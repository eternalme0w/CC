#include <iostream>


using namespace std;


struct UserId {

    int id = 0;

    explicit UserId(int id) : id(id) {}

    explicit operator int() {

        return id;
    }

};

UserId operator ""_uid(unsigned long long x) {

    return UserId(x);
}

int main() {

    UserId a(5);

    UserId u = 6_uid;

    return 0;
}