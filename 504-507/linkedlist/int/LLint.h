#ifndef LLINT_H
#define LLINT_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LLint {
    Node* head;
    Node* tail;
    Node* find(const int& val);
    void printrec(Node* cur, std::ostream& os) const;
    
  public:
    LLint() : head(nullptr), tail(nullptr) {}

    void insertFront(const int& val);
    void insertBack(const int& val);

    bool hasVal(const int& val);

    void insertAfter(const int& valToInsert, const int& valToFind);
    void insertBefore(const int& valToInsert, const int& valToFind);

    void remove(const int& val);

    void clear();

    void print(std::ostream& = std::cout) const;

    void printreverse(std::ostream& = std::cout) const;
};

std::ostream& operator<<(std::ostream&, const LLint&);

#endif