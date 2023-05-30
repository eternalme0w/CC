#include <iostream>
#include <vector>

using namespace std;

int bin_search(int x, vector<int> A) {

    int left = -1;
    int right = A.size();
    int middle;

    while(right - left > 1) {

        middle = (left + right) / 2;

        if (A[middle] < x) 
        
            left = middle;
        else 
            right = middle;
    }

    left++;

    return A[left] == x ? left : -1;

}

vector<int> two_dimensional_bin_search(int x, vector<vector<int>> A) {  

    int left = -1;
    int right = A.size();
    int middle, index;
    vector<int> ans;

    while(right - left > 1) {

        middle = (left + right) / 2;

        if (A[middle][0] <= x)

            left = middle;
        else
            right = middle;
    }

    index = bin_search(x, A[left]);

    if (index != -1) {

        ans.push_back(left);
        ans.push_back(bin_search(x, A[left]));

    } else {

        ans.push_back(-1);
        ans.push_back(-1);
    }

    return ans;

}

int main() {

    vector<vector<int>> A = {{1,1,3}, {4, 4, 6}, {8, 9}};
    vector<int> ans = two_dimensional_bin_search(8, A);

    //cout << bin_search(6, A[1]);

    cout << ans[0] << " " << ans[1] << "\n";


    return 0;
}