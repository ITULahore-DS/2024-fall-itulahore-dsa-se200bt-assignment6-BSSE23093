//
// Created by DELL on 9/28/2024.
//

#ifndef INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23093_FUNCTIONS_H
#define INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23093_FUNCTIONS_H
#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
public:
    Node()
    {
        data=0;
        next=nullptr;
    }
    Node(int val);
    ~Node();
    void setNext(Node* nextNode);  //Sets the next pointer to the provided node.
    Node* getNext();         //Returns the next node pointer.
    void setData(int dataValue);    //Sets the data of the node.
    int getData();           //Returns the data of the node.
};

class List
{
    Node *head;
    Node *tail;
    int count;
public:
    List()
    {
        head=nullptr;
        tail=nullptr;
        count=0;
    }              //Initializes the linked list with head, tail, and count set to nullptr or 0.
    ~List();           //Ensures all nodes are properly deleted when the list is destroyed.
    bool isEmpty();           //Returns true if the list is empty, otherwise false.
    void append(int data);     //Adds a new node with the given data at the end of the list.
    void prepend(int data);      // Adds a new node with the given data at the start of the list.
    void insertAtIndex(int data, int index);   // Inserts a node with the given data at the specified index.
    void deleteFromEnd(); // Deletes the last node in the list.
    void deleteFromStart(); // Deletes the first node in the list.
    void deleteFromIndex(int index); // Deletes the node at the specified index.
    Node* getHead( );
    Node* getTail();
    void display();
    void clear();
};

class Stack
{
    List list;
    Node *top;
    int count;
public:
    Stack()
    {
        top = nullptr;
        count = 0;
    }
    ~Stack();
    bool isEmpty();
    void push(int data);            // Push data at tail/top of stack list
    int size();
    int peek();
    void pop();                    // Pop the list from tail
    void clear();                  // delete all stack list elements
    void printStack();
    void stackMain();              // For main maintenance
    void stackMainRecalling();     // For stack main to call in int main
};

class Queue
{
    List list;
    Node *top;
    int count;
public:
    Queue()
    {
        top = nullptr;
        count = 0;
    }
    ~Queue();
    bool isEmpty();
    void enqueue(int data);      // Add element to last node
    void dequeue();              // Remove element from first index
    void clear();                // Delete whole queue
    int peek();                  // Data of front node(top)
    int size();
    void printQueue();
    void queueMain();             // For Queue main maintenance
    void queueMainRecalling();    // For Queue main to call in int main
};



#endif //INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23093_FUNCTIONS_H
