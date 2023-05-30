#include <iostream>
#include <cmath>

using namespace std;

long long Hash(const char* str) {

    long long p = 31, M = 1e9 + 7;
    long long hash = 0;

    for (; *str != 0; ++str) {

        hash = (hash * p + *str) % M;
    }

    return hash;
}

int rk_search(const string &s, const string &x) {

    string tmp;
    long long p = 31, M = 1e9 + 7;
    long long hs, h;

    int n = s.length(), m = x.length();

    tmp = s.substr(0, m);

    hs = Hash(x.c_str());
    h = Hash(tmp.c_str());

    int t, j;

    for (int i = 0; i <= n - m; ++i) {

        cout << hs << " / " << h << "\n";

        if (h == hs) {

            cout << "hash\n";

            t = i;
            j = 0;

            while(s[t] == x[j] && s[t] != 0) {
                
                t++;
                j++;
            }

            if (j == m) return i;
        }

        h = ( h * p - static_cast<long long>((s[i]*pow(p, m))) + static_cast<int>(s[i + m]) ) % M;
 
    }

    return -1;

}



int main() {

    string s("serega_pirate");
    string x("pirate");

    cout << rk_search(s, x);

    





    return 0;
}