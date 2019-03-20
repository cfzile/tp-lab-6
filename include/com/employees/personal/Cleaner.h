#include "Personal.h"

class Cleaner : public Personal {

public:

    Cleaner (FULLNAME fullName, unsigned int id, double salaryRate,
             unsigned int workTime = 0):Personal(fullName, id, salaryRate, workTime){

        norma = 25;

    }

    virtual double getPayment(){

        return getEarnings() + std::max(0, (int)workTime - norma);

    }

};
