#include "../include/com/employees/engineers/TeamLeader.h"
#include "../include/com/employees/engineers/Tester.h"
#include "../include/com/employees/personal/Cleaner.h"
#include "../include/com/employees/personal/Driver.h"
#include "../include/com/employees/managers/SeniorManager.h"

#include <fstream>
#include <map>
#include <vector>
#include <numeric>
#include <typeinfo>

using namespace std;

map<int, PROJECT *> projects;

struct InfoEmployee{
    FULLNAME fullName;
    unsigned int id;
    int project;
    unsigned int base;
    unsigned int workTime;
};

template <typename T>

static T * create (FULLNAME fullName, unsigned int id,
        double base = 0, unsigned int workTime = 0){

    if (typeid(T) == typeid(class::ProjectManager) || typeid(T) == typeid(class::SeniorManager))
        return new T(fullName, id, workTime);

    return new T(fullName, id, base, workTime);

}

template <class T>

string getInfo (InfoEmployee & employee){

    auto e = create<T>(employee.fullName, employee.id, employee.base, employee.workTime);
    e->joinProject (projects[employee.project]);
    return e->getInfo();

}

template <>

string getInfo<class::Driver> (InfoEmployee & employee){

    auto e = create<class::Driver>(employee.fullName, employee.id, employee.base, employee.workTime);
    return e->getInfo();

}

template <>

string getInfo<class::Cleaner> (InfoEmployee & employee){

    auto e = create<class::Cleaner>(employee.fullName, employee.id, employee.base, employee.workTime);
    return e->getInfo();

}

vector<string> parse (string s, char p){

    string cur;
    vector<string> res;

    for (char i : s){
        if (i == p){
            res.push_back(cur);
            cur = "";
        }else
            cur += i;
    }

    if (cur != "")
        res.push_back(cur);

    return res;

}

void loadProjects (string file){

    ifstream fileProjects;
    fileProjects.open(file);

    string project;

    while (getline(fileProjects, project)) {
        int id = stoi(project.substr(0, project.find(' ')));
        int cost = stoi(project.substr(project.find_last_of(' ') + 1));
        auto * cur = new PROJECT{id, cost};
        projects[id] = cur;
    }

    fileProjects.close();

}

static int tableSpace[10] = {4, 15, 15, 16, 16, 15, 10, 12, 10};

string getCTimes (char c, int p){

    string s;
    for (int i = 0; i < p; i++)
        s += c;

    return s;
}

void printLineOfTable (string line, ofstream & table){

    vector<string> data = parse(line, ' ');

    for (int i = 0; i < (int)data.size(); i++){
        int p = tableSpace[i] - min((int)data[i].size(), tableSpace[i]);
        table << data[i] << getCTimes (' ', p) << (i != (int)data.size() - 1 ? "| " : " ");
    }

    table << "\n" << getCTimes('-', accumulate(tableSpace, tableSpace + data.size() + 1, 0)) << "\n";

}

int main(){

    loadProjects("../res/projects.txt"); // загрузка проектов

    ifstream staffBd;
    staffBd.open("../res/staff.txt"); // информация о работниках

    ofstream table;
    table.open("../res/table.txt"); // таблица

    printLineOfTable("id FirstName SecondName Base Payment Position WorkTime Project", table);

    string cur;
    getline(staffBd, cur); // шапка

    while (getline(staffBd, cur)){

        vector<string> data = parse (cur, ' ');

        unsigned int id = stoul(data[0]);
        FULLNAME fullName(data[1], data[2]);
        int position = stoi(data[3]);
        string positionName = data[4];
        unsigned int base = stoul(data[5]);
        unsigned int workTime = stoul(data[6]);
        int project = (data.size() > 7 ? stoi(data.back()) : -1);

        InfoEmployee employee = {fullName, id, project, base, workTime};

        string info;

        switch(position){

            case Programmer:
                info = getInfo<class::Programmer>(employee);
                break;

            case Tester:
                info = getInfo<class::Tester>(employee);
                break;

            case Cleaner:
                info = getInfo<class::Cleaner>(employee);
                break;

            case Driver:
                info = getInfo<class::Driver>(employee);
                break;

            case TeamLeader:
                info = getInfo<class::TeamLeader>(employee);
                break;

            case ProjectManager:
                info = getInfo<class::ProjectManager>(employee);
                break;

            case SeniorManager:
                info = getInfo<class::SeniorManager>(employee);
                break;

        }

        printLineOfTable(info.append(" ").append(positionName).append(" ").append(to_string(workTime))
                              .append(" ").append((project == -1 ? "-" : to_string(project))), table);

    }

    table.close();
    staffBd.close();

    return 0;

}
