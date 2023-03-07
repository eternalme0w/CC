#include <iostream>
#include "Radio.h"
#include "conio.h"
#include <vector>

using namespace std;



int main() {

	vector<int> v;


	Radio R1;

	char choice;

	do {

		cout << endl;

		cout << "a - prev station; d - next station" << endl;
		cout << "w - inc volume; s - dec volume" << endl << endl;
		cout << "station: " << R1.getStation() << endl << "volume: " << R1.getVolume() << endl << endl;

		choice = _getch();

		if (choice == 'w') R1.incVolume();
		if (choice == 's') R1.decVolume();
		if (choice == 'a') R1.previousStation();
		if (choice == 'd') R1.nextStation();

		system("cls");

	} while (choice != 'e');

	return 0;

}