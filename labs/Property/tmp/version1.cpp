#include <iostream>
#include <conio.h>
#include "Property.h"
#include "Appartment.h"
#include "Car.h"
#include "CountryHouse.h"
#include "Owner.h"
#include <iomanip>

using namespace std;

void displayOwners(const std::vector<Owner>& owners) {
    cout << "=== OWNERS ===" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "No. | Full Name         | INN           | Properties | Tax" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (size_t i = 0; i < owners.size(); ++i) {
        cout << setw(3) << i << " | ";
        cout << setw(17) << owners[i].getFullName() << " | ";
        cout << setw(13) << owners[i].getInn() << " | ";
        cout << setw(10) << owners[i].getAmountOfProperty() << " | ";
        cout << "$" << setw(7) << fixed << setprecision(2) << owners[i].calculateTotalPropertyTax() << endl;
    }

    cout << "--------------------------------------------------------" << endl;
}

void displayOwnerProperties(const Owner& owner) {
    cout << "=== OWNER PROPERTIES ===" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "No. | Property          | Worth    | Income Tax | Tax" << endl;
    cout << "----------------------------------------------" << endl;

    for (size_t i = 0; i < owner.getAmountOfProperty(); ++i) {
        const Property* property = owner.properties[i];
        cout << setw(3) << i << " | ";
        if (const Appartment* appartment = dynamic_cast<const Appartment*>(property)) {
            cout << setw(17) << "Apartment" << " | ";
            cout << "$" << setw(8) << fixed << setprecision(2) << appartment->get_worth() << " | ";
            cout << "$" << setw(10) << fixed << setprecision(2) << appartment->income_tax_calculation() << " | ";
            cout << "$" << setw(7) << fixed << setprecision(2) << appartment->tax_calculation() << endl;
        }
        else if (const Car* car = dynamic_cast<const Car*>(property)) {
            cout << setw(17) << "Car" << " | ";
            cout << "$" << setw(8) << fixed << setprecision(2) << car->get_worth() << " | ";
            cout << "$" << setw(10) << fixed << setprecision(2) << car->income_tax_calculation() << " | ";
            cout << "$" << setw(7) << fixed << setprecision(2) << car->tax_calculation() << endl;
        }
        else if (const CountryHouse* countryHouse = dynamic_cast<const CountryHouse*>(property)) {
            cout << setw(17) << "Country House" << " | ";
            cout << "$" << setw(8) << fixed << setprecision(2) << countryHouse->get_worth() << " | ";
            cout << "$" << setw(10) << fixed << setprecision(2) << countryHouse->income_tax_calculation() << " | ";
            cout << "$" << setw(7) << fixed << setprecision(2) << countryHouse->tax_calculation() << endl;
        }
    }

    cout << "----------------------------------------------" << endl;
}

void addPropertyToOwnerMenu(Owner& owner) {
    int propertyType;
    double worth;
    cout << "=== ADD PROPERTY ===" << endl;
    cout << "Enter the type of property (1 - Apartment, 2 - Car, 3 - Country House): ";
    cin >> propertyType;
    cout << "Enter the worth of the property: ";
    cin >> worth;

    if (propertyType == 1) {
        double square;
        cout << "Enter the square of the apartment: ";
        cin >> square;
        owner.addProperty(new Appartment(worth, square));
        cout << "Apartment added successfully." << endl;
    }
    else if (propertyType == 2) {
        double horsepower;
        cout << "Enter the horsepower of the car: ";
        cin >> horsepower;
        owner.addProperty(new Car(worth, horsepower));
        cout << "Car added successfully." << endl;
    }
    else if (propertyType == 3) {
        double distanceFromCity;
        cout << "Enter the distance from the city for the country house: ";
        cin >> distanceFromCity;
        owner.addProperty(new CountryHouse(worth, distanceFromCity));
        cout << "Country house added successfully." << endl;
    }
    else {
        cout << "Invalid property type." << endl;
    }
}

