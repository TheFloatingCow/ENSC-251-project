//list.cpp to implement linked list class

#include "list.hpp"
#include <iostream>
using namespace std;



/** ------------------Node------------------ **/

// Constructors
template<class T>
Node<T>::Node() {
    link = nullptr;
    data.setFirstName("N/A");
    data.setLastName("N/A");
    data.setCGPA(0);
    data.setResearchScore(0);
    data.setId(20220000);
} //default constructor

template<class T>
Node<T>::Node(const Node &node) {
    link = node->link;
    data = node->data;
    /*
    data.setFirstName(node.getFirstName());
    data.setLastName(node.getLastName());
    data.setCGPA(node.getCGPA());
    data.setResearchScore(node.getResearchScore());
    data.setId(node.getId());
    */
    cout << "running copy constructor" << endl;
} //copy constructor

// Get data
template<class T>
T Node<T>::getData() {
    return data;
}

// Get link
template<class T>
Node<T>* Node<T>::getLink() {
    return link;
}

// Set data
template<class T>
void Node<T>::setData(T newData) {
    data = newData;
}

// Set link
template<class T>
void Node<T>::setLink(Node<T>* newLink) {
    link = newLink;
}

// Overload = operator (calls copy constructor)
template<class T>
Node<T> &Node<T>::operator=(const Node<T> &node) {
    /*
    link = node->link;
    data.setFirstName(node.getFirstName());
    data.setLastName(node.getLastName());
    data.setCGPA(node.getCGPA());
    data.setResearchScore(node.getResearchScore());
    data.setId(node.getId());
     */
    this = Node<T>(node);
    return *this;
}


/** ------------------LinkedList------------------ **/

// Constructors
template<class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
} //default constructor

template<class T>
LinkedList<T>::LinkedList(const LinkedList &list) {
    head = nullptr;
    tail = nullptr;
} //copy constructor

// Destructor
template<class T>
LinkedList<T>::~LinkedList() {

}

// Linked List operators
// insert at head
template<class T>
void LinkedList<T>::head_insert(NodePtr &head, T student) {
    Node<T>* temp_ptr;
    temp_ptr = new Node<T>;

    temp_ptr->data = student;
    //temp_ptr.setData(student);

    temp_ptr->link = head;
    //temp_ptr.setLink(head);
    head = temp_ptr;
}

// insert in organized list
template<class T>
void LinkedList<T>::insert(NodePtr after_me, T student) {
    NodePtr temp_ptr;
    temp_ptr = new Node<T>;

    temp_ptr->getData() = student;

    temp_ptr->link = after_me->getLink();
    after_me->link = temp_ptr;
}

// remove node with student ID
template<class T>
bool LinkedList<T>::remove(NodePtr &head, int target) {
    if (head == nullptr) {
        cout << "Error: Empty list" << endl;
        return false;
    }

    if (head->getData().getId() == target) {
        NodePtr discard = head;
        head = head->link;
        delete discard;
        cout << "Student ID " << discard->getData().getId() << " has been removed" << endl;
        return true;
    }


    return true;
}


// search for node using student's ID
template<class T>
typename LinkedList<T>::NodePtr LinkedList<T>::search(NodePtr head, int target) {
    NodePtr here = head;

    if (here == nullptr) {
        return nullptr;
    }
    else {
        while (here->getData().getId() != target && here->getLink() != nullptr) {
            here = here->link;
        }
        if (here->getData().getId() == target) {
            return here;
        }
        else {
            return nullptr;
        }
    }
}

template<class T>
typename LinkedList<T>::NodePtr LinkedList<T>::printList(NodePtr head)
{
    NodePtr here = head;
    while(here != NULL)
    {
        cout << here->data.getId() << " "
        << here->data.getFirstName() << " "
        << here->data.getLastName() << " "
        << here->data.getCGPA() << " "
        << here->data.getResearchScore() << " " << endl;
        here = here->link;
    }
}

template<class T>
void LinkedList<T>::printNode(NodePtr here)
{
        cout << here->data.getId() << " "
        << here->data.getFirstName() << " "
        << here->data.getLastName() << " "
        << here->data.getCGPA() << " "
        << here->data.getResearchScore() << " " << endl;
        here = here->link;
}


// Template instantiations
template class LinkedList<DomesticStudent>;
template class LinkedList<InternationalStudent>;
