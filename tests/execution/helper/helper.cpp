#include "helper.hpp"

Helper::Helper(sc_module_name name, sc_clock *clk)
{
    SC_THREAD(process);

    sensitive << *clk;
}

void Helper::process()
{
    int counter = 1;

    std::string symbols;

    while (true)
    {
        std::cout << "Enter the command('start', 'stop', 'convert', 'exit') or provide a symbol: ";
        std::cin >> symbols;

        if (symbols == "exit")
        {
            sc_stop();

            break;
        }
        else if (symbols == "start")
        {
            start_button->write(HIGH_SIGNAL);

            wait();

            start_button->write(LOW_SIGNAL);
        }
        else if (symbols == "stop")
        {
            stop_button->write(HIGH_SIGNAL);

            wait();

            stop_button->write(LOW_SIGNAL);
        }
        else if (symbols == "convert")
        {
            convert_button->write(HIGH_SIGNAL);

            wait();

            convert_button->write(LOW_SIGNAL);

            wait(DASH_TIME_UNIT * 5 * counter, SC_MS);

            counter = 1;
        }
        else
        {
            if (!symbols.empty() && symbols.size() > 1)
            {
                std::cout << "It's allowed to provide only one symbol at a time" << std::endl;

                continue;
            }

            input->write(static_cast<int>(symbols.at(0)));

            wait();

            input->write(EMPTY_ASCII_SYMBOL);

            wait();

            counter++;
        }

        wait(CYCLE_TIME, SC_MS);
    }
}