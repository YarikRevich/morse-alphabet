#include "pipeline.hpp"

Pipeline::Pipeline(size_t size) : sc_fifo<int>(size) {
}

bool Pipeline::is_empty() {
    return num_available() == 0;
}

void Pipeline::clear() {
    while (!is_empty()) {
        read();
    }
}