//
// Created by DELL on 9/28/2024.
//
#include "functions.h"

                                     // Node Class Functionalities

Node::Node(int val)
{
    data=val;
    next=nullptr;
}

Node::~Node()                                  //Node will not delete anything
{
    cout<<"Node destructor called\n";
}

void Node::setNext(Node* nextNode)
{
    next = nextNode;
}

Node* Node::getNext( )
{
    return next;
}

void Node::setData(int dataValue)
{
    this->data = dataValue;
}

int Node::getData( )
{
    return data;
}

                                 // List Class Functionalities

List::~List()                       // List destructor will be deleting node because List created it
{
    Node *temp;
    while(head!=nullptr)           // Will iterate until the head reaches the end
    {
        temp=head;                 // Head address will be stored in pointer and will be updated according to updated head
        head=head->getNext();      // Head is shifted to next node
        delete temp;
    }
}

Node* List::getHead()
{
    return head;
}

Node* List::getTail()
{
    return tail;
}

bool List::isEmpty()
{
    return (head == nullptr);
}

void List::append(int data)
{
    Node *temp=new Node(data);
    if(head==nullptr)                // In case of no previous element
    {
        head=temp;
        tail=temp;
        count++;
    }
    else
    {
        tail->setNext(temp);         // Tail's next, means last node's next will now store temp address
        tail=temp;                   // Tail will be shifting to the temp as it has now become last element
        count++;
    }
}

void List::prepend(int data)
{
    Node * temp=new Node(data);
    if(head==nullptr)
    {
        head=temp;
        tail=temp;
        count++;
    }
    else
    {
        temp->setNext(head);          //temp's next will store the head's address, as the element is added at start so the previous head's node is now going to become 2nd element
        head=temp;                    // Now new head will be the temp i.e. recently added node
        count++;
    }
}

void List::insertAtIndex(int data, int index)
{
    int check=0;                    // To get the previous node i.e. one index before the index at which element is to be added
    Node * temp1=new Node(data);
    Node *temp=head;                       // To traverse through all elements
    if(head==nullptr && index==0)
    {
        head=temp1;
        tail=temp1;
        count++;
        return;
    }
    else
    {
        while(temp!=nullptr)
        {
            if(check==0 && index==0)                  // So that my zero index don't get missed
            {
                temp1->setNext(temp);            // Temp1's next will be the previous temp address
                temp->setNext(temp->getNext());
                head=temp1;
                count++;
                return;
            }
            else if(check+1 == index)
            {
                temp1->setNext(temp->getNext());
                temp->setNext(temp1);
                count++;
                return;
            }
            check++;
            temp=temp->getNext();
        }
    }
}

void List::deleteFromEnd()
{
    if(head==nullptr)
    {
        return;
    }
    else
    {
        Node *temp1=tail;
        Node *temp=head;
        while(temp!=nullptr)
        {
            if(head==tail)
            {
                head=nullptr;
                tail=nullptr;
                count--;
                delete temp1;
                return;
            }
            else if(temp->getNext()==tail)
            {
                temp->setNext(nullptr);
                tail=temp;
                count--;
                delete temp1;
                return;
            }
            temp=temp->getNext();
        }
    }
}

void List::deleteFromStart()
{
    if(head==nullptr)
    {
        return;
    }
    else
    {
        Node *temp=head;
        head=head->getNext();              // Updating head
        count--;
        delete temp;
    }
}

void List::deleteFromIndex(int index)
{
    if(head==nullptr)
    {
        return;
    }
    else
    {
        Node *temp=head;
        Node *temp1=head->getNext();
        int check=0;                                  // So that 0 index don't get missed
        while(temp!=nullptr)
        {
            if(check==0 && index==0)                  // In case of 1st index
            {
                head=temp1;
                delete temp;
                count--;
                return;
            }
            else if(check+1==index)
            {
                if(temp1->getNext()==nullptr)             //Last element
                {
                    temp->setNext(nullptr);
                    tail=temp;
                    delete temp1;
                    count--;
                    return;
                }
                else
                {
                    temp->setNext(temp1->getNext());      //Means address of the node which is after the one which
                                                         //is needed to be deleted
                    delete temp1;
                    count--;
                    return;
                }
            }
            check++;
            temp=temp->getNext();
            temp1=temp1->getNext();
        }
    }
}

void List::display()
{
    Node *temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->getData()<<"\n";
        temp=temp->getNext();
    }
}

void List::clear()
{
    count = 0;
    Node *temp;
    while(head!=nullptr)           // Will iterate until the head reaches the end
    {
        temp=head;                 // Head address will be stored in pointer and will be updated according to updated head
        head=head->getNext();      // Head is shifted to next node
        delete temp;
    }
}


                                        // Stack Class Functionalities

Stack::~Stack()
{
}

bool Stack::isEmpty()
{
    return list.isEmpty();          // Will be true if list exists
}

int Stack::size()
{
    return count;
}

void Stack::clear()
{
    count = 0;
    top = nullptr;
    list.clear();                             // Clear whole list of queue
}

int Stack::peek()
{
    if(isEmpty())                             // If stack doesn't exist then peak also not
    {
        return -1;
    }
    else
    {
        return top->getData();
    }
}

void Stack::push(int data)
{
    list.append(data);                         // Elements are added at end (LIFO)
    top = list.getTail();
    count++;
}

void Stack::pop()
{
    list.deleteFromEnd();                       // Elements are deleted from end(LIFO)
    top = list.getTail();
    count--;
}

void Stack::printStack()
{
    list.display();
}

