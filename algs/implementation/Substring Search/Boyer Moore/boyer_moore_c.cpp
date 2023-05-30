#include <iostream>


#define N_CHARS 256

using namespace std;

int max(int a, int b) {

    return (a > b) ? a : b;
}

void badCharHeuristic(const char *str, int size, int badchar[N_CHARS]) {

    size_t i;

    for (i = 0; i < N_CHARS; i++) 

        badchar[i] = -1;

    for (i = 0; i < size; i++)

        badchar[(int) str[i]] = i;

}



int main() {

    string str = "serega_pirate";
    int badchar[N_CHARS];
    int size = str.size();

    badCharHeuristic(str.c_str(), size, badchar);

    for (auto i = 0; i < N_CHARS; i++) 

        cout << (char) i << ": " << badchar[i] << "\n";


   
    return 0;
}