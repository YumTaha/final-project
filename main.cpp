#include <iostream>
#include <memory>
#include "LinkedList.h"
#include "Student.h"

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

tm inputDate() {
    int year, month, day;
    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter day: ";
    cin >> day;

    tm date = {};
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;

    return date;
}

int main() {
    LinkedList<Student> list;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                string firstName, lastName, mNumber;
                tm birthday;
                double gpa;

                cout << "Enter first name: ";
                cin >> firstName;
                cout << "Enter last name: ";
                cin >> lastName;
                cout << "Enter MNumber: ";
                cin >> mNumber;
                cout << "Enter birthday: \n";
                birthday = inputDate();
                cout << "Enter GPA (optional, press 0 if not): ";
                cin >> gpa;

                Student newStudent(firstName, lastName, mNumber, birthday, gpa);
                list.AddItem(make_shared<Node<Student>>(newStudent));
                cout << "Item added.\n";
                break;
            }
            case 2: {
                string mNumber;
                cout << "Enter MNumber to get: ";
                cin >> mNumber;
                Student dummyStudent("", "", mNumber, {}, 0.0);
                auto item = list.GetItem(dummyStudent);
                if (item) {
                    cout << "Item " << item->Data.GetName() << " removed from the list.\n";
                } else {
                    cout << "Item not found in the list.\n";
                }
                break;
            }
            case 3: {
                string mNumber;
                cout << "Enter MNumber to check: ";
                cin >> mNumber;
                Student dummyStudent("", "", mNumber, {}, 0.0);
                cout << (list.IsInList(dummyStudent) ? "Item is in the list.\n" : "Item is not in the list.\n");
                break;
            }
            case 4:
                cout << (list.IsEmpty() ? "List is empty.\n" : "List is not empty.\n");
                break;
            case 5: {
                auto item = list.SeeNext();
                if (item) {
                    cout << "Next item: " << item->Data.GetName() << "\n";
                } else {
                    cout << "No more items in the list or list is empty.\n";
                }
                break;
            }
            case 6: {
                int index;
                cout << "Enter index to see: ";
                cin >> index;
                try {
                    auto item = list.SeeAt(index);
                    cout << "Item at index " << index << ": " << item->Data.GetName() << "\n";
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 7:
                list.Reset();
                cout << "SeeNext reset.\n";
                break;
            case 8:
                list.Print();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}
