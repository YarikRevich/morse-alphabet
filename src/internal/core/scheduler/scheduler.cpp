#include "scheduler.hpp"

Scheduler::Scheduler(sc_module_name name, Pipeline* pipeline) : pipeline{pipeline} {
    SC_THREAD(process);
}

void Scheduler::process() {
    int data;

    while (true) {
        switch (State::get_current()) {
            case AWAIT_INPUT_STATE:
                start_button.read();

                State::set_current(RECORD_INPUT_STATE);

                Logger::invoke_info("IT WORKS");

                break;
            case RECORD_INPUT_STATE:
                data = input.read();

                State::set_current(CONVERT_INPUT_STATE);

                break;  
            case CONVERT_INPUT_STATE:
                

                pipeline->get_data()->write(data);

                State::set_current(AWAIT_INPUT_STATE);

                break;
        }
    }
}

// TODO: add event, which will interrupt action.