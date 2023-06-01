#pragma once
#include <string>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Film {

public:

    std::string title;
    std::string director;
    int year;
    std::string country;
    std::string genre;
    int duration;

    Film() = default;
    ~Film() {

        std::cout << "destructor\n";
    }
    Film(const json &);
    

    Film(std::string title, std::string director, int year, std::string country, std::string genre, int duration);

    

};