#include "executor.hpp"

Executor::Executor(
    sc_module_name name, 
    Pipeline* pipeline, 
    Watcher* watcher) : pipeline{pipeline}, watcher{watcher} {
    SC_THREAD(process);

    sensitive << *watcher->get_conversion_trigger();

    output_export(output);
}

void Executor::process() {
    while (true) {
        wait(*watcher->get_conversion_trigger());

        if (!pipeline->is_empty()) {
            Logger::invoke_info("Conversion has been started");

            while (!pipeline->is_empty()) {
                int data = pipeline->get_data()->read();

                output.write(HIGH_SIGNAL);

                wait(data, SC_MS);

                output.write(LOW_SIGNAL);

                wait(MINOR_AWAIT, SC_MS);
            }

            Logger::invoke_info("Conversion request has been finished");

            watcher->get_conversion_guard()->post();
        } else {
            Logger::invoke_info("Pipeline batch does not have any elements");
        }
    }
}