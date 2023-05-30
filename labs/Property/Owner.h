#include<string>
#include<vector>
#include <algorithm>
#include "Property.h"

class Owner {

    std::string fullname;
    std::string inn;
    std::vector<Property> properties;

    std::vector<Property>::iterator propertyIndex(const Property&);

public:

    Owner(const std::string &fullname, const std::string &inn);
    void addProperty(const Property&);
    void removeProperty(const Property&);

    bool own(const Property&);


};

