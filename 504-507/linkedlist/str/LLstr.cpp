#include <iostream>
#include "LLstr.h"

using std::cout, std::endl;

void LLstr::insertFront(const char& val) {
    Node* newNode = new Node(val);
    if (head == nullptr) { // empty list
        head = newNode;
        tail = newNode;
    }
    else { // head points to a node
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void LLstr::insertBack(const char& val) {
    Node* newNode = new Node(val);
    if (tail == nullptr) { // empty list
        head = newNode;
        tail = newNode;
    }
    else { // head points to a node
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void LLstr::print(std::ostream& os) const {
}

void LLstr::printReverse(std::ostream& os) const {
}

LLstr::LLstr(const std::string& src) : head(nullptr), tail(nullptr) { // copy std::string
}

LLstr::LLstr(const char* src) : head(nullptr), tail(nullptr) { // copy c-string
}

std::ostream& operator<<(std::ostream& os, const LLstr& src) {
}

Node* LLstr::find(const int& val) {
}

bool LLstr::hasChar(const char& val) {
    // use find function
}

char LLstr::peekFront() const {
}

char LLstr::peekBack() const {
}

void LLstr::insertAfter(const char& valToAdd, const char& valToFind) {
}

void LLstr::insertBefore(const char& valToAdd, const char& valToFind) {
}

void LLstr::remove(const char& c) {
}