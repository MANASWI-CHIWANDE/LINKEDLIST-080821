#include <iostream>
#include "./doublyLinkedList.cpp"
using namespace std;

int main()
{
    DoublyLinkedlist dll = DoublyLinkedlist();
    dll.append(234);
    dll.append(789);
    dll.append(546);
    dll.insert(234, 100);
    dll.countNode();
    dll.print();
    dll.prepend(324);
    dll.prepend(5);
    dll.countNode();
    dll.print();
    dll.dElete(5);
    dll.print();
    dll.dElete(789);
    dll.print();
    dll.dElete(546);
    dll.countNode();
    dll.print();
    dll.append(12);
    dll.append(44);
    dll.print();
    dll.updateNode(44, 33);
    dll.print();
    dll.insert(100, 209);
    dll.print();
    
    return 0;
}