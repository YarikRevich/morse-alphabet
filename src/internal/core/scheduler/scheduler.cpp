#include "scheduler.hpp"

Scheduler::Scheduler(
    sc_module_name name, 
    Pipeline *pipeline,
    Watcher* watcher) : pipeline{pipeline}, watcher{watcher}
{
    SC_THREAD(process);
}

void Scheduler::process()
{
    while (true)
    {
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
    if (start_button.read() == HIGH_SIGNAL) {
        State::set_current(RECORD_INPUT_STATE);

        Logger::invoke_info("State has been changed to 'RECORD_INPUT_STATE'");
    }
}

void Scheduler::handle_record_input_state()
{
    if (stop_button.read() == HIGH_SIGNAL) {
        pipeline->clear();

        State::set_current(AWAIT_INPUT_STATE);

        Logger::invoke_info("State has been changed to 'AWAIT_INPUT_STATE' and all the records have been removed");

        return;
    }

    if (convert_button.read() == HIGH_SIGNAL) {
        State::set_current(CONVERT_INPUT_STATE);

        Logger::invoke_info("State has been changed to 'CONVERT_INPUT_STATE'");

        return;
    }

    int symbol = input.read();

    if (Morse::is_allowed_symbol(symbol)) {
        Logger::invoke_warning("Provided symbol has been added to the pipeline batch");

        for (int delay : Morse::get_data()->at(symbol)) {
            pipeline->get_data()->write(delay);    
        }

        State::set_current(CONVERT_INPUT_STATE);
    }
}

void Scheduler::handle_convert_input_state()
{   
    if (stop_button.read() == HIGH_SIGNAL) {
        pipeline->clear();

        State::set_current(AWAIT_INPUT_STATE);

        Logger::invoke_info("State has been changed to 'AWAIT_INPUT_STATE' and all the records have been removed");

        return;
    }

    if (watcher->get_conversion_guard()->trywait() != -1) {
        watcher->get_conversion_trigger()->notify();
    }
}

// TODO: add event, which will interrupt action.