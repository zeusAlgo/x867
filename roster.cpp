#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

Roster::Roster() { classRosterArray = new Student * [5];};
Roster::~Roster() { delete[] classRosterArray;};

void Roster::printDegreeString(int idx) {
    switch (idx) {
        case 0:
            cout << "SECURITY"; break;
        case 1:
            cout << "NETWORK"; break;
        case 2 | 3:
            cout << "SOFTWARE"; break;
        default:
            cout << "NULL"; break;
    }
}

void Roster::addStudent(int index, string a, string b, string c, string d,
                        string e, int f,int g, int h, DegreeProgram x) {
    const int idx = index;
    auto* newStudent = new Student();
    newStudent -> setId(move(a));
    newStudent -> setFirstName(move(b));
    newStudent -> setLastName(move(c));
    newStudent -> setEmailAddress(move(d));
    newStudent -> setAge(move(e));
    newStudent -> setDays(f, g, h);
    newStudent ->setDegreeProgram(x);

    classRosterArray[idx] = newStudent;
}

void Roster::removeStudent(const string& sId) const {
    showHeader("Searching for student by Id: ");
    for (int idx = 0; idx < 5; idx++) {
        auto * currentStudent = classRosterArray[idx];
        if (sId == currentStudent->getId()) {
            cout << "Found student." << endl;
            for (int j = idx;  j<=6; j++) {
                classRosterArray[idx] = classRosterArray[idx + 1];
            }
            cout << "Successfully removed student. \n";
            return;
        }
    }
    cout << "Student " << sId << " not found.";
}

void Roster::parseArray(int idx) {
    string studentDataString = studentData[idx];
    string studentId; string firstName; string lastName; string email;
    string age; string stringDays0; string stringDays1; string stringDays2;
    int days0 = 0; int days1 = 0; int days2 = 0;
    string degreeProgramString; DegreeProgram studentDegree;

    int i = 0; int commasSkipped = 0;

    for (i = 0; i < studentDataString.length(); i++) {
        char s = studentDataString.at(i);
        if (s != ',') {
            switch (commasSkipped) {
                case 0:
                    studentId.push_back(s); break;
                case 1:
                    firstName.push_back(s); break;
                case 2:
                    lastName.push_back(s);break;
                case 3:
                    email.push_back(s);break;
                case 4:
                    age.push_back(s);break;
                case 5:
                    stringDays0.push_back(s);break;
                case 6: stringDays1.push_back(s);break;
                case 7: stringDays2.push_back(s);break;
                case 8:
                    degreeProgramString.push_back(s);break;
                default:
                    break;
            }
        } else {
            commasSkipped = commasSkipped + 1;
        }
    }

    stringstream  daysConvert0(stringDays0);
    stringstream  daysConvert1(stringDays1);
    stringstream  daysConvert2(stringDays2);
    daysConvert0 >> days0; daysConvert1 >> days1; daysConvert2 >> days2;

    if (degreeProgramString == "SECURITY") {
        studentDegree = SECURITY;
    } else if (degreeProgramString == "NETWORK") {
        studentDegree = NETWORK;
    } else  {
        studentDegree = INIT;
    }
    addStudent(
            idx, studentId, firstName,
            lastName, email, age, days0,
            days1, days2, studentDegree
            );
}

void Roster::printAll() const {
    for (int idx = 0; idx < 5; idx++) {
        auto * currentStudent = classRosterArray[idx];

        if (currentStudent -> getId() != "NULL" &&
                currentStudent != classRosterArray[idx-1]) {
            listStudent(currentStudent);
            cout << "Degree Program: ";
            printDegreeString(currentStudent->getDegreeProgram());
            cout << "\n-------------------------" << endl;
        }
    } cout << "" << endl;
}

void Roster::printDivider() {
    cout << " | ";
}
void Roster::printSpace() {
    cout << " ";
}

void Roster:: showHeader(const string& headerText) {
    cout << headerText << endl;
    cout << "=======================" << endl;
}

void Roster::printMeanDaysInCourse(const string& sId) const {
    for (int idx = 0; idx <= 5; idx++) {
        if (sId == classRosterArray[idx]->getId()) {
            int mean = (classRosterArray[idx]->getDays(0) +
                        classRosterArray[idx]->getDays(1) +
                        classRosterArray[idx]->getDays(2)) / 3;
            cout << mean <<
            " days is the mean days in course for student " << sId;
            cout << endl;
        }
    }
}

void Roster::printInvalidEmails() const {
    showHeader("Printing invalid emails:");
    for (int idx = 0; idx < 5; idx++) {
        std::string emailStr = classRosterArray[idx] -> getEmailAddress();
        if ((emailStr.find('@') != std::string::npos) &&
                emailStr.find('.') != std::string::npos) {
            if (emailStr.find(' ') != std::string::npos) {
                std::cout << emailStr;
                std::cout << std::endl;
            }
        } else {
            cout << emailStr << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    showHeader("Printing students by degree program: ");

    unordered_map<int, int> majorMap;
    majorMap[2] = 3;
    majorMap[1] = 1;
    majorMap[0] = 0;

    for (int idx = 0; idx < 5; idx++) {
        auto * currentStudent = classRosterArray[idx];
        if (majorMap[degreeProgram] == currentStudent->getDegreeProgram()) {
            listStudent(currentStudent);
        }
    }
}

void Roster::listStudent(Student *currentStudent) {
    cout << currentStudent->getId(); printDivider();
    cout << currentStudent->getFirstName(); printSpace();
    cout << currentStudent->getLastName(); printDivider();
    cout << currentStudent->getEmailAddress(); printDivider();
    cout << currentStudent->getAge(); printDivider();
    cout << currentStudent->getDays(0);cout << ", ";
    cout << currentStudent->getDays(1);cout << ", ";
    cout << currentStudent->getDays(2) ;cout << " \n";
}
