#pragma once
#include <string>

class Film {

    

public:

    std::string title;
    std::string director;
    int year;
    std::string country;
    std::string genre;
    int duration;

    Film() = default;
    

    Film(std::string title, std::string director, int year, std::string country, std::string genre, int duration);

    
    std::string getTitle() const;
    std::string getDirector() const;
    int getYear() const;
    std::string getCountry() const;
    std::string getGenre() const;
    int getDuration() const;

};