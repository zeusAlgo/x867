#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

Roster::Roster() { classRosterArray = new Student * [5];};

Roster::~Roster() { delete[] classRosterArray;};

void Roster::test() {
    const string studentData[5] = {
            "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
            "A2,Suzan,Erickson,Erickson_199@gmail.com,19,50,30,40,NETWORK",
            "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
            "A4,Erin,Black,Erin.black@comcast.net,22,40,58,40,SECURITY",
            "A5,Regis,Tribbet,registribbet@gmail.com,10,20,200,SOFTWARE"
    };

//    string usr[9];
//    map<int, string[]> usrMap;
//usrMap[0] =  {"A1","John","Smith","John1989@gmail.com",
//              "20","30","35","40","SECURITY"};

//    usrMap.insert(make_pair(
//            0, {"A1","John","Smith","John1989@gmail.com","20","30","35","40","SECURITY"}
//            ));
}

void Roster::printMajor(int idx) {
    std::unordered_map<int, string>degreeHashmap;
    degreeHashmap[0] = "SECURITY";
    degreeHashmap[1] = "NETWORK";
    degreeHashmap[2] = "SOFTWARE";
    cout << degreeHashmap[idx];
}

void Roster::printDegreeString(int idx) {
    switch (idx) {
        case 0:
            cout << "SECURITY"; break;
        case 1:
            cout << "NETWORK"; break;
        case 2:
            cout << "SOFTWARE"; break;
        default:
            cout << "NULL"; break;
    }
    // instantiate hashmap and print degree string from that
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

void Roster::removeStudent(string sId) {
    bool indexFound = false;
    int indexNum = 0;

    std::cout << "Searching for student by Id: " << sId;

    for (int i = 0; i< 5; i++) {
        if (this ->classRosterArray[i] -> getId() == sId) {
            indexNum = i;
            indexFound = true;
            cout << "."; break;
        } else {
            indexFound = false;
            cout << "."; continue;
        }
    }

    std::cout << std::endl;

    if (indexFound) {
        cout << "Student found. Removing student from roster.";
        const int idx = indexNum;
        auto* xstudent = new Student();

        xstudent -> setId("Null");
        cout << ".";
        xstudent ->setFirstName("");
        cout << ".";
        xstudent -> setLastName("");
        cout << ".";
        xstudent -> setEmailAddress("");
        cout << ".";
        xstudent -> setAge("");
        cout << ".";
        xstudent ->setDays(0, 0, 0);
        cout << ".";
        xstudent ->setDegreeProgram(INIT);
        cout << ".";
        classRosterArray[idx] = xstudent;
        cout << "Done";
    } else {
        cout << "Student" << sId << "not found.";
    }
    cout << endl;
}

void Roster::parseArray(int rosterIndex) {
    string studentDataString = studentData[rosterIndex];
    int stringLength = studentDataString.length();

    string studentId; string firstName; string lastName; string email;
    string age; string stringDays0; string stringDays1; string stringDays2;
    int days0 = 0; int days1 = 0; int days2 = 0;
    string degreeProgramString; DegreeProgram studentDegree;

    int i = 0; int commasSkipped = 0;

    for (i = 0; i < stringLength; i++) {
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
    stringstream  daysConvert1(stringDays1); stringstream  daysConvert2(stringDays2);
    daysConvert0 >> days0; daysConvert1 >> days1; daysConvert2 >> days2;

    if (degreeProgramString == "SECURITY") {
        studentDegree = SECURITY;
    } else if (degreeProgramString == "NETWORK") {
        studentDegree = NETWORK;
    } else  {
        studentDegree = INIT;
    }
    addStudent(
            rosterIndex, studentId, firstName, lastName,
            email, age, days0, days1, days2, studentDegree
            );
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] -> getId() != "NUL") {
            classRosterArray[i] -> print(0); cout << " ";
            classRosterArray[i] -> print(1); cout << " ";
            classRosterArray[i] -> print(2); cout << " ";
            classRosterArray[i] -> print(3); cout << " ";
            classRosterArray[i] -> print(4); cout << " ";
            classRosterArray[i] -> print(5); cout << ",";
            classRosterArray[i] -> print(6); cout << ",";
            classRosterArray[i] -> print(7); cout << ") \n"; cout << "Degree Program:";
            printDegreeString(classRosterArray[i] -> getDegreeProgram());
            cout << endl;
        }
    }
    cout << endl;
}

void Roster::printMeanDaysInCourse(const string& sId) const {
    for (int idx = 0; idx <= 5; idx++) {
        if (classRosterArray[idx] -> getId() == sId) {
            int mean = (classRosterArray[idx] ->getDays(0) +
                        classRosterArray[idx] ->getDays(1) +
                        classRosterArray[idx] ->getDays(2)) / 3;
            cout << mean <<
            " days is the mean days in course for student " << sId;
            cout << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    cout << "Printing invalid emails: " << endl;

    for (int i = 0; i < 5; i++) {
        std::string emailStr = classRosterArray[i] -> getEmailAddress();
        if ((emailStr.find('@') != std::string::npos) && emailStr.find('.') != std::string::npos) {
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

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Printing students by degree program";
    printDegreeString(degreeProgram);
    cout << ":" << endl;

    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] -> getDegreeProgram() == degreeProgram) {
            if (classRosterArray[i] -> getId() != "NUL") {
                classRosterArray[i] -> print(0);
                cout << " ";
                cout << "First Name: ";
//                classRosterArray[i] -> print(1);
                classRosterArray[i] -> printUsr(1);
                cout << " ";
                cout << "Last Name:";
                classRosterArray[i] -> printUsr(2);
                cout << " ";
                cout << "Age: ";
                classRosterArray[i] -> printUsr(4);
                cout << "";
                cout << "Days in Course {";
                classRosterArray[i] -> printUsr(5);
                cout << " ";
                classRosterArray[i] -> printUsr(6);
                cout << " ";
                classRosterArray[i] -> printUsr(7);
                cout << "}";
                cout << "Degree Program: ";

                printDegreeString(classRosterArray[i] -> getDegreeProgram());
                cout << endl;
            }
        }
    }
}
