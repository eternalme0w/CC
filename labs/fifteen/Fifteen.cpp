#include "Fifteen.h"

Fifteen::Fifteen(size_t size) {

    count = 0;
    game_field.generateStartField(size);
}

int Fifteen::getCount() const {
    return count;
}

bool Fifteen::isGameOver() const {

    bool isGameOver = true;

    int* field = game_field.getField();
    int size = game_field.getSize();
    int zeroIndex = game_field.getZeroIndex();

    for (int i = 0; i < size*size - 1; i++) {

        if (field[i] + 1 != field[i+1]) isGameOver = false; 
    }

    if(field[zeroIndex] != 0) isGameOver = false;

    return isGameOver;    
}


void Fifteen::run() {

    count = 0;
    game_field.generateStartField();
}


void Fifteen::draw() {

    int* field = game_field.getField();
    int size = game_field.getSize();

    for (int i = 1; i <= game_field.num_cells; ++i) {

        if (i % size != 0) printf("  %-4d", field[i - 1]);
        else printf("  %-4d\n\n", field[i - 1]);
    }
}