#include <iostream>
using namespace std;
#include "./node.cpp"

class SinglyLinkedList{

    private:

        Node*   head   = NULL;
        int     length = 0;
        Node *  traverse(int);

    public:
        
        SinglyLinkedList();

        SinglyLinkedList(Node* );

        Node* getHead();

        int  append(int);

        int  prepend(int);

        int  insert(int,int);

        int  dElete(int);

        int  updateNode(int ,int );

        int  countNode();

        void print();

        
};


SinglyLinkedList::SinglyLinkedList(){
    head = NULL;
}


Node* SinglyLinkedList::getHead(){

    return head;
}


void SinglyLinkedList::print(){
    cout<<"\nPrinting Singly Linked List"<<endl;
    Node *current = head;
    while(current->getNextPtr()!= NULL){
        cout<<"( "<< current->getData()<<" , " << current->getNextPtr() << " ) => ";
        current = current->getNextPtr();
    }
    cout<<"( "<< current->getData()<<" , " << current->getNextPtr() << " ) = x "<<endl;

    cout<<"Finished Printing \n"<<endl;


}


/*
*Function Traverses linked list and gives the pointer to 
*last node
*/
Node* SinglyLinkedList::traverse(int index1){

    Node* current = head;

    while(current->getNextPtr()!= NULL){
        current = current->getNextPtr();
    }
    return current;
   
}


int SinglyLinkedList:: append(int data){

    if(head == NULL){

        head = new Node(data);
        length++;
        return 1;

    }
    else{

        Node *lastPtr = traverse(length);
        Node* newNode = new Node(data);
        lastPtr->setNextPtr(newNode);
        length++;
        return 1;
    }

    return 0;
}


int SinglyLinkedList::prepend(int data){

    Node*lastptr = head;
    Node* newNode = new Node(data);
    newNode->setNextPtr(head);
    head = newNode;
    length ++;
    
    return 1;
    
}


int SinglyLinkedList::insert(int data1 ,int data2){
    Node *current= head;
    while(current->getData() != data1){
        current= current->getNextPtr();
    }
    Node* newNode= new Node(data2);
    newNode->setNextPtr(current->getNextPtr()) ;
    current->setNextPtr(newNode);

    length++;

    return 0;

}


int SinglyLinkedList::dElete(int data)
{
    if(head->getData() == data)
    {
        head = head->getNextPtr();
        length--;
        return 1;
    }
    else
    {
        Node* temp = NULL;
        Node* prevptr    = head;
        Node* currentptr = head->getNextPtr();

        while(currentptr!=NULL){
            if(currentptr->getData()==data){
                temp       = currentptr;
                currentptr =NULL;
            }
            else{
                prevptr    = prevptr->getNextPtr();
                currentptr = currentptr->getNextPtr();
            }
        }

        if(temp != NULL){
            prevptr->setNextPtr(temp->getNextPtr());
        }
        length--;

        return 1;
    }

    return 0;

}


int SinglyLinkedList::updateNode(int data1 ,int data2){
    Node*current = head;
    while(current->getData() != data1 ){
        current= current->getNextPtr();
    }
    current->setData(data2);

    return 0;

}


int SinglyLinkedList::countNode(){
    cout<<"\nLength of the LINKED LIST is : "<<length<<"\n"<<endl;
    return 0;
}