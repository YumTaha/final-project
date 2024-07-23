//
// Created by Taha on 6/13/2024.
//

#ifndef QUANTUMDINGLES_LINKEDLIST_H
#define QUANTUMDINGLES_LINKEDLIST_H

#include <iostream>
#include <memory>
#include "Node.h"
#include "Student.h"

using namespace std;

template <typename T>
class LinkedList {
private:
    shared_ptr<Node<T>> head;
    shared_ptr<Node<T>> tail;
    shared_ptr<Node<T>> CurrentNode;

public:
    LinkedList() : head(nullptr), tail(nullptr), CurrentNode(nullptr) {}

    virtual ~LinkedList() {
        while (head) {
            head = head->next;
        }
    }

    void AddItem(shared_ptr<Node<T>> newNode) {
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    shared_ptr<Node<T>> GetItem(const T& item) {
        shared_ptr<Node<T>> current = head;
        shared_ptr<Node<T>> previous = nullptr;

        while (current) {
            if (current->Data == item) {
                if (previous == nullptr) {
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                current->next = nullptr;
                return current;
            }
            previous = current;
            current = current->next;
        }
        return nullptr;
    }

    bool IsInList(const T& item) const {
        shared_ptr<Node<T>> current = head;
        while (current) {
            if (current->Data == item) return true;
            current = current->next;
        }
        return false;
    }

    [[nodiscard]] bool IsEmpty() const { return head == nullptr; }

    shared_ptr<Node<T>> SeeNext() {
        if (head == nullptr) {
            cout << "ERROR: List is empty!" << endl;
            return nullptr;
        }

        if (CurrentNode == nullptr) {
            CurrentNode = head;
        } else {
            CurrentNode = CurrentNode->next;
        }

        if (CurrentNode == nullptr) {
            cout << "End of the list reached!" << endl;
            return nullptr;
        }

        return CurrentNode;
    }

    void Reset() { CurrentNode = nullptr; }

    shared_ptr<Node<T>> SeeAt(int index) {
        shared_ptr<Node<T>> current = head;
        int count = 0;
        while (current) {
            if (count == index) {
                CurrentNode = current->next;
                return current;
            }
            count++;
            current = current->next;
        }
        throw out_of_range("Index out of range");
    }

    bool operator<(const LinkedList<T>& other) const { return getLength() < other.getLength(); }
    bool operator==(const LinkedList<T>& other) const { return getLength() == other.getLength(); }
    bool operator>(const LinkedList<T>& other) const { return getLength() > other.getLength(); }

    [[nodiscard]] int getLength() const {
        int length = 0;
        shared_ptr<Node<T>> current = head;
        while (current) {
            length++;
            current = current->next;
        }
        return length;
    }


    void DisplayList() const {
        auto current = head;
        while (current) {
            current->Data.Display();
            current = current->next;
        }
    }
};

#endif //QUANTUMDINGLES_LINKEDLIST_H