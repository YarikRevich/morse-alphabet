#include "pipeline.hpp"

Pipeline::Pipeline(size_t size) {
    this->data = new sc_fifo<int>(size);
}

sc_fifo<int>* Pipeline::get_data() {
    return data;
}

bool Pipeline::is_empty() {
    return data->num_available() == 0;
}

void Pipeline::clear() {
    while (!is_empty()) {
        data->read();
    }
}