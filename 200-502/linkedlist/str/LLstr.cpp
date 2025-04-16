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
    else { // tail points to a node
        tail->next = newNode;
        newNode->prev = tail;
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
    const char* l = src;
    while (*l != '\0') {
        insertBack(*l);
        l++;
    }
    /*
    size_t index = 0;
    while (src[index] != '\0') {
        insertBAck(src[index]);
        index++;
    }
    */
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
    Node* result = find(val);
    return result != nullptr;
    /*
    if (result == nullptr) {
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
    if (head != nullptr) {
        Node* cur = head;
        while (cur != nullptr && cur->letter != valToFind) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            throw std::domain_error("Did not find value to add after");
        }
        Node* newNode = new Node(valToAdd);
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next = newNode;
        if (cur == tail) {
            tail = newNode;
        }
    }
    else {
        throw std::invalid_argument("Cannot add after in empty list");
    }
}

void LLstr::insertBefore(const char& valToAdd, const char& valToFind) {
}

void LLstr::remove(const char& c) {
}