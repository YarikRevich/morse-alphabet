#include "executor.hpp"

Executor::Executor(
    sc_module_name name, 
    Pipeline* pipeline, 
    Watcher* watcher) : pipeline{pipeline}, watcher{watcher} {
    SC_THREAD(process);
}

void Executor::process() {
    while (true) {
        wait(*watcher->get_conversion_trigger());

        s.wait()

        if (!pipeline->is_empty()) {
            while (!pipeline->is_empty()) {
                int data = pipeline->get_data()->read();

                Logger::invoke_info("LIGHTING LED");    
            }

            s.post()
        } else {
            Logger::invoke_info("Pipeline batch does not have any elements");
        }
    }
}