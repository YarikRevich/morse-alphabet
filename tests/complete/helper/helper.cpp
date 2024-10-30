#include "helper.hpp"

Helper::Helper(sc_module_name name, sc_clock *clk)
{
    SC_THREAD(process);

    sensitive << *clk;
}

void Helper::process()
{
    perform_first_test_case();
}

void Helper::perform_first_test_case() {
    start_button->write(HIGH_SIGNAL);

    wait();

    input->write(VALID_INPUT_SYMBOL);

    wait();

    convert_button->write(HIGH_SIGNAL);

    wait();

    // convert_button->write(0);

    wait(10, SC_NS);

    int data = output->read();

    std::cout << data << std::endl;

    wait();

    // start_button->write(0);
    // stop_button->write(1);

    // wait();
}