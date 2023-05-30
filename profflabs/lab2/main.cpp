#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Film.h"


using namespace std;

std::vector<Film> parseCSV(const std::string& filename) {

    std::vector<Film> films;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return films;
    }

    std::string line;
    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        
        std::stringstream ss(line);
        std::string cell;
        Film film;

        std::getline(ss, film.title, ',');
        std::getline(ss, film.director, ',');
        std::getline(ss, cell, ',');
        film.year = std::stoi(cell);
        std::getline(ss, film.country, ',');
        std::getline(ss, film.genre, ',');
        std::getline(ss, cell, ',');
        film.duration = std::stoi(cell);

        films.push_back(film);
    }

    file.close();

    return films;
}

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


int main() {

    vector<Film> films = parseCSV("dataset.csv");
    displayFilms(films);
    

    

    return 0;

}