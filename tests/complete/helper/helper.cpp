#include "helper.hpp"

Helper::Helper(sc_module_name name, sc_clock *clk)
{
    SC_THREAD(process);

    sensitive << *clk;
}

void Helper::process()
{
    perform_first_test_case();

    perform_second_test_case();

    perform_third_test_case();
}

void Helper::perform_first_test_case() {
    start_button->write(HIGH_SIGNAL);

    wait();

    start_button->write(LOW_SIGNAL);
    input->write(VALID_INPUT_SYMBOL);

    wait();

    sc_assert(output->read() == LOW_SIGNAL);

    convert_button->write(HIGH_SIGNAL);

    wait();

    convert_button->write(LOW_SIGNAL);
    input->write(EMPTY_ASCII_SYMBOL);

    wait(DOT_TIME_UNIT * 2, SC_MS);

    sc_assert(output->read() == HIGH_SIGNAL);

    wait(DASH_TIME_UNIT * 2, SC_MS);

    stop_button->write(HIGH_SIGNAL);

    wait();

    stop_button->write(LOW_SIGNAL);
}

void Helper::perform_second_test_case() {

}

void Helper::perform_third_test_case() {

}