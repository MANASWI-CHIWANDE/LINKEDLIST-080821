#include <iostream>
#include <typeinfo>
using namespace std;
#include "./circularLinkedList.cpp"

int main()
{
    CircularLinkedlist cll = CircularLinkedlist();
    cll.append(100);
    cll.append(200);
    cll.append(300);
    cll.append(78);
    cll.print();
    cll.prepend(890);
    cll.print();
    cll.insert(200, 670);
    cll.countNode();
    cll.print();
    cll.dElete(890);
    cll.print();
    cll.dElete(200);
    cll.print();
    cll.dElete(78);
    cll.print();
    cll.update(300, 340);
    cll.print();

    return 0;
}