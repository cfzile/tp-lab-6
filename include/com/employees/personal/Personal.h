#pragma once

#include "../../WorkTime.h"
#include "../Employee.h"

class Personal : public Employee, public virtual WorkTime {

public:

    int norma;

    Personal (FULLNAME fullName, unsigned int id, double salaryRate,
              unsigned int workTime = 0):Employee(fullName, id, workTime){

        this->salaryRate = salaryRate;
        norma = 20;

    }

    double getEarnings(){

        return salaryRate * workTime/norma;

    }

    virtual double getPayment(){

        return getEarnings();

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
