#pragma once

#include "systemc"

#include <vector>

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
     * Retrieves pipeline batch internal instance.
     */
    sc_fifo<int>* get_data();

    /**
     * Checks if pipeline batch empty.
     * 
     * @return result of the check.
     */
    bool is_empty();

    /**
     * Removes all the data from the pipeline batch.
     */
    void clear();

private:
    /**
     * Represents internal instance of pipeline batch.
     */
    sc_fifo<int>* data;
};