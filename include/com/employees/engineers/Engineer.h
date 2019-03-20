#pragma once

#include "../../WorkTime.h"
#include "../../Project.h"
#include "../Employee.h"

#include <string>

class Engineer : public Employee, public virtual WorkTime, public virtual Project{

public:

    Engineer (FULLNAME fullName, unsigned int id, double salaryRate,
            unsigned int workTime = 0):Employee(fullName, id, workTime) {

        this->salaryRate = salaryRate;
        coefficient = 0.3;

    }

    double getEarnings(){

        return salaryRate * workTime;

    }

    double getProfitFromProject(PROJECT * project){

        return project->cost * projects[project] * coefficient;

    }

    virtual double getPayment(){

        return payment = getEarnings() + getProjectProfit();

    }

    virtual std::string getInfo(){

        std::string info = std::to_string(id);
        info += " ";
        info += fullName.getString();
        info += " ";
        info += std::to_string(salaryRate);
        info += " ";
        info += std::to_string(getPayment());

        return info;

    }

};
