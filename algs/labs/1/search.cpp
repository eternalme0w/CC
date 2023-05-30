#include <iostream>
#include <vector>

using namespace std;

int lin_search(const vector<int> &mass, int x) {

    int n = mass.size();

    for (int i = 0; i < n; ++i) {

        if (mass[i] == x) return i;
    }

    return -1;

}


int main() {




    return 0;
}