#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main() {
    // Create an ordered linked list
    LinkedList<int> list;

    list.SeeNext();

    // Add items to the list
    list.AddItem(new Node(20));
    list.AddItem(new Node(10));
    list.AddItem(new Node(30));

    // Print the contents of the list
    cout << "List contents: ";
    list.Print();

    // Use SeeNext to iterate through the list
    cout << "Using SeeNext: ";
    Node<int>* node;
    while ((node = list.SeeNext()) != nullptr) {
        cout << node->Data << " ";
    }
    cout << endl;

    // Reset and iterate again
    list.Reset();
    cout << "Using SeeNext after Reset: ";
    while ((node = list.SeeNext()) != nullptr) {
        cout << node->Data << " ";
    }
    cout << endl;

    cout << list.IsEmpty() << list.IsInList(30);
    Node<int>* pNode = list.GetItem(30);
    list.AddItem(pNode);

    return 0;
}

