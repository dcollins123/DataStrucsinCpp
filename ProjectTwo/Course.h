#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

using namespace std;

class Course {
public:
    string courseNumber;
    string courseName;
    vector<string> prerequisites;

    Course(string num, string name, vector<string> prereqs);
    void printCourseInfo() const;
};

#endif // COURSE_H
