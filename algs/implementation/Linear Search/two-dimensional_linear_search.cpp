#include <iostream>
#include <vector>

using namespace std;

vector<int> two_dimensional_linear_search(vector<vector<int>> A, int x) {

    vector<int> ans;

    A.back().push_back(x);

    int i = 0, j = 0;

    while(A[i][j] != x) {

        //cout << A[i][j] << "\n";

        if(j == A[i].size() - 1) {

            i++;
            j = 0;

        } else   

            j++;
    }


   ans = (i == A.size()- 1 && j == A[i].size() - 1) ? vector<int>{-1,-1} : vector<int>{i, j};

   return ans;
}

int main() {

    vector<vector<int>> A = {{3,2,3}, {4, 6}, {5, 7}};

    vector<int> b = two_dimensional_linear_search(A, 7);

    //cout << b.size();

    for (int x : b) cout << x << " ";


    return 0;
}