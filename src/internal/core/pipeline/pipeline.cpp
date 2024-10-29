#include "pipeline.hpp"

Pipeline::Pipeline(size_t size) {
    this->data = new sc_fifo<int>(size);
}

sc_fifo<int>* Pipeline::get_data() {
    return data;
}