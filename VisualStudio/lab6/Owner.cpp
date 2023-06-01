#include "Owner.h"

Owner::Owner(const std::string& fullname, const std::string& inn) {
    this->fullname = fullname;
    this->inn = inn;
    amountOfProperty = 0;
}

std::vector<Property*> Owner::getProperties() const {

    return properties;
}


void Owner::addProperty(Property* p) {

    properties.push_back(p);
    amountOfProperty++;

}

void Owner::removeProperty(const Property* property) {

    auto it = std::find(properties.begin(), properties.end(), property);
    if (it != properties.end()) {
        properties.erase(it);
        amountOfProperty--;
    }
}

double Owner::calculateTotalPropertyTax() const {
    double totalTax = 0.0;
    for (const auto& property : properties) {
        totalTax += property->tax_calculation() + property->income_tax_calculation();
    }
    return totalTax;
}

int Owner::getAmountOfProperty() const {

    return amountOfProperty;
}

std::string Owner::getFullName() const {

    return fullname;
}

std::string Owner::getInn() const {

    return inn;
}

void Owner::out() {
    
    //"Name", "INN", "Properties", "Total Tax";
    
    printf("|%15s|%12s|%10d|%10.2f|\n", 
        fullname.c_str(), inn.c_str(), amountOfProperty, calculateTotalPropertyTax());
}

void Owner::printOwnerProperty() const {

    std::cout << fullname << ":\n";
    int num = 1;

    printf("|%3s|  %-10s|   %-8s |    %-9s|  %-11s|     %-7s|\n",
        "No.", "Property", "Params", "Worth", "IncomeTax", "Tax");

    for (const auto& property : properties) {
        std::cout << "| " << num++ << " ";
        property->out();
    }

    std::cout << "\n\n";
}