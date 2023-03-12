#pragma once
#include <iostream>
#include <vector>
#include "Field.h"
using namespace std;


class Fifteen
{
private:
    Field game_field;
    int cnt = 0;

public:
    Fifteen(size_t size);
    int getCount() const;
    void draw() const;
    bool isGameOver() const;
    void onKeyPressed(int const& btnCone);
    void onKeyPressed1(int const& btnCone);
};