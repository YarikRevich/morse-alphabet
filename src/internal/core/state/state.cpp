#include "state.hpp"

int State::current = AWAIT_INPUT_STATE;

int State::get_current() {
    return current;
}

void State::set_current(int value) {
    State::current = value;
}