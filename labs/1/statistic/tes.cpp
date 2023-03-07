#include <vector>
#include <iostream>
#include <algorithm>

int main() {

    std::vector<int> v{3, 2, 0};

    int a = *std::max_element(v.begin(), v.end());

    for (int x : v) {

        std::cout << x << " "; 
    }

    return 0;
}