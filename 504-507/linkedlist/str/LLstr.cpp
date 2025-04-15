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
    Node* cur = head;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->next;
    }
}

void LLstr::printReverse(std::ostream& os) const {
    Node* cur = tail;
    while (cur != nullptr) {
        os << cur->letter;
        cur = cur->prev;
    }
}

LLstr::LLstr(const std::string& src) : head(nullptr), tail(nullptr) { // copy std::string
    for (size_t i=0; i<src.size(); ++i) {
        insertBack(src.at(i));
    }
}

LLstr::LLstr(const char* src) : head(nullptr), tail(nullptr) { // copy c-string
    size_t index = 0;
    while (src[index] != '\0') {
        insertBack(src[index]);
        index++;
    }
}

std::ostream& operator<<(std::ostream& os, const LLstr& src) {
    src.print(os);
    return os;
}

Node* LLstr::find(const char& val) {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->letter == val) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

bool LLstr::hasChar(const char& val) {
    // use find function
    Node* node = find(val);
    return node != nullptr;
    /*
    if (node == nullptr) {
        return false;
    }
    else {
        return true;
    }
    */
}

char LLstr::peekFront() const {
    return head->letter;
}

char LLstr::peekBack() const {
    return tail->letter;
}

void LLstr::insertAfter(const char& valToAdd, const char& valToFind) {
    Node* cur = head;
    while (cur != nullptr && cur->letter != valToFind) {
        cur = cur->next;
    }
    if (cur == nullptr) {
        throw std::domain_error("value not found");
    }
    Node* newNode = new Node(valToAdd);
    newNode->next = cur->next;
    newNode->prev = cur;
    cur->next = newNode;
    if (cur == tail) { // also means newNode->next is nullptr
        tail = newNode;
    }
    else {
        newNode->next->prev = newNode;
    }
}

void LLstr::insertBefore(const char& valToAdd, const char& valToFind) {
}

void LLstr::remove(const char& c) {
}