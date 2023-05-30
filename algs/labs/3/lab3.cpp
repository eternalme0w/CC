#include <iostream>
#include <vector>
#include <time.h>

#include "Sorts.h"


using namespace std;


int main() {

    vector<int> a;
    int m = 12;

    srand(time(NULL));

    for (size_t i = 0; i < 16; ++i) 
        a.push_back(rand() % m + 1);

    
    Sorts lab(a);


    lab.out();

    lab.problem_2();

    lab.out();



    


    return 0;
}