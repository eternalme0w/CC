#include <iostream>
#include <vector>

using namespace std;

void out(const vector<int> &a, int s, int e) {

    cout << "\n\n";
    for (int i = s; i <= e; i++) cout << a[i] << " ";
    cout << "\n\n";
}

void quick_sort(vector<int> &a, int first, int last) {

    int i = first, j = last;
    int x = a[(first + last) / 2];

    while (i <= j) {

        while(a[i] < x) i++;
        while(a[j] > x) j--;

        if (i <= j) swap(a[i++], a[j--]);
    }

    if (first < j) quick_sort(a, first, j);
    if ( i < last) quick_sort(a, i, last);
}

int main() {

    //vector<int> a = {8, 2, 5, 1, 3, 7, 6, 8};
    vector<int> a = {1, 2, 3, 4, 5};

    out(a, 0, a.size() - 1);

    quick_sort(a, 0, a.size() - 1);

    out(a, 0, a.size() - 1);


    return 0;
}