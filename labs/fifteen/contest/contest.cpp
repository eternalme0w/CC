#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

class Field
{

    int size;
    std::vector<int> field;
    int zeroIndex;

    Field(const Field &) = delete;
    Field &operator=(Field) = delete;

public:
    int num_cells;
    std::vector<int> good_field;

    Field(const int &size = 4);

    ~Field() = default;

    int getSize() const;
    std::vector<int> getField() const;
    int getZeroIndex() const;

    void generateStartField(int const &size = 4);

    void swap(int, int);

    void shiftRight();
    void shiftLeft();
    void shiftUp();
    void shiftDown();

    void out();
};

class Fifteen
{

    Field game_field;
    size_t size;
    int count;

    Fifteen(const Fifteen &) = delete;
    Fifteen operator=(Fifteen) = delete;

public:
    Fifteen(size_t size);
    ~Fifteen() = default;

    int getCount() const;
    void run();
    void draw();
    bool isGameOver() const;
    void onKeyPressed(int const &btnCone);
};

Field::Field(const int &size)
{

    generateStartField(size);
}

void Field::generateStartField(const int &size)
{

    field.clear();

    this->size = size;
    num_cells = size * size;

    for (int i = 1; i <= num_cells; ++i)
        field.push_back(i);

    zeroIndex = num_cells - 1;
    field[zeroIndex] = 0;

    good_field = getField();
}

int Field::getSize() const
{

    return size;
}

std::vector<int> Field::getField() const
{
    return field;
}

int Field::getZeroIndex() const
{

    return zeroIndex;
}

void Field::swap(int i1, int i2)
{

    int tmp = field[i1];
    field[i1] = field[i2];
    field[i2] = tmp;
}

void Field::shiftRight()
{

    if ((zeroIndex + 1) % size)
    {

        swap(zeroIndex, zeroIndex + 1);
        zeroIndex++;
    }
}

void Field::shiftLeft()
{

    if (zeroIndex % size)
    {

        swap(zeroIndex, zeroIndex - 1);
        zeroIndex--;
    }
}

void Field::shiftUp()
{

    if ((zeroIndex - size) >= 0)
    {

        swap(zeroIndex, zeroIndex - size);
        zeroIndex -= size;
    }
}

void Field::shiftDown()
{

    if ((zeroIndex + size) < num_cells)
    {

        swap(zeroIndex, zeroIndex + size);
        zeroIndex += size;
    }
}

void Field::out()
{

    printf("\n\n\n\n\n\n\n\n");

    printf("                                 ");

    for (int i = 1; i <= num_cells; ++i)
    {

        if (i % size != 0)
            printf("  %-4d", field[i - 1]);

        else
        {

            printf("  %-4d\n\n", field[i - 1]);
            printf("                                 ");
        }
    }
}




Fifteen::Fifteen(size_t size)
{
    this->size = size;
    run();
}

void Fifteen::run()
{
    count = 0;
    srand(time(NULL));
    game_field.generateStartField(size);

    int x = rand() % 5 + 2;

    for (size_t i = 0; i < 1; ++i)
    {

        game_field.shiftUp();
        game_field.shiftLeft();
    }
}

bool Fifteen::isGameOver() const
{
    std::vector<int> field = game_field.getField();
    return field == game_field.good_field;
}

int Fifteen::getCount() const
{
    return count;
}

void Fifteen::draw()
{

    std::vector<int> field = game_field.getField();
    int size = game_field.getSize();


    for (int i = 1; i <= game_field.num_cells; ++i)
    {

        if (i % size != 0)
            std::cout << field[i - 1] << " ";
        else
            std::cout << field[i - 1] << "\n";
    }
}

void Fifteen::onKeyPressed(int const &btnCone)
{

    switch (btnCone)
    {
    case 72:
        game_field.shiftUp();
        count++;
        break;
    case 80:
        game_field.shiftDown();
        count++;
        break;
    case 75:
        game_field.shiftLeft();
        count++;
        break;
    case 77:
        game_field.shiftRight();
        count++;
        break;
    }
}
