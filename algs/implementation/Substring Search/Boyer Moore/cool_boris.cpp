#include <iostream>
#include <map>

using namespace std;

map<char,int> offsets(const string &x) {

    map<char, int> d;
    int i, m = x.length();

    for (i = m - 2; i >= 0; i--) 

        if (d.find(x[i]) == d.end())

            d[x[i]] = m - i - 1;

    if (d.find(x[m-1]) == d.end())
        d[x[m-1]] = m;

    d['*'] = m;

    return d;

} 

int bm_search(const string &s, const string &x) {

    int i, j, k, off;
    int n = s.size(), m = x.size();
    bool f = false;

    map<char,int> d = offsets(x);

    i = m - 1;

    while(i < n) {

        k = 0;

        for (j = m - 1; j >= 0; j--) {

            if (s[i - k] != x[j]) {

                if (j == m - 1)
                    off = (d.find(s[i]) == d.end()) ? d['*'] : d[s[i]];
                else
                    off = d[x[j]];

                i += off;
                break;
            }

            k++;
        }

        if (j == -1) {

            return i-k + 1;
        }
    }

    return -1;

}

int main() {
    

    string s("vizxckazxc");
    string x("zxc");

    cout << bm_search(s, x);







    return 0;
}