#pragma once

#include <set>

class Heading{

public:

    std::set<Employee *> subordinates;

    virtual double getProfitFromManagement() = 0;

};
