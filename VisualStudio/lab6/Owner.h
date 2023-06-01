#pragma once
#include<string>
#include<vector>
#include "Property.h"

class Owner {

    std::string fullname;
    std::string inn;
    int amountOfProperty;
    


public:

    std::vector<Property*> properties;

    Owner(const std::string& fullname, const std::string& inn);
    
    std::vector<Property*> getProperties() const;

    void addProperty(Property *p);
    void removeProperty(const Property* p);

    double calculateTotalPropertyTax() const;

    void printOwnerProperty() const;

    int getAmountOfProperty() const;
    std::string getFullName() const;
    std::string getInn() const;

    void out();

};

