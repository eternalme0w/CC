#include <iostream>
#include "conio.h"
#include "Field.h"

using namespace std;


int main() {

	Field f;
	char choice;
	
	do {

		f.out();
		
		choice = _getch();

		if (choice == 'w') f.ShiftUp();
		if (choice == 's') f.ShiftDown();
		if (choice == 'd') f.ShiftRight();
		if (choice == 'a') f.ShiftLeft();

		system("cls");
		
	} while (choice != 'e');



	return 0;
}