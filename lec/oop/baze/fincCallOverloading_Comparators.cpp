#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

//Функтор, Функциональный класс
struct GreatherThanZero {
    
    bool operator()(int x) {

        return x > 0;
    }
    
};


//comparator
struct MyCompare {
    
    bool operator()(int x, int y) {

        return abs(x) < abs(y);
    }
};


bool my_cmp(int x, int y) {

    return abs(x) < abs(y);
}



int main() {

    /* std::vector<int> v = {-1, -2, 4, 0, 3};

    std::cout << *std::find_if(v.begin(), v.end(), GreatherThanZero());

    std::sort(v.begin(), v.end(), MyCompare());
    //std::sort(v.begin(), v.end(), my_cmp);

    for (int x : v) std::cout << x << " "; */

    std::set<int, MyCompare> s;

    s.insert(-1);
    s.insert(0);
    s.insert(-2);

    for (int x : s) std::cout << x << " ";







    return 0;
}