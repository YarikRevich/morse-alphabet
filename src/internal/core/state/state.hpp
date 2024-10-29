#pragma once

/**
 * Represents finite state machine state.
 */
class State {
public:
    /**
     * Retrieves current state value.
     */
    static int get_current();

    /**
     * Sets current state value.
     */
    static void set_current(int value);

private:
    /**
     * Represents current state value.
     */
    static int current;
};