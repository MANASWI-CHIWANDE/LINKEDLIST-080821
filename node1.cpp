#include <iostream>
using namespace std;

class Node
{

private:
    int data;
    Node *nextPtr;
    Node *prevPtr;

public:
    Node();

    Node(int);

    void setData(int k);

    int getData();

    Node* getNextPtr();

    Node* getPrevPtr();

    void setNextPtr(Node *);

    void setPrevPtr(Node *);

    void print();
};

Node::Node()
{
    data = 0;
    nextPtr = NULL;
}


Node::Node( int dataLocal)
{
    data = dataLocal;
    nextPtr = NULL;
}


void Node::setData(int k)
{
    data = k;
}


int Node ::getData()
{
    return data;
}


void Node::setNextPtr(Node * nextptr1){
    nextPtr = nextptr1;
}


void Node::setPrevPtr(Node * prevptr1){
    prevPtr = prevptr1;
}


Node* Node::getNextPtr(){
    return nextPtr;
}


Node* Node::getPrevPtr(){
    return prevPtr;
}


void Node::print(){
    cout<<"data = "<<data<<endl;
    cout<<"Previous pointer = "<< prevPtr<<endl;
    cout<<"Next pointer     = "<<nextPtr<<endl;
}