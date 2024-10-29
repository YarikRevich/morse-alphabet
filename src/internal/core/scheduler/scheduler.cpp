#include "scheduler.hpp"

Scheduler::Scheduler(sc_module_name name, Pipeline *pipeline) : pipeline{pipeline}
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
    int d = start_button.read();

    std::cout << d << std::endl;

    State::set_current(RECORD_INPUT_STATE);

    Logger::invoke_info("IT WORKS");
}

void Scheduler::handle_record_input_state()
{
    int data = input.read();

    State::set_current(CONVERT_INPUT_STATE);
}

void Scheduler::handle_convert_input_state()
{
    pipeline->get_data()->write(0);

    State::set_current(AWAIT_INPUT_STATE);
}

// TODO: add event, which will interrupt action.