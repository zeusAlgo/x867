#pragma once
#include <iostream>
#include "degree.h"
#include <string>

using namespace std;
class Student {
public:
    Student();

    string getId(); string getFirstName(); string getLastName();
    string getEmailAddress(); string getAge(); int getDays(int atArray);
    DegreeProgram getDegreeProgram();

    void setId(std::string studentId); void setFirstName(std::string firstName);
    void setLastName(std::string lastName); void setEmailAddress(std::string emailAddress);
    void setAge(std::string age); void setDays(int int0, int int1, int int2);
    void setDegreeProgram(DegreeProgram degree);

private:
    string studentId; string firstName; string lastName;
    string emailAddress; string age; int daysInCourse[3];
    DegreeProgram degreeProgram;

};