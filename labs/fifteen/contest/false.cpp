#include <iostream>
#include "conio.h"
#include "Field.h"

using namespace std;

int main()
{

    Field f(6);
    char choice;

    do
    {

        f.out();

        choice = _getch();

        if (choice == 'w')
            f.shiftUp();
        if (choice == 's')
            f.shiftDown();
        if (choice == 'd')
            f.shiftRight();
        if (choice == 'a')
            f.shiftLeft();

        system("cls");

    } while (choice != 'e');

    return 0;
}