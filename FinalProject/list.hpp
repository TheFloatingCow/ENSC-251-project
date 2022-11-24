// header file list.hpp to declare linked list class
#ifndef Linked_List_HG
#define Linked_List_HG

#include <iostream>
#include "student.hpp"
using namespace std; //use namespace std

// Node class
template<class T>
class Node {
private:

public:
    T data;
    Node *link;

    // Constructors
    Node(); //default constructor
    Node(const Node &node); //copy constructor

    // Getters
    T getData();
    Node<T>* getLink();

    // Setters
    void setData(T data);
    void setLink(Node<T>* newLink);

    // Overload = operator
    Node<T> &operator=(const Node &node);

};


// LinkedList class
template<class T>
class LinkedList {
    typedef Node<T>* NodePtr;

private:
    NodePtr *head;
    NodePtr *tail;

public:
    // Constructors
    LinkedList(); //default constructor
    LinkedList(const LinkedList &list); //copy constructor

    // Destructor
    ~LinkedList();

    // Linked List operations
    void head_insert(NodePtr &head, T student); //insert at head
    void insert(NodePtr after_me, T student); //insert in ordered list
    bool remove(NodePtr &head, int target); //remove node
    NodePtr search(NodePtr head, int target); //search node

    // Print functions
    NodePtr printList(NodePtr head);
    void printNode(NodePtr here);

};


#endif