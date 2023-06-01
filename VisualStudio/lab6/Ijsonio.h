#pragma once

#include "deps\include\nlohmann\json.hpp"

using json = nlohmann::json;

class Ijsonio {


public:

	Ijsonio() = default;
	virtual ~Ijsonio() = 0;
	virtual void fromJson(const json &json_file) = 0;
	virtual json toJson() = 0;


	
};

