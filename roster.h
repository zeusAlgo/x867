#pragma once
#include "student.h"
#include <unordered_map>
#include <string>
using namespace std;

const string studentData[5] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_199@gmailc,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,40,58,40,SECURITY",
        "A5,Regis,Tribbet,registribbet@gmail.com,10,20,200,SOFTWARE"
};

class Roster : public error_code {
public:
    Roster();

    ~Roster();

    Student** classRosterArray;

    void addStudent(int index, string a, string b, string c, string d,
                    string e, int f, int g, int h, DegreeProgram x);

    void removeStudent(const string& sId) const;

    void parseArray(int rosterIndex);

    void printAll() const;

    void printMeanDaysInCourse(const string& sId) const;

    void printInvalidEmails() const;

    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    static void showHeader(const string& headerText);

    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    void printByDegreeProgram(DegreeProgram degreeProgram);

private:
    static void printDegreeString(int dp);

    static void printSpace();

    static void printDivider();

};
