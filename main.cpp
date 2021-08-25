#include<iostream>
#include<typeinfo>
using namespace std;
#include "./singlyLinkedList.cpp"


int main(){

    SinglyLinkedList ssl = SinglyLinkedList();

    ssl.append(100);
    ssl.append(200);
    ssl.append(300);
    ssl.print();
    ssl.countNode();
    ssl.prepend(345);
    ssl.print();
    ssl.countNode();
    ssl.insert(200,500);
    ssl.print();
    ssl.dElete(300);
    ssl.print();
    ssl.countNode();
    ssl.updateNode(200 ,205);
    ssl.print();
    ssl.countNode();

    return 0;

}