#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
#include "student.h"
using namespace std;

Student::Student() {
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = "";
    for (int &idx: this->daysInCourse) {
        idx = 0;
    }
    this->degreeProgram = INIT;
}
string Student::getId() {return studentId;}
string Student::getFirstName() {return firstName;}
string Student::getLastName() {return lastName;}
string Student::getEmailAddress() {return emailAddress;}
string Student::getAge() {return age;}
int Student::getDays(int atArray) {
    return daysInCourse[atArray];}
DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;}

void Student::setId(string studentId) {
    this -> studentId = move(studentId);
}
void Student::setFirstName(string firstName) {
    this -> firstName = move(firstName);
}
void Student::setLastName(string lastName) {
    this -> lastName = move(lastName);
}
void Student::setEmailAddress(string emailAddress) {
    this -> emailAddress = move(emailAddress);
}
void Student::setAge(string age) {
    this -> age = std::move(age);}
void Student::setDays(int int0, int int1, int int2) {
    this -> daysInCourse[0] = int0;
    this -> daysInCourse[1] = int1;
    this -> daysInCourse[2] = int2;
}

void Student::setDegreeProgram(DegreeProgram degree) {
    this-> degreeProgram = degree;
}