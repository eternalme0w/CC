#include <iostream>
#include <vector>

using namespace std;


int bin_search(int x, vector<int> A) {

    int left = -1;
    int right = A.size();
    int middle;

    while(right - left > 1) {

        middle = (left + right) / 2;

        if (A[middle] < x) 
            left = middle;
        else 
            right = middle;
    }

    return left + 1;

}

int main() {

    vector<int> A = {1, 2, 2, 4, 5, 7, 7, 8, 9};

    cout << bin_search(4, A);


    return 0;
}