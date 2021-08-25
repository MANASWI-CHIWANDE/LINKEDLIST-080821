#include <iostream>
using namespace std;

class Node
{

private:
    int data;
    Node *nextPtr;

public:
    Node();

    Node(int);

    void setData(int k);

    int getData();

    Node* getNextPtr();

    void setNextPtr(Node *);

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

Node* Node::getNextPtr(){
    return nextPtr;
}

void Node::print(){
    cout<<"data = "<<data<<endl;
    cout<<"pointer = "<< nextPtr<<endl;
}
