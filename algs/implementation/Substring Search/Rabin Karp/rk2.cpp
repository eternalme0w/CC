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

int rk_search(const string &s, const string &x) {

    int p = 3, M = 1e9 + 7;
    int n = s.length(), m = x.length();
    int i, j, t;
    string tmp = s.substr(0, m);
    int hs = Hash(x.c_str());
    int h = Hash(tmp.c_str());

    int Ti, Tim, hp;

    for (i = 0; i < n - m; i++) {        

        if (hs == h) {

            t = i;
            j = 0;

            while(s[t] == x[j]) {
                
                t++;
                j++;
            }

            if (j == m) return i;
        }

        hp = h*p;
        Ti = s[i] * pow(p, m);
        Tim = s[i+m];

        h = hp - Ti + Tim;

    }

    if (hs == h) {

        t = i;
        j = 0;

        while(s[t] == x[j] && s[t] != 0) {

            t++;
            j++;
        }

        if (j == m) return i;
    }

    return -1;

}

int main() {

    string s("zxc");
    string x("zxc");

    cout << rk_search(s, x);

    return 0;
}