#include "morse.hpp"

std::map<int, std::string>* Morse::get_data() {
    std::call_once(this->data_flag, [this]{
        this->data->emplace(1, "itworks");
    });

    return data;
}