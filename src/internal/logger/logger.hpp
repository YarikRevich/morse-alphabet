#pragma once

#include "systemc"

using namespace sc_core;

/**
 * Represents common logger for the application.
*/
class Logger {
public:
    /**
     * Performs logger initialization.
     */
    static void init();

    /**
     * Invokes message of warning level. 
     */
    static void invoke_warning(std::string message);

    /**
     * Invokes message of info level. 
     */
    static void invoke_info(std::string message);
};