#include <iostream>
#include <map>

#include <conio.h>

using namespace std;



int main() {


    map<char, int> d;

    int i, j, k, off;

    string s("zxcvikazxc");
    string x("vika");

    int n = s.size();
    int m = x.size();

    for (i = m - 2; i >= 0; i--) {

        if (d.find(x[i]) == d.end())

            d[x[i]] = m - i - 1;
    }

    if (d.find(x[m-1]) == d.end()) 
        
        d[x[m-1]] = m;

    d['*'] = m;

    if (n >= m) {

        i = m - 1;

        while(i < n) {
            
            k = 0;

            for (j = m - 1; j >= 0; j--) {

                if (s[i-k] != x[j]) {

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

                cout << "match at " << i-k + 1;
                break;
            }
        }


    } else 

        cout << -1;



    //for (auto pair : d) cout << pair.first << ":" << pair.second << "\n";



    
    

    

    //cout << (d.find('w') == d.end());


    return 0;
}