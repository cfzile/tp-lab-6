#pragma once

#include <unordered_map>

struct PROJECT{

    int id = 0;
    int cost = 0;

};

class Project{

public:

    std::unordered_map<PROJECT *, bool> projects;
    double coefficient;

    void joinProject(PROJECT * project){

        projects[project] = true;

    }

    void finishProject(PROJECT * project){

        projects.erase(project);

    }

    virtual double getProfitFromProject(PROJECT *) = 0;

    virtual double getProjectProfit(){

        double profit = 0;

        for (auto i : projects)
            profit += getProfitFromProject(i.first);

        return profit;

    }

};
