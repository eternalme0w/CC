#include <iostream>
#include <cstring>
#include <algorithm>


class String {

private:

	size_t sz = 0;
	char* str = nullptr;

public:

	String() = default;

	String(const String& s): String(s.sz, '\0') {

		memcpy(str, s.str, sz);
	}

	String(size_t sz, char c = '\0'): sz(sz), str(new char[sz]) {

		memset(str, c, sz);

		//for (int i = 0; i < sz; ++i) str[i] = c;
	}

	~String() {

		delete[] str;
	}

	String& operator=(String s) {

		swap(s);
		return *this;
	}

	void swap(String& s) {

		std::swap(str, s.str);
		std::swap(sz, s.sz);
	}

	void out() {

		std::cout << sz;
	}

	

};


int main() {

	String s(10, 'a');

	String g(2, 'k');

	String ss = s;

	s = g;

	s.out();




	return 0;
}