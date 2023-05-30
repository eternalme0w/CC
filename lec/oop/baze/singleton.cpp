#include <iostream>

using namespace std;

class C {

    static C* obj;
    C() {};

public:

    static C& getObj() {

        if (obj) return *obj;
        obj = new C();
        return *obj;
    }

    static void destroy() {

        delete obj;
    }

};


int main() {



    return 0;
}