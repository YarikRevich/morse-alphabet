#pragma once

#include "systemc"

#include <vector>

using namespace sc_core;

/**
 * Represents pipeline batch, which is used to schedule operations.
 */
class Pipeline : public sc_fifo<int> {
public:
    /**
     * @param size - given pipeline size.
     */
    Pipeline(size_t size);

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
};