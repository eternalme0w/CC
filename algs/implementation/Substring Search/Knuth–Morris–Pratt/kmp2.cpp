#include <iostream>
#include <vector>

using namespace std;

vector<int> pref(const string &s) {

    int m = s.length(), k;
    vector<int> p = {-1};

    for (int i = 1; i <= m; ++i) {

        k = p[i-1];

        while(k != -1 && s[k] != s[i-1]) {

            k = p[k];
        }

        p.push_back(k + 1);

    }

    return p;

}

int kmp_search2(const string &s, const string &x) {

    int i = 0, j = 0, l = 0;
    int n = s.length(), m = x.length();

    vector<int> p = pref(x);
    p.erase(p.begin());

    while(i < n) {

        l++;

        if (s[i] == x[j]) {

            i++;
            j++;

            if (j == m) {

                cout << l;
                return i - m;
            }

        } else {

            if (j > 0) j = p[j-1];
            else i++;
        }
    }
    

    return -1;
}

int kmp_search(const string &s, const string &x) {

    string t = x + "#" + s;
    vector<int> p = pref(t);
    int m = x.length(), l = 0;

    for (int i = m; i < p.size(); i++) {

        //l++;

        if (p[i] == m) {

            cout << l;
            return i - 2*m - 1;
        }
    }

    //cout << l;
    

    return -1;
}


int main() {

    string s("zxazxc");
    string x("zxc");

    kmp_search(s, x);
    kmp_search2(s, x);


    //vector<int> p = pref(s);
    //for (auto x : p) cout << x << " ";




    return 0;
}