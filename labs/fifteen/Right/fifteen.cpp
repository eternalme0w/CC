#include "Fifteen.h"
#include "Field.h"
#include <iostream>
#include <vector>

using namespace std;

Fifteen::Fifteen(size_t size)
{
    game_field.generateStartField(size);
}

int Fifteen::getCount() const
{
    return cnt;
}

void Fifteen::draw() const
{
    for (size_t i = 0; i < game_field.getField().size(); i++)
    {
        cout << game_field.getField()[i];
        if ((i + 1) % game_field.getSize() == 0 && i < game_field.getField().size())
            cout << '\n';
        else
            cout << '\t';
    }
}

bool Fifteen::isGameOver() const
{
    int fieldsize = game_field.getSize() * game_field.getSize();
    bool gameover = (game_field.getField()[fieldsize - 1] == 0) ? true : false;
    for (size_t i = 0; i < (fieldsize - 1) && gameover; i++)
    {
        if (game_field.getField()[i] != (i + 1))
            gameover = false;
    }

    return gameover;
}

void Fifteen::onKeyPressed1(int const& btnCone)
{
    switch (btnCone)
    {
    case 72:
        game_field.shiftUp1();
        break;
    case 80:
        game_field.shiftDown1();
        break;
    case 75:
        game_field.shiftLeft1();
        break;
    case 77:
        game_field.shiftRight1();
        break;
    }
}
void Fifteen::onKeyPressed(int const& btnCone)
{
    switch (btnCone)
    {
    case 72:
        game_field.shiftUp();
        break;
    case 80:
        game_field.shiftDown();
        break;
    case 75:
        game_field.shiftLeft();
        break;
    case 77:
        game_field.shiftRight();
        break;
    }
}