#include "Fifteen.h"

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

    for(size_t i = 0; i < 1; ++i) {

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

    game_field.out();
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