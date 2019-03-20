#include "Engineer.h"

class Programmer : public Engineer {

public:

    Programmer (FULLNAME fullName, unsigned int id, double salaryRate,
            unsigned int workTime = 0):Engineer(fullName, id, salaryRate, workTime) {

        coefficient = 0.2;

    }

};
