#include "executor.hpp"

Executor::Executor(
    sc_module_name name,
    Pipeline *pipeline,
    Watcher *watcher,
    sc_clock *clk) : pipeline{pipeline}, watcher{watcher}
{
    SC_THREAD(process);

    sensitive << *watcher->get_conversion_trigger();
    sensitive << *clk;

    output_export(output);
}

void Executor::process()
{
    while (true)
    {
        wait(*watcher->get_conversion_trigger());

        if (!pipeline->is_empty())
        {
            Logger::invoke_info("Conversion has been started");

            while (!pipeline->is_empty())
            {
                int delay = pipeline->get_data()->read();

                Logger::invoke_info(std::string("Sending high output signal for ").append(std::to_string(delay)).append(" milliseconds"));

                output.write(HIGH_SIGNAL);

                wait(delay, SC_MS);

                Logger::invoke_info("Sending low output signal");

                output.write(LOW_SIGNAL);

                Logger::invoke_info("Minor await has been started");

                wait(MINOR_AWAIT, SC_MS);
            }

            Logger::invoke_info("Conversion request has been finished");

            watcher->get_conversion_guard()->post();
        }
        else
        {
            Logger::invoke_info("Pipeline batch does not have any elements");
        }
    }
}