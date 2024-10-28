#pragma once

#include "systemc"

#include <map>
#include <mutex>
#include <string>

/**
 * Represents morse alphabet related helpers.
 */
class Morse {
public:
    /**
     * Retrieves raw conversion data, having initialized it, if needed.
     */
    std::map<int, std::string>* get_data();

private:
    /**
     * Represents raw conversion data map initialization flag.
     */
    std::once_flag data_flag;

    /**
     * Represents pre-defined raw conversion data.
     */
    std::map<int, std::string>* data;
};