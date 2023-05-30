#include <iostream>
#include <cmath>

using namespace std;

int Hash(const char* str) {

    int p = 3, M = 1e9 + 7;
    int hash = 0;

    for (; *str != 0; ++str) {

        hash = (hash * p + *str) % M;
    }

    return hash;
}



int main() {

    string s("sessepirate");
    string x("pirate");

    int n = s.length();
    int m = x.length();

    string tmp = s.substr(0, m);

    int p = 3, M = 1e9 + 7;

    int hs = Hash(x.c_str());
    int h = Hash(tmp.c_str());

    int Ti, Tim, hp, old;

    cout << "Hs: " << hs << "\n\n";
    cout << "H: " << h << "\n\n";
    

    for (int i = 0; i < n - m; ++i) {        

        if (hs == h) {

            cout << " hash ";
        }

        hp = h*p;
        Ti = s[i] * pow(p, m);
        Tim = s[i+m];

        old = h;

        h = hp - Ti + Tim;

        cout << "H = "<<old<<"*"<<p<<" - "<<(int)s[i]<<"*"<<p<<"**"<<m<<" + " << s[i+m] <<(int)s[i+m]<<" = "<< h << "\n\n";

    }

    if (hs == h) {

        cout << " hash ";
    }
    

    





    return 0;
}