void Stack::stackMain()
{
    int elementsNum,data;
    int stackSwitch;
    cout<<"\n          Welcome to Stack section\n";
    cout<<"Enter: \n"<<" 1 to add Elements\n 2 to pop Elements\n"<<" 3 to Print stack\n 4 to see size\n";
    cout<<" 5 to see peak\n 6 to check if it is empty or not\n"<<" 7 to clear stack\n";
    cin>>stackSwitch;
    switch(stackSwitch)
    {
        case 1:
        {
            cout<<"Enter the number of elements you want to add\n\n";
            cin>>elementsNum;
            for(int i = 0 ; i < elementsNum ; i++)
            {
                cout<<"Enter element "<<i+1<<"\n";
                cin>>data;
                push(data);
            }
            cout<<"The updated stack is: \n";
            printStack();
            stackMainRecalling();
            break;
        }
        case 2:
        {
            cout<<"Enter the number of elements you want to pop\n\n";
            cin>>elementsNum;
            cout<<"Stack before pop: \n";
            printStack();
            for(int i = 0 ; i < elementsNum ; i++)
            {
                pop();
            }
            cout<<"\nThe updated stack is: \n";
            printStack();
            stackMainRecalling();
            break;
        }
        case 3:
        {
            cout<<"\nThe updated stack is: \n";
            printStack();
            stackMainRecalling();
            break;
        }
        case 4:
        {
            cout<<"The size of Stack is: \n";
            cout<<size()<<"\n";
            stackMainRecalling();
            break;
        }
        case 5:
        {
            cout<<"The peak of Stack is:    [-1 in case of null stack]\n";
            cout<<peek()<<"\n";
            stackMainRecalling();
            break;
        }
        case 6:
        {
            cout<<"The current status of stack (Empty or not) is :         [1 in case of empty & 0 in other case]\n\n";
            cout<< isEmpty()<<"\n";
            stackMainRecalling();
            break;
        }
        case 7:
        {
            cout<<"Stack before clearing it is: \n";
            printStack();
            clear();
            cout<<"\nThe updated stack is: \n";
            printStack();
            stackMainRecalling();
            break;
        }
    }
}                // For Stack main maintenance

void Stack::stackMainRecalling()
{
    int option;
    cout<<"\nEnter: \n 1 if you want to return to stack section\n"<<" In other case enter any other number\n";
    cin>>option;
    if(option == 1)
    {
        stackMain();
    }
    else
    {
        return;
    }
}      // For Stack main to call in int main



                                         // Queue Class Functionalities

Queue::~Queue()
{
}

bool Queue::isEmpty()
{
    return list.isEmpty();          // Will be true if list exists
}

int Queue::size()
{
    return count;
}

void Queue::clear()
{
    count = 0;
    top = nullptr;
    list.clear();                  // Clear whole list of queue
}

int Queue::peek()
{
    if(isEmpty())                  // If queue doesn't exist then peak also not
    {
        return -1;
    }
    else
    {
        return top->getData();
    }
}

void Queue::enqueue(int data)
{
    list.append(data);           // Elements are added at end (FIFO)
    top = list.getHead();       // Top of queue is the head of list as it is the place from where elements are removed
    count++;
}

void Queue::dequeue()
{
    list.deleteFromStart();       // Elements are deleted from front (FIFO)
    top = list.getHead();
    count--;
}

void Queue::printQueue()
{
    list.display();
}

void Queue::queueMain()
{
    int elementsNum,data;
    int queueSwitch;
    cout<<"\n          Welcome to Queue section\n";
    cout<<"Enter: \n"<<" 1 to enqueue Elements\n 2 to dequeue Elements\n"<<" 3 to Print queue\n 4 to see size\n";
    cout<<" 5 to see peak\n 6 to check if it is empty or not\n"<<" 7 to clear queue\n";
    cin>>queueSwitch;
    switch(queueSwitch)
    {
        case 1:
        {
            cout<<"Enter the number of elements you want to enqueue\n\n";
            cin>>elementsNum;
            for(int i = 0 ; i < elementsNum ; i++)
            {
                cout<<"Enter element "<<i+1<<"\n";
                cin>>data;
                enqueue(data);
            }
            cout<<"The updated stack is: \n";
            printQueue();
            queueMainRecalling();
            break;
        }
        case 2:
        {
            cout<<"Enter the number of elements you want to dequeue\n\n";
            cin>>elementsNum;
            cout<<"Queue before pop: \n";
            printQueue();
            for(int i = 0 ; i < elementsNum ; i++)
            {
                dequeue();
            }
            cout<<"\nThe updated queue is: \n";
            printQueue();
            queueMainRecalling();
            break;
        }
        case 3:
        {
            cout<<"\nThe updated queue is: \n";
            printQueue();
            queueMainRecalling();
            break;
        }
        case 4:
        {
            cout<<"The size of queue is: \n";
            cout<<size()<<"\n";
            queueMainRecalling();
            break;
        }
        case 5:
        {
            cout<<"The peak of queue is:    [-1 in case of null queue]\n";
            cout<<peek()<<"\n";
            queueMainRecalling();
            break;
        }
        case 6:
        {
            cout<<"The current status of queue (Empty or not) is :         [1 in case of empty & 0 in other case]\n\n";
            cout<< isEmpty()<<"\n";
            queueMainRecalling();
            break;
        }
        case 7:
        {
            cout<<"Queue before clearing it is: \n";
            printQueue();
            clear();
            cout<<"\nThe updated queue is: \n";
            printQueue();
            queueMainRecalling();
            break;
        }
    }
}                // For Queue main maintenance

void Queue::queueMainRecalling()
{
    int option;
    cout<<"\nEnter: \n 1 if you want to return to Queue section\n"<<" In other case enter any other number\n";
    cin>>option;
    if(option == 1)
    {
        queueMain();
    }
    else
    {
        return;
    }
}      // For Queue main to call in int main
