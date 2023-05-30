#include "iostream"
#include "fstream"
#include <sstream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

vector<int> lin_search(const string &s, const string &x);

int Hash(const char* str);
vector<int> rk_search(const string &s, const string &x);

vector<int> pref(const string &s);
vector<int> kmp_search(const string &s, const string &x);

map<char,int> offsets(const string &x);
vector<int> bm_search(const string &s, const string &x);


int main() {

    ifstream file;
    string s, x, emptiness;
    int index;

    file.exceptions(ifstream::badbit | ifstream::failbit);

    try {

        file.open("file.txt");

        while(!file.eof()) {

            getline(file, s);
            getline(file, x);
            getline(file, emptiness);

            cout << s << "/" << x << "\n";

            cout << "Linear search: at " << lin_search(s, x)[0] << ", num of comps: " << lin_search(s, x)[1] << "\n";

            cout << "Rabin Karp search: at " << rk_search(s, x)[0] << ", num of comps: " << rk_search(s, x)[1] << "\n";

            cout << "KMP search: at " << kmp_search(s, x)[0] << ", num of comps: " << kmp_search(s, x)[1] << "\n";

            cout << "Boyer Moore search: at " << bm_search(s, x)[0] << ", num of comps: " << bm_search(s, x)[1] << "\n";

            cout << "\n\n";
            

        }


    } catch(const ifstream::failure &e) {

        cout << "File opening error.";
    }



    return 0;
}

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

vector<int> bm_search(const string &s, const string &x) {

    vector<int> ans;

    int i, j, k, off, l = 0;
    int n = s.size(), m = x.size();

    map<char,int> d = offsets(x);

    

    i = m - 1;

    while(i < n) {

        k = 0;

        for (j = m - 1; j >= 0; j--) {

            l++;

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

            ans.push_back(i-k + 1);
            ans.push_back(l);

            return ans;
        }
    }

    ans.push_back(-1);
    ans.push_back(l);

    return ans;

}

vector<int> kmp_search(const string &s, const string &x) {

    vector<int> ans;

    string t = x + "#" + s;
    vector<int> p = pref(t);
    int m = x.length(), l = 0;

    for (int i = m + 1; i < p.size(); i++) {

        l++;

        if (p[i] == m) {

            ans.push_back(i - 2*m - 1);
            ans.push_back(l);

            return ans;
        }
    }

    ans.push_back(-1);
    ans.push_back(l);

    return ans;
}


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

vector<int> rk_search(const string &s, const string &x) {

    vector<int> ans;

    int p = 3, M = 1e9 + 7, l = 0;
    int n = s.length(), m = x.length();
    int i, j, t, Ti, Tim, hp;
    string tmp = s.substr(0, m);
    int hs = Hash(x.c_str());
    int h = Hash(tmp.c_str());

    for (i = 0; i < n - m; i++) { 

        l++;       

        if (hs == h) {

            t = i;
            j = 0;

            while(s[t] == x[j]) {
                
                t++;
                j++;
            }

            if (j == m) {

                ans.push_back(i);
                ans.push_back(l);

                return ans;
            }
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

        if (j == m) {

            ans.push_back(i);
            ans.push_back(l);

            return ans;

        }
    }

    ans.push_back(-1);
    ans.push_back(l);

    return ans;

}


int Hash(const char* str) {

    int p = 3, M = 1e9 + 7;
    int hash = 0;
    
    for (; *str != 0; ++str) hash = (hash * p + *str) % M;
    return hash;
}


vector<int> lin_search(const string &s, const string &x) {

    vector<int> ans;

    int i, j, t, l = 0;
    int n = s.length(), m = x.length();

    for (i = 0; i <= n - m; ++i) {

        l++;

        j = 0;
        t = i;

        while(s[t] == x[j] && s[t] != 0) {

            l++;
            t++;
            j++;
        }

        if (j == m) {

            ans.push_back(i);
            ans.push_back(l);

            return ans;

        }
    }

    ans.push_back(-1);
    ans.push_back(l);

    return ans;

}