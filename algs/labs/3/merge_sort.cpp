#include <iostream>
#include <vector>

using namespace std;

void out(const vector<int> &a) {
    
    cout << "\n";
    for (int x : a) cout << x << " ";
    cout << "\n";
}

void merge(const vector<int> &a, const vector<int> &b, vector<int> &c) {    

    int i = 0, j = 0, n = 0;

    while (i < a.size() && j < b.size()) {

        if (a[i] <= b[j]) c[n++] = a[i++];
        else c[n++] = b[j++];
    }

    while (i < a.size()) 
        c[n++] = a[i++];

    while (j < b.size()) 
        c[n++] = b[j++];

}

void merge_sort(vector<int> &a) {
    
    int n = a.size();
    if (n <= 1) return;
    int middle = n / 2;

    vector<int> left(a.begin(), a.begin() + middle);
    vector<int> right(a.begin() + middle, a.end());

    merge_sort(left);
    merge_sort(right);

    merge(left, right, a);

}

int main() {

    vector<int> a = {4, 2, 5, 1, 3, 7, 6, 8};

    out(a);

    merge_sort(a);

    out(a);

    




    return 0;
}