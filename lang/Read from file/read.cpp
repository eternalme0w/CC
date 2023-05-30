#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {

    string path = "file.txt";
    ifstream file;

    string s, x, emptiness;

    file.exceptions(ifstream::badbit | ifstream::failbit);

    try {

        file.open(path);

        while(!file.eof()) {

            getline(file, s);
            getline(file, x);
            getline(file, emptiness);
            cout << s << " / " << x << "\n";
        }


        file.close();

    } catch(const ifstream::failure &e) {

        cout << "exp.";
        
    }
    


    return 0;
}