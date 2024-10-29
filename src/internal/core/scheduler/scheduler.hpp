#pragma once

#include "systemc"

#include "../../tools/morse/morse.hpp"
#include "../../logger/logger.hpp"
#include "../pipeline/pipeline.hpp"
#include "../watcher/watcher.hpp"
#include "../state/state.hpp"

using namespace sc_core;

/**
 * Represents scheduler module, which is reponsible for operations to be scheduled according 
 * to the selected state.
 */
class Scheduler : public sc_module {
public:
    /**
     * Performs scheduler module initialization.
     * 
     * @param pipeline - given instance of pipeline batch.
     * @param watcher - given instance of event watcher.
     */
    SC_CTOR(Scheduler, Pipeline* pipeline, Watcher* watcher);

    /**
     * Performs state handlers processing.
     */
    void process();

    /**
     * Handles await input state processing.
     */
    void handle_await_input_state();

    /**
     * Handles record input state processing.
     */
    void handle_record_input_state();

    /**
     * Handles convert input state processing.
     */
    void handle_convert_input_state();

    /**
     * Represents start button signal used to start recording process.
     */
    sc_signal<int> start_button;

    /**
     * Represents convert button signal used to start conversion process.
     */
    sc_signal<int> convert_button;

    /**
     * Represents stop button signal used to stop both recording and conversion processes.
     */
    sc_signal<int> stop_button;

    /**
     * Represents keyboard input signal used to record input data.
     */
    sc_signal<int> input;

private:
    /**
     * Represents instance of pipeline batch with scheduled operations.
     */
    Pipeline* pipeline;

    /**
     * Represents of instance of watcher, which helps to manage executor.
     */
    Watcher* watcher;
};