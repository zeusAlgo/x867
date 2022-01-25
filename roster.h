#pragma once
#include "student.h"
#include <unordered_map>
#include <string>

using namespace std;

const string studentData[5] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_199@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,40,58,40,SECURITY",
        "A5,Regis,Tribbet,registribbet@gmail.com,10,20,200,SOFTWARE"
};

//string usr[9];
//std::unordered_map<int, string[9]> usrMap;
//usrMap[0] =

//usrMap.insert(make_pair(0, {"A1","John","Smith","John1989@gmail.com","20","30","35","40","SECURITY"};));
class Roster {
public:
    Roster();

    ~Roster();

    Student** classRosterArray;

    void addStudent(int index, string a, string b, string c, string d,
                    string e, int f, int g, int h, DegreeProgram x);

    void removeStudent(string sId);

    void parseArray(int rosterIndex);

    void printAll();

    void printMeanDaysInCourse(const string& sId) const;

    void printInvalidEmails();

    void printByDegreeProgram(DegreeProgram degreeProgram);

private:
    static void printDegreeString(int dp);

    void printSpace();

    void printDivider();
};
