#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>

#include "../include/com/employees/Employee.h"

using namespace std;

static string positions[7] = {"Cleaner", "Driver", "Tester", "Programmer", "TeamLeader",
                       "ProjectManager", "SeniorManager"};

int main(){

    srand (time(NULL));

    int id = 1;

    ifstream people;
    people.open("../res/people.txt");

    ifstream projects;
    projects.open("../res/projects.txt");

    string project;
    vector<int> projectIds;

    while (getline(projects, project))
        projectIds.push_back(stoi(project.substr(0, project.find(" "))));

    ofstream staff;
    staff.open("../res/staff.txt");

    string name;

    staff << "id FirstName SecondName idPosition Position Base WorkTime Project\n";

    while (getline(people, name)) {

        int p = rand() % END_POSITION;

        staff << ++id << " " << name << " " << POSITION(p) << " "
                                << positions[p] << " " << 2 * max(p, 1) * 10000 << " " << rand() % 100;

        if (p >= 2)
            staff << " " << projectIds[rand() % projectIds.size()];

        staff << "\n";

    }

    staff.close();
    projects.close();
    people.close();

    return 0;

}
