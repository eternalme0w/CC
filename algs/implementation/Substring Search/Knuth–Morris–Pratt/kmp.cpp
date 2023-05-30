#include <iostream>
#include <vector>

using namespace std;

vector<int> masspi(const string &a) {

    vector<int> p{0};   
    int i = 1, j = 0;

    while (i < a.length()) {

        if (a[i] == a[j]) {

            p.push_back(j + 1);
            i++;
            j++;

        } else {

            if (j == 0) { 

                p.push_back(0);
                i++;
            }

            else {

                j = p[j - 1];
            }
        }
    }

    return p;
}

int kmp_search(const string &a, const string &t) {

    int i = 0, j = 0, n, m;

    vector<int> p = masspi(t);
    n = a.length();
    m = t.length();


    while (i < n) {

        if (a[i++] == t[j++]) {
            
            if (j == m) break;
            
        } else {

            if (j > 0) 
                j = p[j - 1];
            else 
                i++;
        }

    }

    if (i == n) {

        cout << "Substring not found.";
        return -1;

    } else {
        
        cout << "Substring found at " << i - j;
        return i - j;
    }

    


}

int main() {

    kmp_search("qwelilila in s", "lilila");
    

    return 0;
}