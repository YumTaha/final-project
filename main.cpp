#include <iostream>
#include "Node.h"
#include "LinkedList.h"

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
    return 0;
}
