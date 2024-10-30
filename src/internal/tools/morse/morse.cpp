#include "morse.hpp"

std::once_flag Morse::data_flag;

std::map<int, std::vector<int>>* Morse::data = new std::map<int, std::vector<int>>();

std::map<int, std::vector<int>>* Morse::get_data() {
    std::call_once(Morse::data_flag, []{
        Morse::data->emplace(65, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(66, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(67, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(68, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(69, std::vector<int>{DOT_TIME_UNIT});
        Morse::data->emplace(70, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(71, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(72, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(73, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(74, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(75, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(76, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(77, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(78, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(79, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(80, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(81, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(82, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(83, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});
        Morse::data->emplace(84, std::vector<int>{DASH_TIME_UNIT});
        Morse::data->emplace(85, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(86, std::vector<int>{DOT_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(87, std::vector<int>{DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(88, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(89, std::vector<int>{DASH_TIME_UNIT, DOT_TIME_UNIT, DASH_TIME_UNIT, DASH_TIME_UNIT});
        Morse::data->emplace(90, std::vector<int>{DASH_TIME_UNIT, DASH_TIME_UNIT, DOT_TIME_UNIT, DOT_TIME_UNIT});

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