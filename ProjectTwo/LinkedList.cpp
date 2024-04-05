#include "LinkedList.h"
#include <iostream>

using namespace std;

Node::Node(Course aCourse) : course(aCourse), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::append(Course aCourse) {
    Node* newNode = new Node(aCourse);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void LinkedList::printList() const {
    Node* current = head;
    while (current != nullptr) {
        current->course.printCourseInfo();
        current = current->next;
    }
}

Course* LinkedList::find(string courseNumber) {
    Node* current = head;
    while (current != nullptr) {
        if (current->course.courseNumber == courseNumber) {
            return &(current->course);
        }
        current = current->next;
    }
    return nullptr;
}
