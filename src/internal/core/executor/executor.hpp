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
     * Performs module initialization.
     */
    SC_CTOR(Executor);

    // TODO: load from pipeline, execute with awaits and unlock mutex after that. 


    /**
     * Performs pipeline batch scheduled operations processing.
     */
    void process();

private:
    /**
     * Represents instance of pipeline batch with scheduled operations.
     */
    Pipeline* pipeline;

    /**
     * Represents output handler, which is expected to be some led
     */
    sc_signal<int> output;
};