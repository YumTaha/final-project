//
// Created by Taha on 6/13/2024.
//

#ifndef QUANTUMDINGLES_LINKEDLIST_H
#define QUANTUMDINGLES_LINKEDLIST_H

#include "Node.h"
#include <iostream>

using namespace std;

template <typename T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* CurrentNode;

    [[nodiscard]] int getLength() const {
        int length = 0;
        Node<T>* current = head;
        while (current) {
            length++;
            current = current->next;
        }
        return length;
    }

public:
// TODO Constructor
    LinkedList(): head(nullptr), tail(nullptr), CurrentNode(nullptr){}

// TODO Destructor
    virtual ~LinkedList(){
        while (head){
            Node<T>* toBeDel = head;
            head = head->next;
            delete toBeDel;
        }
    }

// TODO AddItem – adds an item from the list
    void AddItem(T data) {
        auto* newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

// TODO GetItem – searches the list for the given item. If found, it removes it from the list and returns it. If not found, it returns a null pointer.
    Node<T>* GetItem(T item){
        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while (current){
            if (current->Data == item){
                if (previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                // Isolate the node
                current->next = nullptr;
                return current;
            }
            previous = current;
            current = current->next;
        }
        return nullptr;
    }

// TODO IsInlist – returns a bool indicating if the given item is in the list.
    bool IsInList(T item){
        Node<T>* current = head;
        while (current){
            if (current->Data == item) return true;
            current = current->next;
        }
        return false;
    }

// TODO IsEmpty – returns a bool indicating if the list is empty.
    bool IsEmpty() { return (head == nullptr); }

 /*TODO SeeNext – returns the item without removing it from the list at a given location in the list.
  * The class will maintain the next location and will start at the first item in the list.
  * When it gets to the last item in the list, it will return a null pointer after it gets past the last item.
  * If the list is empty, this will throw an error or display an error message.
  * 2 calls to SeeNext will return the 2 items next to each other in the list unless SeeAt or Reset is called
  * in between the 2 calls (or the first call returns the last item in the list).*/
    Node<T>* SeeNext() {
        if (head == nullptr) {
            throw runtime_error("ERROR: List is empty!");
        }else if (CurrentNode == nullptr) {
            CurrentNode = head;
        }else { CurrentNode = CurrentNode->next; }

        if (CurrentNode == nullptr) {
            cout << " End of the list reached!" << endl;
            return nullptr;
        }
        return CurrentNode;
    }

 /*TODO SeeAt – Finds an item at a location in the list (int passed in from user).
 * returns the item without removing it. If the location passed by the user is
 * past the end of the list, this will throw an error or display an error
 * message. This will set the location used by SeeNext to point at the item
 * after the item returned*/
    Node<T>* SeeAt(int index){
        Node<T>* current = head;
        int count = 0;

        if (index < 0){
            throw runtime_error("ERROR: Index must be non-negative!");
        }

        while (current != nullptr) {
            if (count == index){
                CurrentNode = current;
                return current;
            }
            current = current->next;
            count++;
        }

        throw runtime_error("ERROR: Index out of range!");
    }

// TODO Reset – resets the location that the SeeNext function uses to point at the first item in the list.
    void Reset() { CurrentNode = nullptr; }


/*// TODO operators < > ==
    bool operator<(const LinkedList<T>& other) const{
        LinkedList<T> currentNode = head;
        LinkedList<T> otherNode = other.head;

        while (currentNode && otherNode){
            if (currentNode->Data < otherNode->Data) return true;
            if (currentNode->Data > otherNode->Data) return false;
            currentNode = currentNode->next;
            otherNode = otherNode->next;
        }
        return currentNode == nullptr && otherNode != nullptr;
    }
};*/

// TODO operators < > ==
    bool operator<(const LinkedList<T>& other) const{ return getLength() < other.getLength();}
    bool operator==(const LinkedList<T>& other) const{ return getLength() == other.getLength();}
    bool operator>(const LinkedList<T>& other) const{ return getLength() > other.getLength();}

    void Print() {
        Node<T>* current = head; // Start with the head of the list
        while (current != nullptr) { // Continue until the end of the list
            cout << current->Data << "->"; // Print the id of the current node
            current = current->next; // Move to the next node
        }
        cout << endl; // Print a newline at the end
    }
};


#endif //QUANTUMDINGLES_LINKEDLIST_H
