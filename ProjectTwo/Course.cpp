#include "Course.h"
#include <iostream>

using namespace std;

Course::Course(string num, string name, vector<string> prereqs)
    : courseNumber(num), courseName(name), prerequisites(prereqs) {}

void Course::printCourseInfo() const {
    cout << courseNumber << " " << courseName << endl;
    cout << "Prerequisites: ";
    if (prerequisites.empty()) {
        cout << "None";
    }
    for (const auto& prereq : prerequisites) {
        cout << prereq << " ";
    }
    cout << endl;
}
