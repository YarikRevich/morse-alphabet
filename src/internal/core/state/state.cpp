#include "state.hpp"

int State::get_current() {
    return current;
}

void State::set_current(int value) {
    this->current = value;
}