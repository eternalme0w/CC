#include <iostream>
#include <vector>

size_t linearSearch(std::vector<int> mass, int x) {

    for (size_t i = 0; i < mass.size(); ++i) {

        if (mass[i] == x) 
            return i;
    }

    return -1;

}


int main() {

    std::vector<int> a = {1, 2, 3, 4};

    size_t ans = linearSearch(a, 2);

    std::cout << ans;



    return 0;
}