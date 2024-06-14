#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main() {
    // Create a new linked list
    LinkedList<int> list;

    // Test IsEmpty method
    cout << "Is the list empty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

    // Add items to the list
    list.AddItem(10);
    list.AddItem(20);
    list.AddItem(30);
    list.AddItem(40);

    // Print the list
    cout << "List contents after adding items: ";
    list.Print();

    // Test IsEmpty method again
    cout << "Is the list empty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

    // Test IsInList method
    cout << "Is 20 in the list? " << (list.IsInList(20) ? "Yes" : "No") << endl;
    cout << "Is 50 in the list? " << (list.IsInList(50) ? "Yes" : "No") << endl;

    // Test GetItem method
    auto item = list.GetItem(20);
    if (item) {
        cout << "Got item: " << item->Data << endl;
    } else {
        cout << "Item not found" << endl;
    }

    // Print the list after removing an item
    cout << "List contents after removing 20: ";
    list.Print();

    // Test SeeNext method
    cout << "Using SeeNext: ";
    try {
        shared_ptr<Node<int>> node;
        while ((node = list.SeeNext()) != nullptr) {
            cout << node->Data << " ";
        }
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    cout << endl;

    // Reset the SeeNext pointer
    list.Reset();

    // Test SeeNext after Reset
    cout << "Using SeeNext after Reset: ";
    try {
        shared_ptr<Node<int>> node;
        while ((node = list.SeeNext()) != nullptr) {
            cout << node->Data << " ";
        }
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
    cout << endl;

    // Test SeeAt method
    try {
        auto itemAt = list.SeeAt(1);
        cout << "Item at index 1: " << itemAt->Data << endl;
    } catch (const std::out_of_range& e) {
        cout << e.what() << endl;
    }

    // Test SeeNext after SeeAt
    cout << "Using SeeNext after SeeAt: ";
    try {
        auto nextItem = list.SeeNext();
        if (nextItem) {
            cout << "Next item after index 1: " << nextItem->Data << endl;
        }
    } catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    // Add more items to the list for comparison
    LinkedList<int> otherList;
    otherList.AddItem(10);
    otherList.AddItem(20);
    otherList.AddItem(30);

    // Test comparison operators
    cout << "Is the original list < other list? " << (list < otherList ? "Yes" : "No") << endl;
    cout << "Is the original list > other list? " << (list > otherList ? "Yes" : "No") << endl;
    cout << "Is the original list == other list? " << (list == otherList ? "Yes" : "No") << endl;

    return 0;
}


