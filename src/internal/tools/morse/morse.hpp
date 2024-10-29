#pragma once

#include "systemc"

#include <map>
#include <mutex>
#include <vector>

/**
 * Represents morse alphabet related helpers.
 */
class Morse {
public:
    /**
     * Retrieves raw conversion data, having initialized it, if needed.
     * 
     * @return retrieved raw conversion data.
     */
    static std::map<int, std::vector<int>>* get_data();

    /**
     * Checks if provided ASCII symbol code is allowed to be used.
     * 
     * @param symbol - provided ASCII symbol code.
     * @return result of the check.
     */
    static bool is_allowed_symbol(int symbol);

private:
    /**
     * Represents raw conversion data map initialization flag.
     */
    static std::once_flag data_flag;

    /**
     * Represents pre-defined raw conversion data.
     */
    static std::map<int, std::vector<int>>* data;
};