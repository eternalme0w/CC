#include "Fifteen.h"
#include "conio.h"

using namespace std;

int main() {

    Fifteen game(4);
    char ch = 'p';

    while(ch != 'e') {

        cout << "count steps: " << game.getCount() << "\n\n";
        cout << "if you wanna exit game press 'e'"  << "\n\n";
        cout << "good luck have fun)))'"  << "\n\n";

        if(game.isGameOver()) break; 
        game.draw();
        ch = _getch();
        game.onKeyPressed(ch);
        system("cls");
    }

    



    return 0;
}

/* int x = rand() % 5 + 2;

for (size_t i = 0; i < 1; ++i)
{

    game_field.shiftUp();
    game_field.shiftLeft();
} */