#include <iostream>
#include <vector>

using namespace std;

int linearSearch(const vector<int> &mass, int x) {

    int n = mass.size();

    for (int i = 0; i < n; ++i) {

        if (mass[i] == x) return i;
    }

    return -1;
}

int linearSearchWithBarrier(vector<int> mass, int x) {


    int i = 0;
    mass.push_back(x);

    while(mass[i] != x) {
        
        i++;
    }

    return i == mass.size() - 1 ? -1 : i;

}


int main() {




    return 0;
}