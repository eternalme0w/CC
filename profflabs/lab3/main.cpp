#include <iostream>
#include <fstream>
#include <vector>
#include "pugixml.hpp"
#include "../lab2/Film.h"

using namespace std;

void displayFilms(const std::vector<Film>& films) {

    cout << "===List OF FILMS===:\n\n";

    for (const auto& film : films) {
        std::cout << "Title: " << film.title << std::endl;
        std::cout << "Director: " << film.director << std::endl;
        std::cout << "Year: " << film.year << std::endl;
        std::cout << "Country: " << film.country << std::endl;
        std::cout << "Genre: " << film.genre << std::endl;
        std::cout << "Duration: " << film.duration << " minutes" << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
}

vector<Film> parseJSON(const std::string& filename) {

    vector<Film> films;
    json obj;
    fstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return films;
    }

    file >> obj;
    file.close();

    for (auto x : obj) {

        Film tmp(x);
        films.push_back(tmp);
    }

    return films;
}

int main() {

    vector<Film> films = parseJSON("data.json");

    displayFilms(films);
    

    

    




    return 0;
}