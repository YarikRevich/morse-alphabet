#pragma once

#include "systemc"

#include "../../logger/logger.hpp"
#include "../pipeline/pipeline.hpp"
#include "../watcher/watcher.hpp"

#include <vector>

using namespace sc_core;

/**
 * Represents executor module, which is reponsible for pipeline entities processing.
 */
class Executor : public sc_module
{
public:
    /**
     * Performs executor module initialization.
     *
     * @param pipeline - given instance of pipeline batch.
     * @param watcher - given instance of event watcher.
     * @param clk - given external system clock.
     */
    SC_CTOR(Executor, Pipeline *pipeline, Watcher *watcher, sc_clock *clk);

    // TODO: load from pipeline, execute with awaits and unlock mutex after that.

    /**
     * Represents output signal for executor results.
     */
    sc_signal<int> output;

    /**
     * Represents export interface for output signal for executor results.
     */
    sc_export<sc_signal<int>> output_export;

private:
    /**
     * Performs pipeline batch scheduled operations processing.
     */
    void process();

    /**
     * Represents instance of pipeline batch with scheduled operations.
     */
    Pipeline *pipeline;

    /**
     * Represents of instance of watcher, which helps to manage executor.
     */
    Watcher *watcher;
};