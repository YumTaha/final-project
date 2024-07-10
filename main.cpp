#include "LinkedList.h"
#include <iostream>
#include <memory>

using namespace std;

void displayMenu() {
    cout << "\nLinked List Menu\n";
    cout << "1. Add Item\n";
    cout << "2. Get Item\n";
    cout << "3. Check if Item is in List\n";
    cout << "4. Check if List is Empty\n";
    cout << "5. See Next Item\n";
    cout << "6. See Item at Index\n";
    cout << "7. Reset SeeNext\n";
    cout << "8. Print List\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    LinkedList<int> list;
    int choice, data, index;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to add: ";
                cin >> data;
                list.AddItem(make_shared<int>(data));
                cout << "Item added.\n";
                break;

            case 2:
                cout << "Enter data to get: ";
                cin >> data;
                {
                    auto item = list.GetItem(make_shared<int>(data));
                    if (item) {
                        cout << "Item " << item->Data << " removed from the list.\n";
                    } else {
                        cout << "Item not found in the list.\n";
                    }
                }
                break;

            case 3:
                cout << "Enter data to check: ";
                cin >> data;
                cout << (list.IsInList(make_shared<int>(data)) ? "Item is in the list.\n" : "Item is not in the list.\n");
                break;

            case 4:
                cout << (list.IsEmpty() ? "List is empty.\n" : "List is not empty.\n");
                break;

            case 5:
            {
                auto item = list.SeeNext();
                if (item) {
                    cout << "Next item: " << item->Data << "\n";
                } else {
                    cout << "No more items in the list or list is empty.\n";
                }
            }
                break;

            case 6:
                cout << "Enter index to see: ";
                cin >> index;
                try {
                    auto item = list.SeeAt(index);
                    cout << "Item at index " << index << ": " << item->Data << "\n";
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;

            case 7:
                list.Reset();
                cout << "SeeNext reset.\n";
                break;

            case 8:
                list.Print();
                break;

            case 9:
                system("pause");
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    system("pause");
    return 0;
}
