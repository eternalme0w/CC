#include <iostream>

using namespace std;

struct Granny {

    int g;

    Granny(int x) {

        g = x;

    };
};

struct Father: public Granny {

    int f;

    Father(int x): Granny(x) {

    }
};

struct Mother: public Granny {

    int m;

    Mother(int x): Granny(x) {

    }
};

struct Son: public Father, public Mother {

    Son(): Father(1), Mother(2) {


    }
};


int main() {

    Son s;

    cout << s.Mother::g << "\n";
    cout << s.Father::g << "\n";


    return 0;
}