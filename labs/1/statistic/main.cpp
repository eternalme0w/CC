#include <iostream>
#include <vector>
#include "Statistic.h"
#include "conio.h"

using namespace std;


int main() {

    vector<int> v{34,23,8,93,21,77,34};

    cout << v[-3];

    //Statistic s("34 23 8 93 21 77 34");
    /* Statistic s(v);

    // 34 23 8 93 21 77 34

    cout << s.sum_sales() << endl;
    cout << s.average_sales() << endl;
    for(int x: s.max_sales()) cout << x << " ";
    cout << endl;
    for(int x: s.min_sales()) cout << x << " ";
    cout << endl;
    cout << s.months_sales_above_average() << endl;
    cout << s.months_sales_below_average() << endl; */

    /* char ch;

    cout << "1-sum\n2-average\n3-max sales\n4-min sales\n5-months sales below avg\n6 - months sales above avg\nEnter your choice: ";

    ch = _getch();

    cout << "\n\n\n"; */

    /* switch (ch)
    {
    case '1':
        cout << "sum: " << s.sum_sales();
        break;

    case '2':
        cout << "avg: " << s.average_sales();
        break;

    case '3':
        v = s.max_sales();
        cout << "max sales: ";
        for (int x : v)
            cout << x << " ";
        break;

    case '4':
        v = s.min_sales();
        cout << "min sales: ";
        for (int x : v)
            cout << x << " ";
        break;

    case '5':
        cout << "months_sales_below_average: " << s.months_sales_below_average();
        break;

    case '6':
        cout << "months_sales_below_average: " << s.months_sales_above_average();
        break;

    } */


    return 0;
}