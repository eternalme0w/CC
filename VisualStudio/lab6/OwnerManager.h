#pragma once
#include <vector>
#include <iostream>
#include "Owner.h"
#include "Property.h"
#include "Appartment.h"
#include "Car.h"
#include "CountryHouse.h"
#include <iomanip>

using namespace std;

class OwnerManager {

	vector<Owner*> owners;

public:

	OwnerManager(const vector<Owner*>& owners);
	OwnerManager() = default;

	~OwnerManager();

	void addOwner(Owner* owner);

	void removeOwner(Owner* owner);

	void displayOwners() const;
	void displayOwnerProperties(const Owner* owner) const;

	Owner* selectOwner(int ownerIndex) const;

	void menuToSelectOwner(int);
	void menuToChangeOwnerProperty(Owner* selected);
	
	void addPropertyToOwner(Owner*);
	void deleteOwnerProperty(Owner*);

	void addNewOwner();

	int menuToSelectPropertyType();

	double menuToEnrtyParams(const string&);




	
};

