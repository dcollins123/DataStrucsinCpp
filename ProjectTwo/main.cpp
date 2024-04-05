#include "Course.h"
#include "LinkedList.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void loadDataFromFile(LinkedList& courseList) {
    string fileName;
    cout << "Enter filename: ";
    cin >> fileName;

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Could not open file\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, courseName, prerequisite;
        getline(ss, courseNumber, ',');
        getline(ss, courseName, ',');

        vector<string> prerequisites;
        while (getline(ss, prerequisite, ',')) {
            prerequisites.push_back(prerequisite);
        }

        Course newCourse(courseNumber, courseName, prerequisites);
        courseList.append(newCourse);
    }

    cout << "Data loaded successfully.\n";
}

void printCourseList(const LinkedList& courseList) {
    courseList.printList();
}

void printCourseInfo(LinkedList& courseList) {
    string courseNumber;
    cout << "What course do you want to know about? ";
    cin >> courseNumber;

    Course* course = courseList.find(courseNumber);
    if (course != nullptr) {
        course->printCourseInfo();
    }
    else {
        cout << "Course not found.\n";
    }
}

int main() {
    LinkedList courseList;
    string choice;

    do {
        cout << "\nWelcome to the course planner.\n";
        cout << "1. Load Data Structure\n";
        cout << "2. Print Course List\n";
        cout << "3. Print Course\n";
        cout << "9. Exit\n";
        cout << "What would you like to do? ";
        cin >> choice;

        if (choice == "1") {
            loadDataFromFile(courseList);
        }
        else if (choice == "2") {
            printCourseList(courseList);
        }
        else if (choice == "3") {
            printCourseInfo(courseList);
        }
        else if (choice == "9") {
            cout << "Thank you for using the course planner!\n";
        }
        else {
            cout << choice << " is not a valid option.\n";
        }
    } while (choice != "9");

    return 0;
}
