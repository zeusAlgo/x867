#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
    auto* classRoster = new Roster();

    for (int idx = 0; idx <= 5; idx++) {
        classRoster -> parseArray(idx);
    }

    cout << "Printing all students: " << endl;
    classRoster -> printAll();
    classRoster -> printInvalidEmails();

    cout << "Printing mean days in course for each student: " << endl;

    for (int idx = 0; idx < 5; idx++) {
        classRoster ->printMeanDaysInCourse(
                classRoster -> classRosterArray[idx] -> getId());
    }

    cout << endl;
    classRoster -> printByDegreeProgram(SOFTWARE);
    cout << endl;
    classRoster -> removeStudent("A3");
    cout << endl;
    cout << "Printing all students: \n";
    classRoster -> printAll();
    classRoster -> removeStudent("A3");

    return 0;
}