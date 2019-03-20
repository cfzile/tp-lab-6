#pragma once

#include "../../Heading.h"
#include "Manager.h"

class ProjectManager : public Manager, public virtual Heading{

public:

    ProjectManager (FULLNAME fullName, unsigned int id,
                    unsigned int workTime = 0, unsigned int salaryRate = 0) : Manager (fullName, id, workTime){

        coefficient = 0.2;

    }

    double getProfitFromManagement(){

        return subordinates.size() * 1200;

    }

    virtual double getPayment(){

        return payment = getProjectProfit() + getProfitFromManagement();

    }

};
