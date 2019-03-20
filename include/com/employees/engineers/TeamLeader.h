#pragma once

#include "Programmer.h"
#include "../../Heading.h"

class TeamLeader : public Programmer, public virtual Heading {

public:

    TeamLeader(FULLNAME fullName, unsigned int id, double salaryRate,
               unsigned int workTime = 0) : Programmer(fullName, id, salaryRate, workTime) {

        coefficient = 0.3;

    }

    double getProfitFromManagement(){

        return subordinates.size() * 1000;

    }

    virtual double getPayment(){

        return payment = getEarnings() + getProjectProfit() + getProfitFromManagement();

    }

};
