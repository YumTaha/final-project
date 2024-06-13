//
// Created by Taha on 6/13/2024.
//

#ifndef QUANTUMDINGLES_NODE_H
#define QUANTUMDINGLES_NODE_H

#include <iostream>

using namespace std;

template <typename T>
class Node {
// protected:

public:
    T Data;
    Node* next;

    explicit Node(T initialData) : Data(initialData), next(nullptr) {}

};

#endif //QUANTUMDINGLES_NODE_H
