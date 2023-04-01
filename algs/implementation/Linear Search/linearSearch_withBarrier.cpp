#include <iostream>
#include <vector>

int linearSearchWithBarrier(std::vector<int> mass, int x) {

    size_t i = 0;
    mass.push_back(x);

    while(mass[i] != x) {
        i++;
    }

    return i == mass.size() - 1 ? -1 : i;

}


int main() {

    std::vector<int> a = {1, 2, 5, 7};

    int ans = linearSearchWithBarrier(a, 7);

    std::cout << ans;

    return 0;
}