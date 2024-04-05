#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Course.h"

using namespace std;

class Node {
public:
    Course course;
    Node* next;

    Node(Course aCourse);
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void append(Course aCourse);
    void printList() const;
    Course* find(string courseNumber);
};

#endif // LINKEDLIST_H
