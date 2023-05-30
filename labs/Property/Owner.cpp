#include "Owner.h"


Owner::Owner(const std::string &fullname, const std::string &inn) {

    this->fullname = fullname;
    this->inn = inn;
}

void Owner::addProperty(const Property &p) {

    properties.push_back(p);
}

void Owner::removeProperty(const Property &p) {

    auto index = std::find(properties.begin(), properties.end(), p);

    if (index != properties.end()) 
        properties.erase(index);
}

std::vector<Property>::iterator Owner::propertyIndex(const Property &p) {

    std::vector<Property>::iterator index = std::find(properties.begin(), properties.end(), p);
    return index;
}

bool Owner::own(const Property &p) {

    return propertyIndex(p) == properties.end() ? false : true;
}
