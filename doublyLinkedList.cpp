#include <iostream>
#include "./node1.cpp"
using namespace std;

class DoublyLinkedlist
{
private:

    Node *head;
    int   length = 0;
    Node *traverse(int);

public:

    DoublyLinkedlist();

    Node *getHead();

    int   append(int);

    int   prepend(int);

    int   insert(int, int);

    int   dElete(int);

    int   updateNode(int, int);

    int   countNode();

    void  print();

};

DoublyLinkedlist::DoublyLinkedlist()
{
    head = NULL;
}


Node *DoublyLinkedlist::getHead()
{
    return head;
}


void DoublyLinkedlist::print()
{
    cout << "\nADDRESS OF HEAD POINTER : " << getHead() << endl;
    if (getHead() == NULL)
    {
        cout << "\nLInked List is EMPTY\n"
             << endl;
    }
    else
    {
        cout << "\nPrinting Doubly Linked List\n" << endl;
        Node *current = head;
        while (current->getNextPtr() != NULL)
        {
            cout << "( " << current->getPrevPtr() << "  ,  " << current->getData() << "  ,  " << current->getNextPtr() << " ) <=> ";
            current = current->getNextPtr();
        }
        cout << "( " << current->getPrevPtr() << "  ,  " << current->getData() << " , " << current->getNextPtr() << " ) <= x " << endl;

        cout << "\nFinished Printing \n"
             << endl;
    }
}


Node *DoublyLinkedlist::traverse(int length)
{
    Node *temp = head;
    while (temp->getNextPtr() != NULL)
    {
        temp = temp->getNextPtr();
    }
    return temp;
}


int DoublyLinkedlist::append(int data1)
{

    /*
       for appending first node of the linked list
    */   
    if (head == NULL)
    {
        Node *newNode = new Node(data1);              
        head = newNode;
        length++;
        return 1;
    }

    /*
       for appending node 
    */ 
    else
    {
        Node *ptr = traverse(length);
        Node *newNode = new Node(data1);
        ptr->setNextPtr(newNode);
        newNode->setPrevPtr(ptr);
        length++;
        return 1;
    }
}


int DoublyLinkedlist::prepend(int data1)
{
    /*
       for prepending first node of the linked list
    */ 
    if (head == NULL)
    {
        Node *newNode = new Node(data1);
        head = newNode;
        length++;
        return 1;
    }

    /*
       for prepending node 
    */ 
    else
    {
        Node *newNode = new Node(data1);
        head->setPrevPtr(newNode);
        newNode->setNextPtr(head);
        newNode->setPrevPtr(NULL);
        head = newNode;
        length++;
        return 1;
    }
}


int DoublyLinkedlist::insert(int data1, int data2)
{
    Node *ptr = head;
    Node *nextPtr = head->getNextPtr();

    while (ptr->getData() != data1)
    {
        ptr = ptr->getNextPtr();
        nextPtr = nextPtr->getNextPtr();
    }

    Node *newNode = new Node(data2);

    ptr->setNextPtr(newNode);
    newNode->setPrevPtr(ptr);
    newNode->setNextPtr(nextPtr);
    nextPtr->setPrevPtr(newNode);
    length++;
    return 0;
}


int DoublyLinkedlist::dElete(int data1)
{
    if (head->getData() == data1)
    {
        /*
          for deleting node of linked list with only single node
        */
        if (head->getNextPtr() == NULL)
        {
            head = NULL;
            length--;
            return 1;
        }
        /*
          for deleting first node of linked list 
        */
        else
        {
            Node *current = head->getNextPtr();
            head->setNextPtr(NULL);
            current->setPrevPtr(NULL);
            head          = current;
            length--;
            return 1;
        }
    }
    else
    {
        Node *temp = NULL;
        Node *prevptr = head;
        Node *currentptr = head->getNextPtr();

        while (currentptr != NULL)
        {
            if (currentptr->getData() == data1)
            {
                temp = currentptr;
                currentptr = NULL;
            }
            else
            {
                prevptr = prevptr->getNextPtr();
                currentptr = currentptr->getNextPtr();
            }
        }
        
        /*
          for deleting node in between two nodes
        */
        if (temp->getNextPtr() != NULL)
        {
            prevptr->setNextPtr(temp->getNextPtr());
            (temp->getNextPtr())->setPrevPtr(prevptr);

            length--;
            return 1;
        }
        /*
          for deleting node at the end
        */
        else
        {
            prevptr->setNextPtr(temp->getNextPtr());
            length--;
            return 1;
        }
    }
    return 0;
}


int DoublyLinkedlist::updateNode(int data1, int data2)
{
    Node *current = head;
    while (current->getData() != data1)
    {
        current = current->getNextPtr();
    }
    current->setData(data2);

    return 0;
}


int DoublyLinkedlist::countNode()
{
    cout << "\nLength of the LINKED LIST is : " << length << "\n"
         << endl;
    return 0;
}
