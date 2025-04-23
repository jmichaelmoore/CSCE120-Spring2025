#include "LLint.h"

using std::cout, std::endl;

Node* LLint::find(const int& val) {
    Node* cur = head;
    while (cur != nullptr) {
        if (cur->data == val) {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}
    
void LLint::insertFront(const int& val) {
    Node* newNode = new Node(val);
    if (head == nullptr) { // empty list
        head = newNode;
        tail = newNode;
    }
    else { // head points to a node
        newNode->next = head;
        head = newNode;
    }
}

void LLint::insertBack(const int& val) {
    Node* newNode = new Node(val);
    if (tail == nullptr) { // empty list
        head = newNode;
        tail = newNode;
    }
    else { // tail points to a node
        tail->next = newNode;
        tail = newNode;
    }
}

bool LLint::hasVal(const int& val) {
    Node* result = find(val);
    return result != nullptr;
}

void LLint::insertAfter(const int& valToInsert, const int& valToFind) {
    if (head != nullptr) {
        Node* cur = head;
        while (cur != nullptr && cur->data != valToFind) {
            cur = cur->next;
        }
        if (cur == nullptr) {
            throw std::domain_error("Did not find value to add after");
        }
        Node* newNode = new Node(valToInsert);
        newNode->next = cur->next;
        cur->next = newNode;
        if (cur == tail) {
            tail = newNode;
        }
    }
    else {
        throw std::invalid_argument("Cannot add after in empty list");
    }
}

void LLint::insertBefore(const int& valToInsert, const int& valToFind) {
    Node* cur = head;
    Node* prev = nullptr;
    while (cur != nullptr && cur->data != valToFind) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == nullptr) {
        throw std::domain_error("Unable to find number to insert before");
    }
    Node* newNode = new Node(valToInsert);
    newNode->next = cur;
    if (prev != nullptr) {
        prev->next = newNode;
    }
    else { // new head
        head = newNode;
    }
}

void LLint::remove(const int& val) {
    Node* cur = head;
    Node* prev = nullptr;
    while (cur != nullptr && cur->data != val) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == nullptr) {
        throw std::domain_error("Unable to find value to delete");
    }
    if (prev == nullptr) { // new head
        head = cur->next;
    }
    else {
        prev->next = cur->next;
    }
    if (tail == cur) {
        tail = prev;
    }
    delete cur;
}

void LLint::clear() {
    Node* cur = head;
    Node* delNode = nullptr;
    while (cur != nullptr) {
        delNode = cur;
        cur = cur->next;
        delete delNode;
    }
    head = nullptr;
    tail = nullptr;
}

void LLint::print(std::ostream& os) const {
    Node* cur = head;
    std::string p;
    while (cur != nullptr) {
        os << p << cur->data;
        p = " -> ";
        cur = cur->next;
    }
    if (cur != nullptr)
        os << " -|";
}

void LLint::printrec(Node* cur, std::ostream& os) const {
    if (cur == nullptr)
        return;
    printrec(cur->next, os);
    os << cur->data << endl;
}

void LLint::printreverse(std::ostream& os) const {
    printrec(head, os);
}

std::ostream& operator<<(std::ostream& os, const LLint& src) {
    src.print(os);
    return os;
}
