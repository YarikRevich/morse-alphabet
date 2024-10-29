#pragma once

#include "systemc"

#include "../pipeline/pipeline.hpp"
#include "../converter/converter.hpp"

using namespace sc_core;

/**
 * Represents executor module, which is reponsible for pipeline entities processing.
 */
class Executor : public sc_module {
public:
    /**
     * Performs executor module initialization.
     * 
     * @param pipeline - given instance of pipeline batch.
     */
    SC_CTOR(Executor, Pipeline* pipeline);

    // TODO: load from pipeline, execute with awaits and unlock mutex after that. 

    /**
     * Performs pipeline batch scheduled operations processing.
     */
    void process();

    /**
     * Watches process execution and can interrupt pipeline batch entity execution. 
     */
    void watch();

    /**
     * Represents output signal for executor results.
     */
    sc_signal<int> output;

private:
    /**
     * Represents instance of pipeline batch with scheduled operations.
     */
    Pipeline* pipeline;
};