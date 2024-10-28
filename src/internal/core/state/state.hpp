#pragma once

/**
 * Represents finite state machine state.
 */
class State {
public:
    /**
     * Retrieves current state value.
     */
    int get_current();

    /**
     * Sets current state value.
     */
    void set_current(int value);

private:
    /**
     * Represents current state value.
     */
    int current;
};