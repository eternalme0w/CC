#include <iostream>

using namespace std;

int lin_search(const string& s, const string& x) {

    int j, t, i;
    int n = s.length(), m = x.length();

    for (i = 0; i <= n - m; i++) {

        j = 0;
        t = i;

        while(s[t] == x[j] && s[t] != 0) {
            
            // cout << j << " ";

            t++;
            j++;
        }

        if (j == m) return i;
    

    }
 

    return -1;

}

int main() {

    string str("wqwezxcsfs");
    string x  ("qwezxcsfs");

    cout << lin_search(str, x);
    


    return 0;
}