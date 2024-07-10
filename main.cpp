#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "Student.h"

using namespace std;

int main() {
    LinkedList<int> list1;
    LinkedList<int> list2;

    auto* nodeA = new Node(15);
    auto* nodeB = new Node(20);
    auto* nodeC = new Node(30);
    auto* nodeD = new Node(9);

    list1.AddItem(nodeA);
    list1.AddItem(nodeB);
    list2.AddItem(nodeC);
    list2.AddItem(nodeD);

    //auto* NodeGet = list1.GetItem(1);
    //list2.AddItem(NodeGet);
    cout << list1.IsInList(15) << " " << list2.IsInList(3);


    cout << endl;
    list1.Print();
    list2.Print();

/*  Testing Student.h
    tm birthday1 = {0, 0, 0, 15, 6, 2003}; // July 15, 2000
    Student student1("John", "Doe", "M00123456", birthday1, 3.5);

    tm birthday2 = {0, 0, 0, 20, 11, 2004}; // December 20, 2002
    Student student2("Jane", "Smith", "M00123457", birthday2, 3.8);

    tm birthday3 = {0, 0, 0, 1, 0, 2005}; // January 1, 1995
    Student student3("Alice", "Johnson", "M00123455", birthday3, 3.9);

    // Print student information
    cout << "Student 1: " << student1.GetName() << ", MNumber: " << student1.GetMNumber() << ", Age: " << student1.GetAge() << ", GPA: " << 3.5 << endl;
    cout << "Student 2: " << student2.GetName() << ", MNumber: " << student2.GetMNumber() << ", Age: " << student2.GetAge() << ", GPA: " << 3.8 << endl;
    cout << "Student 3: " << student3.GetName() << ", MNumber: " << student3.GetMNumber() << ", Age: " << student3.GetAge() << ", GPA: " << 3.9 << endl;

    // Compare students by MNumber
    cout << endl;
    cout << "Comparing Students by MNumber:" << endl;
    cout << (student1 > student2 ? student1.GetName() + " has a higher MNumber than " + student2.GetName() : student2.GetName() + " has a higher MNumber than " + student1.GetName()) << endl;
    cout << (student1 < student3 ? student1.GetName() + " has a lower MNumber than " + student3.GetName() : student3.GetName() + " has a lower MNumber than " + student1.GetName()) << endl;
    cout << (student2 == student3 ? student2.GetName() + " has the same MNumber as " + student3.GetName() : student2.GetName() + " has a different MNumber than " + student3.GetName()) << endl;
    */
    return 0;
}
