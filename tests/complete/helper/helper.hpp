#include "systemc"

using namespace sc_core;

/**
 * Represents stimulus helper used for the testbench.
 */
class Helper : public sc_module  {
public:
    /**
     * Performs stimulus helper initialization.
     * 
     * @param clk - given external system clock.
     */
    SC_CTOR(Helper, sc_clock* clk);

    /**
     * Represents start button signal used to start recording process.
     */
    sc_port<sc_signal_out_if<int>> start_button;

    /**
     * Represents convert button signal used to start conversion process.
     */
    sc_port<sc_signal_out_if<int>> stop_button;

    /**
     * Represents stop button signal used to stop both recording and conversion processes.
     */
    sc_port<sc_signal_out_if<int>> convert_button;

    /**
     * Represents keyboard input signal used to record input data.
     */
    sc_port<sc_signal_out_if<int>> input;

    /**
     * Represents executor output signal used to represent conversion results.
     */
    sc_port<sc_signal_in_if<int>> output;

private:
    /**
     * Performs testbench processing.
     */
    void process();

    /**
     * Performs first testcase, which checks correct application flow.
     */
    void perform_first_test_case();
};