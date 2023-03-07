#include <iostream>
#include <algorithm>

using namespace std;

void g(int, char) {

	cout << 5;
}

bool cmp(int a, int b) {

	return a > b;
}

int main() {

	int a[5] = {1, 3, 4, 2, 7};

	void (*pg)(int, char) = &g;

	//pg(1, 'a');

	sort(a, a + 5, cmp);

	for (int i = 0; i < 5; ++i) cout << a[i] << " ";

	return 0;
}