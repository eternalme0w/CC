#include "OwnerManager.h"

OwnerManager::OwnerManager(const vector<Owner*>& owners): owners(owners){}

OwnerManager::~OwnerManager() {

    for (const auto& owner : owners) {
        delete owner;
    }
}

void OwnerManager::addOwner(Owner* owner) {

    owners.push_back(owner);
}

void OwnerManager::removeOwner(Owner* owner) {

    auto it = find(owners.begin(), owners.end(), owner);

    if (it != owners.end()) {
        owners.erase(it);
        delete owner;
    }
}

void OwnerManager::displayOwners() const {

    int i = 1;

    cout << "=== OWNERS LIST ===" << endl;
    printf("|%3s|%15s|%12s|%10s|%10s|\n", "No.", "Name", "INN", "Properties", "Total Tax");

    for (auto owner : owners) {
        printf("|%3d", i);
        owner->out();
        i++;
    }
}

void OwnerManager::displayOwnerProperties(const Owner* owner) const {

    owner->printOwnerProperty();

}

Owner* OwnerManager::selectOwner(int ownerIndex) const {

    if (ownerIndex >= 1 && ownerIndex <= owners.size()) {
        return owners[ownerIndex - 1];
    }

    return nullptr;
}

void OwnerManager::menuToSelectOwner(int ch) {

    int selectedOwnerIndex;
    Owner* selectedOwner;
    
    do {

        selectedOwner = nullptr;
        
        system("cls");
        displayOwners();
        cout << "\nSelect an owner (enter owner index, or 0 to back to main menu): ";

        if (!(cin >> selectedOwnerIndex)) {
            cin.clear(); // Очищаем флаги ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue; 
        }

        if (selectedOwnerIndex == 0) break;

        selectedOwner = selectOwner(selectedOwnerIndex);

        if (selectedOwner != nullptr) {

            if (ch == 1)menuToChangeOwnerProperty(selectedOwner);
            if (ch == 2)removeOwner(selectedOwner);
            selectedOwner = nullptr;
        }

    } while (selectedOwner == nullptr);
}

void OwnerManager::menuToChangeOwnerProperty(Owner* selected) {

    int menuChoice = -1;

    do {

        system("cls");
        displayOwnerProperties(selected);

        cout << "=== PROPERTIES MENU ===" << endl;
        cout << "1. Add new property" << endl;
        cout << "2. Remove property" << endl;
        cout << "\nEnter your choice (1-2, or 0 to back): ";

        if (!(cin >> menuChoice)) {
            cin.clear(); // Очищаем флаги ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            menuChoice = -1;
            continue;
        }

        if (menuChoice == 0) break;

        if (menuChoice == 1) addPropertyToOwner(selected);
        if (menuChoice == 2) deleteOwnerProperty(selected);

    } while (menuChoice != 0);
}

int OwnerManager::menuToSelectPropertyType() {

    int propertyType = -1;

    do {

        system("cls");

        cout << "Select property type:" << endl;
        cout << "1. Apartment" << endl;
        cout << "2. Car" << endl;
        cout << "3. Country House" << endl;
        cout << "Enter property type: ";
        
        if (!(cin >> propertyType)) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            propertyType = -1;
            continue;
        }

    } while (propertyType < 1 || propertyType > 3);

    return propertyType;
}

double OwnerManager::menuToEnrtyParams(const string &ParametrName) {

    double parametr = 0;

    do {

        system("cls");

        cout << "Enter " << ParametrName << ": ";

        if (!(cin >> parametr)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            parametr = 0;
            continue;
        }

    } while (parametr <= 0);

    return parametr;

}

void OwnerManager::addPropertyToOwner(Owner* owner) {

    
    int propertyType = menuToSelectPropertyType();

    double worth = menuToEnrtyParams("worth");
    
    Property* property = nullptr;

    switch (propertyType) {
    case 1: {

        double square = menuToEnrtyParams("square");;
        property = new Appartment(worth, square);
        break;
    }
    case 2: {

        double horsepower = menuToEnrtyParams("horsepower");
        property = new Car(worth, horsepower);
        break;
    }
    case 3: {

        double distanceFromCity = menuToEnrtyParams("distance from the city");
        property = new CountryHouse(worth, distanceFromCity);
        break;
    }
    default:
        cout << "Invalid property type." << endl;
        return;
    }

    owner->addProperty(property);
}

void OwnerManager::deleteOwnerProperty(Owner* owner) {

    int number = 0;
    vector<Property*> properties = owner->getProperties();

    do {

        system("cls");

        displayOwnerProperties(owner);
        cout << "\nEnter number of property to delete: ";


        if (!(cin >> number)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            number = 0;
            continue;
        }

    } while (number <= 0 || number > owner->getAmountOfProperty());



    if (number != 0) {

        owner->removeProperty(properties[number - 1]);
    }
}

void OwnerManager::addNewOwner() {
    string fullName;
    string inn;

    system("cls");

    cout << "Enter the full name of the owner: ";
    cin.ignore();
    getline(cin, fullName);

    cout << "Enter the INN (Individual Taxpayer Identification Number) of the owner: ";
    cin >> inn;

    Owner* owner = new Owner(fullName, inn);
    owners.push_back(owner);

    cout << "Owner added successfully." << endl;
}

