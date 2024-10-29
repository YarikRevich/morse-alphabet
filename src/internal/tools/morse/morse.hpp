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
    std::map<int, std::vector<int>>* get_data();

private:
    /**
     * Represents raw conversion data map initialization flag.
     */
    std::once_flag data_flag;

    /**
     * Represents pre-defined raw conversion data.
     */
    std::map<int, std::vector<int>>* data;
};