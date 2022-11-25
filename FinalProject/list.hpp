// header file list.hpp to declare linked list class
#ifndef Linked_List_HG
#define Linked_List_HG

#include <iostream>
#include "student.hpp"
using namespace std; //use namespace std

// Node class
template<class T>
class Node {
public:
    T data;
    Node *link;

    // Constructors
    Node(); //default constructor
    Node(const Node &node); //copy constructor
    Node(Node<T> head, T student); //student constructor

    /*
    // Getters
    T getData() const;
    Node<T>* getLink() const;

    // Setters
    void setData(T data);
    void setLink(Node<T>* newLink);
     */

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

    NodePtr getHead() const;

    // Linked List operations domestic
    void head_insert(NodePtr head, T student); //insert at head
    void insert(NodePtr after_me, T student); //insert in ordered list
    bool remove(NodePtr &head, string first, string last); //remove node
    bool removeTail(NodePtr &head); //remove tail node
    NodePtr search(NodePtr head, int target); //search node
    NodePtr searchCGPA(NodePtr head, float target); //search by CGPA

    // Linked List operations international
    //void head_insert_int(NodePtr& head, T student); //insert at head
    //void insert_int(NodePtr after_me, T student); //insert in ordered list


    //bool remove_int(NodePtr &head, int target); //remove node
    //NodePtr search_int(NodePtr head, int target); //search node

    // Print functions
    void printList(NodePtr head);
    void printNode(NodePtr here);

};


#endif