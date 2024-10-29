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

        if (!pipeline->is_empty()) {
            Logger::invoke_info("Conversion has been started");

            while (!pipeline->is_empty()) {
                int data = pipeline->get_data()->read();

                Logger::invoke_info("LIGHTING LED");    
            }

            Logger::invoke_info("Conversion request has been finished");

            watcher->get_conversion_guard()->post();
        } else {
            Logger::invoke_info("Pipeline batch does not have any elements");
        }
    }
}