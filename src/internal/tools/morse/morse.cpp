#include "morse.hpp"

std::once_flag Morse::data_flag;

std::map<int, std::vector<int>>* Morse::data = new std::map<int, std::vector<int>>();

std::map<int, std::vector<int>>* Morse::get_data() {
    std::call_once(Morse::data_flag, []{
        Morse::data->emplace(97, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(98, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(99, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(100, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(101, std::vector<int>{DOT_TIME_UNIT});
        Morse::data->emplace(102, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(103, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(104, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(105, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(106, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(107, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(108, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(109, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(110, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(111, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(112, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(113, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(114, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(115, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(116, std::vector<int>{DASH_TIME_UNIT});
        Morse::data->emplace(117, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(118, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(119, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(120, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(121, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(122, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});

        Morse::data->emplace(48, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(49, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(50, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(51, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(52, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(53, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(54, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(55, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(56, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(57, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
    });

    return data;
}

bool Morse::is_allowed_symbol(int symbol) {
    return (symbol >= NUMBER_MIN_ASCII_RANGE && symbol <= NUMBER_MAX_ASCII_RANGE) ||
        (symbol >= LETTER_MIN_ASCII_RANGE && symbol <= LETTER_MAX_ASCII_RANGE);
}

bool Morse::is_empty_symbol(int symbol) {
    return symbol == EMPTY_ASCII_SYMBOL;
}