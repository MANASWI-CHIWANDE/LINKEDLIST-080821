#include <iostream>
#include "./node.cpp"

using namespace std;

class CircularLinkedlist
{
private:
    int length = 0;
    Node *head = NULL;
    Node *traverse(int);

public:
    CircularLinkedlist();

    Node *getHead();

    void print();

    int append(int);

    int prepend(int);

    int insert(int, int);

    int dElete(int);

    int update(int, int);

    int countNode();
};

CircularLinkedlist::CircularLinkedlist()
{
    head = NULL;
}


Node *CircularLinkedlist::getHead()
{
    return head;
}


Node *CircularLinkedlist::traverse(int index)
{
    Node *temp = head;
    while (temp->getNextPtr() != head)
    {
        temp = temp->getNextPtr();
    }
    return temp;
}


void CircularLinkedlist::print()
{

    cout << "HEAD ADDRESS OF THE LINKED LIST IS : " << getHead() << endl;
    if (getHead() == NULL)
    {
        cout << "\nLInked List is EMPTY\n"
             << endl;
    }
    else
    {
        cout << "\nPrinting Circular Linked List" << endl;
        Node *current = head;
        while (current->getNextPtr() != head)
        {
            cout << "( " << current->getData() << " , " << current->getNextPtr() << " ) => ";
            current = current->getNextPtr();
        }
        cout << "( " << current->getData() << " , " << current->getNextPtr() << " ) = x " << endl;

        cout << "Finished Printing \n"
             << endl;
    }
}


int CircularLinkedlist::append(int data)
{

    if (head == NULL)
    {
        head = new Node(data);
        head->setNextPtr(head);

        length++;
        return 1;
    }
    else
    {
        Node *temp    = traverse(length);
        Node *newNode = new Node(data);
        temp->setNextPtr(newNode);
        newNode->setNextPtr(head);
        length++;
        return 1;
    }
}


int CircularLinkedlist::prepend(int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        head->setNextPtr(head);

        length++;
        return 1;
    }
    else
    {
        Node *temp    = traverse(length);
        Node *newNode = new Node(data);
        temp->setNextPtr(newNode);
        newNode->setNextPtr(head);
        head = newNode;
        length++;
        return 1;
    }
}


int CircularLinkedlist::insert(int data1, int data2)
{
    Node *ptr = head;
    while (ptr->getData() != data1)
    {
        ptr = ptr->getNextPtr();
    }

    Node *temp    = ptr->getNextPtr();
    Node *newNode = new Node(data2);
    newNode->setNextPtr(temp);
    ptr->setNextPtr(newNode);
    length++;
    return 1;
}


int CircularLinkedlist::dElete(int data1)
{
    if (head->getData() == data1)
    {
        if (head->getNextPtr() == head)
        {
            head->setNextPtr(NULL);
            head = NULL;

            length--;
            return 1;
        }
        else
        {
            Node *ptr = traverse(length);
            ptr->setNextPtr(head->getNextPtr());
            head = head->getNextPtr();

            length--;
            return 1;
        }
    }
    else
    {
        Node *temp       = NULL;
        Node *prevptr    = head;
        Node *currentptr = head->getNextPtr();

        while (currentptr != NULL)
        {
            if (currentptr->getData() == data1)
            {
                temp       = currentptr;
                currentptr = NULL;
            }
            else
            {
                prevptr    = prevptr->getNextPtr();
                currentptr = currentptr->getNextPtr();
            }
        }

        if (temp != NULL)
        {
            prevptr->setNextPtr(temp->getNextPtr());
        }
        length--;

        return 1;
    }
}


int CircularLinkedlist::update(int data1, int data2)
{
    Node *current = head;
    while (current->getData() != data1)
    {
        current = current->getNextPtr();
    }
    current->setData(data2);

    return 0;
}


int CircularLinkedlist::countNode()
{
    cout << "\nLength of the LINKED LIST is : " << length << "\n"
         << endl;
    return 1;
}