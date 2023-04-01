#include <iostream>
#include <vector>

size_t linearSearchWithBarrier(std::vector<int> mass, int x) {

    size_t i = 0;
    mass.push_back(x);

    while(mass[i] != x) {
        i++;
    }

    return i == mass.size() - 1 ? -1 : i;

}

int main() {

    return 0;
}