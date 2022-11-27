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
    Node<T> *link;

     // Constructors
    Node(); //default constructor
    Node(const Node<T> &node); //copy constructor
    Node(Node<T> head, T student); //student constructor

    
    // Getters
    T getData() const;
    Node<T>* getLink() const;

    // Setters
    void setData(T data);
    void setLink(Node<T>* newLink);
     

    // Overload = operator
    Node<T> &operator=(const Node &node);

};

template <class T>
using NodePtr = Node<T>*;

// LinkedList class
template<class T>
class LinkedList {
private:
    NodePtr<T> head;
    NodePtr<T> tail;

public:
    // Constructors
    LinkedList(); //default constructor
    LinkedList(const LinkedList &list); //copy constructor

    // Destructor
    ~LinkedList();

    NodePtr<T> getHead() const;
    NodePtr<T> getTail() const;

    void setHead(NodePtr<T> new_head);
    void setTail(NodePtr<T> new_tail);

    // Update Tail
    NodePtr<T> updateTail(NodePtr<T> current_head);
    // Comprare Nodes
    int CompareNodes(NodePtr<T> first, NodePtr<T> second);

    // Linked List operations 
    void insert(T student); //insert in ordered list
    bool remove(string first, string last); //remove node

    // Domestic
    void searchCGPA(float CGPA); 
    void searchApplication(int id);
    void searchResearch(int score);
    void searchName(string first, string last);

    bool removeHeadTail();
    // Linked List operations international
    //void head_insert_int(NodePtr& head, T student); //insert at head
    //void insert_int(NodePtr after_me, T student); //insert in ordered list


    //bool remove_int(NodePtr &head, int target); //remove node
    //NodePtr search_int(NodePtr head, int target); //search node

    // Print functions
    void printList(NodePtr<T> head);
    void printNode(NodePtr<T> here);

};


#endif
