#pragma once

#include "systemc"

#include "../../logger/logger.hpp"
#include "../pipeline/pipeline.hpp"
#include "../state/state.hpp"

using namespace sc_core;

/**
 * Represents scheduler module, which is reponsible for operations to be scheduled according 
 * to the selected state.
 */
class Scheduler : public sc_module {
public:
    /**
     * Performs module initialization.
     * 
     * @param pipeline - given instance of pipeline batch.
     */
    SC_CTOR(Scheduler, Pipeline* pipeline);

    /**
     * Performs state handlers processing.
     */
    void process();

private:
    /**
     * Represents instance of pipeline batch with scheduled operations.
     */
    Pipeline* pipeline;

    /**
     * Represents input signal used to start recording process.
     */
    sc_signal<int> start_button;

    /**
     * Represents input signal used to stop recording process.
     */
    sc_signal<int> stop_button;

    /**
     * Represents input signal used to transfer input data to be converted.
     */
    sc_signal<int> input;
};