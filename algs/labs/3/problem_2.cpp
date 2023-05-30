#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void out(const vector<int> &a) {

    cout << "\n\n";
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << "\n\n";
}

void problem_2(vector<int> &a) {

    vector<int> tmp;

    for (int x : a) {

        if (x % 2 == 0) tmp.push_back(x);
    }

    for (int x : a) {

        if (x % 2 != 0) tmp.push_back(x);
    }

    a = tmp;
}


int main() {

    srand(time(NULL));

    int m = 10;

    vector<int> a;

    for (size_t i = 0; i < 10; ++i) 
        a.push_back(rand() % m + 1);

    out(a);

    problem_2(a);

    out(a);

    


    return 0;
}