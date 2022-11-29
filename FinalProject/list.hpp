// header file list.hpp to declare linked list class
#ifndef Linked_List_HG
#define Linked_List_HG

#include <iostream>
#include "student.hpp"
#include "validCheck.hpp"
#include "toeflscore.hpp"
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
    int CompareObjects(NodePtr<T> first, NodePtr<T> second);

    // Linked List operations 
    bool insert(T student); //insert in ordered list
    bool remove(string first, string last); //remove node

    // Search functions
    bool searchCGPA(float CGPA);
    bool searchApplication(int id);
    bool searchResearch(int score);
    bool searchName(string first, string last);

    // Threshold functions
    bool thresholdCGPA(float CGPA);
    bool thresholdResearch(int score);
    void threshold(float CGPA, int score);

    // Remove functions
    bool removeHead();
    bool removeTail();
    bool removeHeadTail();

    // Check if student info is valid
    //bool validCheck(T student);
    bool validCheck(T student);

    // Print functions
    void printList(NodePtr<T> head);
    void printNode(NodePtr<T> here);

    // Average functions
    float averageCGPA();
    float averageResearch();

};


#endif
