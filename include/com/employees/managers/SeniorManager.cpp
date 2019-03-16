#pragma once

#include "ProjectManager.cpp"

class SeniorManager : public ProjectManager{

public:

    SeniorManager (FULLNAME fullName, unsigned int id,
                   unsigned int workTime = 0, unsigned int salaryRate = 0) : ProjectManager (fullName, id, workTime){

        coefficient = 0.3;

    }

};
