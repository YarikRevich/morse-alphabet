#include "morse.hpp"

std::map<int, std::vector<int>>* Morse::get_data() {
    std::call_once(this->data_flag, [this]{
        this->data->emplace(65, std::vector<int>{1000, 3000});
        this->data->emplace(66, std::vector<int>{3000, 1000, 1000, 1000});
        this->data->emplace(67, std::vector<int>{3000, 1000, 3000, 1000});
        this->data->emplace(68, std::vector<int>{3000, 1000, 1000});
        this->data->emplace(69, std::vector<int>{1000});
        this->data->emplace(70, std::vector<int>{1000, 1000, 3000, 1000});
        this->data->emplace(71, std::vector<int>{3000, 3000, 1000});
        this->data->emplace(72, std::vector<int>{1000, 1000, 1000, 1000});
        this->data->emplace(73, std::vector<int>{1000, 1000});
        this->data->emplace(74, std::vector<int>{1000, 3000, 3000, 3000});
        this->data->emplace(75, std::vector<int>{3000, 1000, 3000});
        this->data->emplace(76, std::vector<int>{1000, 3000, 1000, 1000});
        this->data->emplace(77, std::vector<int>{3000, 3000});
        this->data->emplace(78, std::vector<int>{3000, 1000});
        this->data->emplace(79, std::vector<int>{3000, 3000, 3000});
        this->data->emplace(80, std::vector<int>{1000, 3000, 3000, 1000});
        this->data->emplace(81, std::vector<int>{3000, 3000, 1000, 3000});
        this->data->emplace(82, std::vector<int>{1000, 3000, 1000});
        this->data->emplace(83, std::vector<int>{1000, 1000, 1000});
        this->data->emplace(84, std::vector<int>{3000});
        this->data->emplace(85, std::vector<int>{1000, 1000, 3000});
        this->data->emplace(86, std::vector<int>{1000, 1000, 1000, 3000});
        this->data->emplace(87, std::vector<int>{1000, 3000, 3000});
        this->data->emplace(88, std::vector<int>{3000, 1000, 1000, 3000});
        this->data->emplace(89, std::vector<int>{3000, 1000, 3000, 3000});
        this->data->emplace(90, std::vector<int>{3000, 3000, 1000, 1000});

        this->data->emplace(49, std::vector<int>{1000, 3000, 3000, 3000, 3000});
        this->data->emplace(50, std::vector<int>{1000, 1000, 3000, 3000, 3000});
        this->data->emplace(51, std::vector<int>{1000, 1000, 1000, 3000, 3000});
        this->data->emplace(52, std::vector<int>{1000, 1000, 1000, 1000, 3000});
        this->data->emplace(53, std::vector<int>{1000, 1000, 1000, 1000, 1000});
        this->data->emplace(54, std::vector<int>{3000, 1000, 1000, 1000, 1000});
        this->data->emplace(55, std::vector<int>{3000, 3000, 1000, 1000, 1000});
        this->data->emplace(56, std::vector<int>{3000, 3000, 3000, 1000, 1000});
        this->data->emplace(57, std::vector<int>{3000, 3000, 3000, 3000, 1000});
        this->data->emplace(48, std::vector<int>{3000, 3000, 3000, 3000, 3000});
    });

    return data;
}