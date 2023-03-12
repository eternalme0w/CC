#include <iostream>
#include <vector>
#include <conio.h>
#include "Field.h"
#include "Fifteen.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    int n;
    cout << "Введите размер поля: " << endl;
    cin >> n;
    if (n <= 0) cout << "Поле с данным размером не существует." << endl;
    if (n > 0)
    {
        Fifteen fifteen(n);

        vector<int> keys = { 72, 80, 75, 77 };

        for (int i = 0; i < 30; i++)
        {
            fifteen.onKeyPressed1(keys[(rand() % 4)]);
        }

        int k;
        cout << "Поле размером " << endl << n << 'x' << n << ':' << endl;
        cout << "Кол-во ходов: " << endl << '0' << endl;
        fifteen.draw();

        for (size_t i = 0;; ++i)
        {
            if (fifteen.isGameOver())
            {
                cout << "You are winner!" << "\n";
            }
            k = _getch();
            system("cls");
            cout << "Поле размером " << endl << n << 'x' << n << ':' << endl;
            cout << "Кол-во ходов: " << endl;
            fifteen.onKeyPressed(k);
            cout << endl;
            fifteen.draw();
            cout << "\n";
        }
    }
}