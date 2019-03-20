#pragma once

struct FULLNAME{

    std::string firstName, secondName, patronymic;

    std::string getString(){

        std::string ans = firstName;
        return ans.append(" ").append(secondName);

    }

    explicit FULLNAME (std::string firstName, std::string secondName, std::string patronymic = ""){

        this->firstName = std::move(firstName);
        this->secondName = std::move(secondName);
        this->patronymic = std::move(patronymic);

    }

    FULLNAME (){

        firstName = "";
        secondName = "";
        patronymic = "";

    }

};