void removePropertyFromOwnerMenu(Owner& owner) {
    int propertyIndex;
    displayOwnerProperties(owner);
    cout << "Enter the number of the property to remove: ";
    cin >> propertyIndex;

    if (propertyIndex >= 0 && propertyIndex < owner.getAmountOfProperty()) {
        const Property* property = owner.properties[propertyIndex];
        owner.removeProperty(property);
        delete property;
        cout << "Property removed successfully." << endl;
    }
    else {
        cout << "Invalid property number." << endl;
    }
}

void ownerMenu(std::vector<Owner>& owners) {
    int ownerIndex;
    char choice;
    displayOwners(owners);
    cout << "Enter the number of the owner: ";
    cin >> ownerIndex;

    if (ownerIndex >= 0 && ownerIndex < owners.size()) {
        Owner& owner = owners[ownerIndex];
        while (true) {
            system("cls");
            displayOwnerProperties(owner);
            cout << "=== OWNER MENU ===" << endl;
            cout << "1. Add property" << endl;
            cout << "2. Remove property" << endl;
            cout << "0. Go back to main menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            if (choice == '1') {
                addPropertyToOwnerMenu(owner);
            }
            else if (choice == '2') {
                removePropertyFromOwnerMenu(owner);
            }
            else if (choice == '0') {
                break;
            }
            else {
                cout << "Invalid choice." << endl;
            }

            cout << endl;
        }
    }
    else {
        cout << "Invalid owner number." << endl;
    }
}

void addOwner(std::vector<Owner>& owners) {
    string fullName, inn;
    cout << "=== ADD OWNER ===" << endl;
    cout << "Enter the full name of the owner: ";
    cin.ignore(); // Ignore any previous newline character
    getline(cin, fullName);
    cout << "Enter the INN of the owner: ";
    cin >> inn;

    owners.push_back(Owner(fullName, inn));
    cout << "Owner added successfully." << endl;
}

void removeOwner(std::vector<Owner>& owners) {
    int ownerIndex;
    displayOwners(owners);
    cout << "Enter the number of the owner to remove: ";
    cin >> ownerIndex;

    if (ownerIndex >= 0 && ownerIndex < owners.size()) {
        owners.erase(owners.begin() + ownerIndex);
        cout << "Owner removed successfully." << endl;
    }
    else {
        cout << "Invalid owner number." << endl;
    }
}



int main()
{
    std::vector<Owner> owners;
    char choice;

    

    // Создаем собственников и добавляем им собственность
    Owner owner1("John Doe", "123456789012");
    owner1.addProperty(new Appartment(100000, 80));
    owner1.addProperty(new Car(50000, 200));
    owner1.addProperty(new CountryHouse(200000, 50));

    Owner owner2("Jane Smith", "987654321098");
    owner2.addProperty(new Appartment(150000, 100));
    owner2.addProperty(new Car(60000, 250));
    owner2.addProperty(new CountryHouse(300000, 70));

    Owner owner3("Mike Johnson", "456789012345");
    owner3.addProperty(new Appartment(120000, 90));
    owner3.addProperty(new Car(55000, 220));
    owner3.addProperty(new CountryHouse(250000, 60));

    owners.push_back(owner1);
    owners.push_back(owner2);
    owners.push_back(owner3);



    while (true) {

        system("cls");

        displayOwners(owners);
        cout << "=== MAIN MENU ===" << endl;
        cout << "1. Select owner" << endl;
        cout << "2. Add owner" << endl;
        cout << "3. Remove owner" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '1') {
            system("cls");
            ownerMenu(owners);
        }
        else if (choice == '2') {
            system("cls");
            addOwner(owners);
        }
        else if (choice == '3') {
            system("cls");
            removeOwner(owners);
        }
        else if (choice == '0') {
            break;
        }
        else {
            cout << "Invalid choice." << endl;
        }

        cout << endl;
    }
    


    
    return 0;
}

