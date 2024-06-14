#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using namespace std;

int main() {
    // Create a new linked list
    LinkedList<int> list;

    auto item1 = make_shared<int>(10);
    auto item2 = make_shared<int>(20);
    auto item3 = make_shared<int>(30);
    auto item4 = make_shared<int>(40);
    auto item5 = make_shared<int>(40);

    // Test IsEmpty method
    cout << "Is the list empty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

    // Add items to the list
    list.AddItem(item1);
    list.AddItem(item2);
    list.AddItem(item3);
    list.AddItem(item4);

    // Print the list
    cout << "List contents after adding items: ";
    list.Print();

    // Test IsEmpty method again
    cout << "Is the list empty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

    // Test IsInList method
    cout << "Is 20 in the list? " << (list.IsInList(item2) ? "Yes" : "No") << endl;
    cout << "Is 50 in the list? " << (list.IsInList(item5) ? "Yes" : "No") << endl;

    // Test GetItem method
    auto item = list.GetItem(item2);
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
    otherList.AddItem(item1);
    otherList.AddItem(item2);
    otherList.AddItem(item3);

    // Test comparison operators
    cout << "Is the original list < other list? " << (list < otherList ? "Yes" : "No") << endl;
    cout << "Is the original list > other list? " << (list > otherList ? "Yes" : "No") << endl;
    cout << "Is the original list == other list? " << (list == otherList ? "Yes" : "No") << endl;

    return 0;
}


