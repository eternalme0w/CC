#include "Film.h"


Film::Film(std::string title, std::string director, int year, std::string country, std::string genre, int duration) {
    this->title = title;
    this->director = director;
    this->year = year;
    this->country = country;
    this->genre = genre;
    this->duration = duration;
}

Film::Film(const json &obj) {

    title = obj["title"];
    director = obj["director"];
    year = obj["year"];
    country = obj["country"];
    genre = obj["genre"];
    duration = obj["duration"];
}
