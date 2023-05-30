#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void out(const vector<int> &a) {

    cout << "\n\n";
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << "\n\n";
}

void porblem_1(vector<int> &a, int m) {

    vector<int> proto;
    proto.resize(a.size() + 1);

    for(int i = 0; i < a.size(); ++proto[a[i++]]);

    a.clear();

    for(int i = 0; i < proto.size(); i++) {

        for (int j = 0; j < proto[i]; j++) a.push_back(i);
    }

}


int main() {

    srand(time(NULL));

    int m = 10;

    vector<int> a;

    for (size_t i = 0; i < 10; ++i) 
        a.push_back(rand() % m + 1);

    out(a);

    porblem_1(a, m);

    out(a);

    


    return 0;
}