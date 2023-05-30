#include <iostream>
#include <cstring>

using namespace std;

class String {

private:

	char* str = nullptr;
	mutable size_t sz = 0; // mutable - anticonst; поле можно будет менять даже в const методе

public:

	String() = default;

	String(const String& s): String(s.sz, '\0') {

		memcpy(str, s.str, sz);
	}

	String(size_t sz, char c = '\0') {

		this->sz = sz;
		str = new char[sz];

		memset(str, c, sz);

		//for (int i = 0; i < sz; ++i) str[i] = c;
	}

	~String() {

		delete[] str;
	}

	size_t get_sz() {

		return sz;
	}

	const char& operator[](size_t index) const {

		return str[index];
	}

	char& operator[](size_t index) {

		return str[index];
	}

	

};


int main() {

	String s(10, 'a');

	String ss = s;

	s.get_sz();




	return 0;
}