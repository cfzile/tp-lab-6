#pragma once

#include "../../Project.h"
#include "../Employee.h"

class Manager : public Employee, public virtual Project{

public:

    Manager (FULLNAME fullName, unsigned int id,
             unsigned int workTime = 0):Employee(fullName, id, workTime){

        coefficient = 0.3;

    }

    double getProfitFromProject(PROJECT * project){

        return project->cost * projects[project] * coefficient;

    }

    virtual double getPayment(){

        return getProjectProfit();

    }

    virtual std::string getInfo(){

        std::string info = std::to_string(id);
        info += " ";
        info += fullName.getString();
        info += " ";
        info += "-";
        info += " ";
        info += std::to_string(getPayment());

        return info;

    }

};
