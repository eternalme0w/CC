#include <iostream>

using namespace std;

struct Granny {

    int g;
};

struct Mother: virtual public Granny {

    int m;
};

struct Father: virtual public Granny {

    int f;
};

struct Son: public Father, public Mother {

    int s;
    
};


int main() {

    Son s;

    Father &f = s;

    f.g;


    return 0;
}