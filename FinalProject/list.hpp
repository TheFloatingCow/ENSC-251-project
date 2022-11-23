// header file list.hpp to declare linked list class
#ifndef Linked_List_HG
#define Linked_List_HG

#include <iostream>
#include "student.hpp"
using namespace std; //use namespace std

namespace ENSC251_Final {

    template<typename T>
    struct Node {
        T data;
        Node *link;
    };

    template<typename T>
    class LinkedList {
        typedef Node<T>* NodePtr;

    private:
        NodePtr *head;

    public:
        // Constructors
        LinkedList(); //default constructor
        LinkedList(const LinkedList &list); //copy constructor

        // Destructor
        ~LinkedList();

        // Linked List operations
        void head_insert(NodePtr &head, T student); //insert at head
        void insert(NodePtr after_me, T student); //insert in ordered list
        void remove(int target); //remove node
        //NodePtr search(NodePtr head, int target); //search node

    };
}
#endif