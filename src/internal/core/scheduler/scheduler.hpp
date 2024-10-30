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
     * @param clk - given external system clock.
     */
    SC_CTOR(Scheduler, Pipeline* pipeline, Watcher* watcher, sc_clock* clk);

    /**
     * Represents start button signal used to start recording process.
     */
    sc_signal<int> start_button;

    /**
     * Represents export interface for start button signal used to start recording process.
     */
    sc_export<sc_signal<int>> start_button_export;

    /**
     * Represents stop button signal used to stop both recording and conversion processes.
     */
    sc_signal<int> stop_button;

    /**
     * Represents export interface for stop button signal used to stop both recording and conversion processes.
     */
    sc_export<sc_signal<int>> stop_button_export;

    /**
     * Represents convert button signal used to start conversion process.
     */
    sc_signal<int> convert_button;

    /**
     * Represents export interface for convert button signal used to start conversion process.
     */
    sc_export<sc_signal<int>> convert_button_export;

    /**
     * Represents keyboard input signal used to record input data.
     */
    sc_signal<int> input;

    /**
     * Represents export interface for keyboard input signal used to record input data.
     */
    sc_export<sc_signal<int>> input_export;

private:
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
     * Represents instance of pipeline batch with scheduled operations.
     */
    Pipeline* pipeline;

    /**
     * Represents of instance of watcher, which helps to manage executor.
     */
    Watcher* watcher;
};