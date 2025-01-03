#include "scheduler.hpp"

Scheduler::Scheduler(
    sc_module_name name,
    Pipeline *pipeline,
    Watcher *watcher,
    sc_clock *clk) : pipeline{pipeline}, watcher{watcher}
{
    SC_THREAD(process);

    start_button_export(start_button);
    stop_button_export(stop_button);
    convert_button_export(convert_button);
    input_export(input);

    sensitive << *clk;
}

void Scheduler::process()
{
    while (true)
    {
        wait();

        switch (State::get_current())
        {
        case AWAIT_INPUT_STATE:
            handle_await_input_state();

            break;
        case RECORD_INPUT_STATE:
            handle_record_input_state();

            break;
        case CONVERT_INPUT_STATE:
            handle_convert_input_state();

            break;
        }
    }
}

void Scheduler::handle_await_input_state()
{
    if (start_button.read() == HIGH_SIGNAL)
    {
        State::set_current(RECORD_INPUT_STATE);

        Logger::invoke_info("State has been changed to 'RECORD_INPUT_STATE'");
    }
}

void Scheduler::handle_record_input_state()
{
    if (stop_button.read() == HIGH_SIGNAL)
    {
        pipeline->clear();

        State::set_current(AWAIT_INPUT_STATE);

        Logger::invoke_info("State has been changed to 'AWAIT_INPUT_STATE' and all the records have been removed");

        return;
    }

    if (convert_button.read() == HIGH_SIGNAL)
    {
        State::set_current(CONVERT_INPUT_STATE);

        Logger::invoke_info("State has been changed to 'CONVERT_INPUT_STATE'");

        return;
    }

    int symbol = input.read();

    if (!Morse::is_empty_symbol(symbol))
    {
        if (Morse::is_allowed_symbol(symbol))
        {
            Logger::invoke_info("Provided symbol has been added to the pipeline batch");

            for (int delay : Morse::get_data()->at(symbol))
            {
                pipeline->write(delay);
            }
        } else {
            Logger::invoke_warning("Provided symbol cannot be converted");
        }
    }
}

void Scheduler::handle_convert_input_state()
{
    if (stop_button.read() == HIGH_SIGNAL)
    {
        pipeline->clear();

        State::set_current(AWAIT_INPUT_STATE);

        Logger::invoke_info("State has been changed to 'AWAIT_INPUT_STATE' and all the records have been removed");

        return;
    }

    if (!pipeline->is_empty())
    {
        if (watcher->get_conversion_guard()->trywait())
        {
            Logger::invoke_info("Conversion request has been sent");

            watcher->get_conversion_trigger()->notify();

            watcher->get_conversion_guard()->wait();
        }
    }
    else
    {
        State::set_current(RECORD_INPUT_STATE);

        Logger::invoke_info("State has been changed to 'RECORD_INPUT_STATE'");
    }
}