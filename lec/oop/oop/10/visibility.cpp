#include <iostream>

// Visibility and accessibility

using namespace std;

struct Mother {

    int a = 0;
    void f(int x) {

        cout << "Mother\n";
    }
};

struct Son : Mother {

    int a = 1;
    using Mother::f;
    void f(string s) {

        cout << "Son\n";
    }

};




int main() {

    Son s;

    s.f(2.2);
    s.Mother::f(2);

    return 0;
}