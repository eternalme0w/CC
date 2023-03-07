#include "Field.h"
#include <iostream>
#include <algorithm>
#include <random>


Field::Field(const int& size) {

    num_cells = size * size;
    field = new int[num_cells];
    this->size = size;
    generateStartField(size);
}

void Field::generateStartField(const int& size) {

    for (int i = 1; i <= num_cells; ++i) field[i - 1] = i;

    std::random_device device;
    std::mt19937 g(device());

    std::shuffle(field, field + num_cells - 1, g);

    zeroIndex = num_cells - 1;
    field[zeroIndex] = 0;
}

Field::~Field() {

    delete[] field;
}

int Field::getSize() const {

    return size;
}

int* Field::getField() const {

    return field;
}

int Field::getZeroIndex() const {

    return zeroIndex;
}

void Field::swap(int i1, int i2) {

    int tmp = field[i1];
    field[i1] = field[i2];
    field[i2] = tmp;
}

void Field::ShiftRight() {

    if ((zeroIndex + 1) % size) {

        swap(zeroIndex, zeroIndex + 1);
        zeroIndex++;
    }
}

void Field::ShiftLeft()
{

    if (zeroIndex % size) {

        swap(zeroIndex, zeroIndex - 1);
        zeroIndex--;
    }
}

void Field::ShiftUp()
{

    if ((zeroIndex - size) >= 0) {

        swap(zeroIndex, zeroIndex - size);
        zeroIndex -= size;
    }
}

void Field::ShiftDown() {

    if ((zeroIndex + size) < num_cells) {

        swap(zeroIndex, zeroIndex + size);
        zeroIndex += size;
    }
}

void Field::out() {

    printf("\n\n\n\n\n\n\n\n");

    printf("                                 ");

    for (int i = 1; i <= num_cells; ++i) {

        if (i % size != 0) printf("  %-4d", field[i - 1]);

        else {

            printf("  %-4d\n\n", field[i - 1]);
            printf("                                 ");
        }
    }
}



