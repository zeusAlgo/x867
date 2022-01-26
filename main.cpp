#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
    auto * classRoster = new Roster();
    for (int idx = 0; idx <= 5; idx++) {
        classRoster -> parseArray(idx);
    }

    Roster::showHeader("Printing all students: ");
    classRoster -> printAll();
    classRoster -> printInvalidEmails();

    Roster::showHeader(
            "Printing mean days in course: ");
    for (int idx = 0; idx < 5; idx++) {
        classRoster ->printMeanDaysInCourse(
                classRoster -> classRosterArray[idx]
                        -> getId());
    }

    cout << endl;
    classRoster -> printByDegreeProgram(SOFTWARE);

    classRoster -> printByDegreeProgram(SECURITY);

    classRoster -> printByDegreeProgram(NETWORK);
    cout << endl;
    classRoster -> removeStudent("A3");
    cout << endl;

    Roster::showHeader("Printing all students: ");
    classRoster -> printAll();
    classRoster -> removeStudent("A3");

    return 0;
}