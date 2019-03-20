#pragma once

#include "../FULLNAME.h"

class Tester;
class Programmer;
class Cleaner;
class Driver;
class ProjectManager;
class SeniorManager;
class TeamLeader;

enum POSITION{

    Cleaner = 0, Driver, Tester, Programmer, TeamLeader, ProjectManager, SeniorManager, END_POSITION

};

class Employee{

public:

    FULLNAME fullName;
    unsigned int id, workTime;
    double payment;

    Employee(FULLNAME fullName, unsigned int id, unsigned int workTime = 0){

        this->fullName = fullName;
        this->id = id;
        this->workTime = workTime;
        payment = 0;

    }

    virtual double getPayment(){

        return payment;

    }

    virtual std::string getInfo(){

        std::string info = std::to_string(id);
        info += " ";
        info += fullName.getString();
        info += " ";
        info += std::to_string(getPayment());

        return info;

    }

};
