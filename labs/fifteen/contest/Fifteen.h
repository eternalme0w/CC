#pragma once
#include "Field.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>

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