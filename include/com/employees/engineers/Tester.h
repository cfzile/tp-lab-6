#pragma once

#include "Engineer.h"

class Tester : public Engineer {

public:

    Tester (FULLNAME fullName, unsigned int id, double salaryRate,
            unsigned int workTime = 0):Engineer(fullName, id, salaryRate, workTime) {

        coefficient = 0.1;

    }

};
