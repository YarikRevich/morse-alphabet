#pragma once

#include "systemc"

using namespace sc_core;

/**
 * Represents pipeline batch, which is used to schedule operations.
 */
class Pipeline {
public:
    /**
     * @param size - given pipeline size.
     */
    Pipeline(size_t size);

    /**
     * 
     */
    sc_fifo<int>* get_data();

private:
    /**
     * 
     */
    sc_fifo<int>* pipeline;
};