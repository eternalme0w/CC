#include <iostream>
#include <vector>


using namespace std;


	


int main() {


	vector<int> v = {1, 2, 3, 4, 5};

	vector<int> vv = v; // создается копия;

	vv[0] = 0; // v[0] == 0 ??

	vector<int> &rv = v;

	rv[0] = 0;

	cout << v[0];



	

	return 0;
}