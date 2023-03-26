#include <iostream>
#include <vector>
#include "Statistic.h"
#include "conio.h"

using namespace std;


int main() {

    string str = "8 23 8 93 21 77 93";

    
    vector<int> v;
    char ch;
    Statistic s(str);

    int ans;

    char ch1;
    int size;
    int value;

    while(ch1 != '1' && ch1 != '2') {

        system("cls");

        cout << "what set of data you wanna use?\n\n1 - static data\n2 - your data set\n\n";

        cout << "enter your choice: ";
        ch1 = _getch();
    }

    system("cls");

    if (ch1 == '1')

        s = Statistic(str);

    else {

        cout << "enter size of data set: ";
        cin >> size;

        for (size_t i = 0; i < size; ++i) {

            cin >> value;
            v.push_back(value);
        }

        s = Statistic(v);
    }

    v.clear();

    int ll = 0;


    while (ch != 'e') {

        system("cls");

        if (ll) {

            cout << "answer: ";
            if (v.size())
            {

                for (int x : v)
                {

                    cout << x << " ";
                }
            }

            else
                cout << ans;

        }

        v.clear();

        s.out();

        cout << "\n\nif you wanna exit press 'e'\n\n";

        cout << "1 - sum\n2 - average\n3 - max sales\n4 - min sales\n5 - months sales below avg\n6 - months sales above avg\n\nEnter your choice: ";

        ch = _getch();

        cout << "\n\n\n"; 

        switch (ch)
        {
        case '1':
            ans = s.sum_sales();
            break;

        case '2':
            ans = s.average_sales();
            break;

        case '3':
            v = s.max_sales();
            break;

        case '4':
            v = s.min_sales();
            break;

        case '5':
            ans = s.months_sales_below_average();
            break;

        case '6':
            ans = s.months_sales_above_average();
            break;

        }

        ll = 1;
        

        

    }


    return 0;
}