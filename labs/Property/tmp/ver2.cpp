#include <iostream>
#include <conio.h>
#include "Property.h"
#include "Appartment.h"
#include "Car.h"
#include "CountryHouse.h"
#include "Owner.h"
#include "OwnerManager.h"
#include <iomanip>

using namespace std;






int main()
{
    std::vector<Owner> owners;
    OwnerManager ownerManager;
    
    
    

    
    Owner* owner1 = new Owner("John Doe", "123456789012");
    owner1->addProperty(new Appartment(100000, 80));
    owner1->addProperty(new Car(50000, 200));
    owner1->addProperty(new CountryHouse(200000, 50));
    owner1->addProperty(new Car(200, 50));
    ownerManager.addOwner(owner1);

    Owner* owner2 = new Owner("Jane Smith", "987654321098");
    owner2->addProperty(new Appartment(150000, 100));
    owner2->addProperty(new Car(60000, 250));
    owner2->addProperty(new CountryHouse(300000, 70));
    owner2->addProperty(new CountryHouse(302, 75));
    ownerManager.addOwner(owner2);

    Owner* owner3 = new Owner("Mike Johnson", "456789012345");
    owner3->addProperty(new Appartment(120000, 90));
    owner3->addProperty(new Car(55000, 220));
    owner3->addProperty(new CountryHouse(250000, 60));
    owner3->addProperty(new Appartment(1000, 20));
    ownerManager.addOwner(owner3);
    

    ownerManager.displayOwners();
    


    
    return 0;
}


printf("%s %s %s %s %s", "No.", "Name", "INN", "Properties", "Total Tax");