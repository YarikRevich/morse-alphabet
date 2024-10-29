#pragma once

#include "systemc"

using namespace sc_core;

/**
 * Represents a holder of events, which act as watchers for the modules.
 */
class Watcher {
public:
    /**
     * Performs watcher initialization.
     */
    Watcher();

    /**
     * Retrieves conversion trigger event.
     * 
     * @return retrieved conversion trigger event.
     */
    sc_event* get_conversion_trigger();

    /**
     * Retrieves conversion guard.
     * 
     * @return retrieved conversion guard.
     */
    sc_semaphore* get_conversion_guard();

private:
    /**
     * Represents a trigger, which notified executor to start conversion process. 
     */
    sc_event* conversion_trigger;

    /**
     * Represents a gurad, used to protect conversion trigger to be executed.
     */
    sc_semaphore* conversion_guard;
};