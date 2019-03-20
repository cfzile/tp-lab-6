#include "Personal.h"

class Driver : public Personal {

public:

    Driver (FULLNAME fullName, unsigned int id, double salaryRate,
            unsigned int workTime = 0):Personal(fullName, id, salaryRate, workTime){

        norma = 20;

    }

    virtual double getPayment(){

        return getEarnings() + std::max(0, (int)workTime - norma);

    }

};
