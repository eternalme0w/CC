#include "Film.h"


Film::Film(std::string title, std::string director, int year, std::string country, std::string genre, int duration) {
    this->title = title;
    this->director = director;
    this->year = year;
    this->country = country;
    this->genre = genre;
    this->duration = duration;
}

// Геттеры для доступа к полям класса
std::string Film::getTitle() const {
    return title;
}

std::string Film::getDirector() const {
    return director;
}

int Film::getYear() const {
    return year;
}

std::string Film::getCountry() const {
    return country;
}

std::string Film::getGenre() const {
    return genre;
}

int Film::getDuration() const {
    return duration;
}