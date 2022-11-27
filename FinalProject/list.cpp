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
    //data = node->data;

    data.setFirstName(node.getFirstName());
    data.setLastName(node.getLastName());
    data.setCGPA(node.getCGPA());
    data.setResearchScore(node.getResearchScore());
    data.setId(node.getId());

    cout << "running copy constructor" << endl;
} //copy constructor

template<class T>
Node<T>::Node(Node<T> head, T student) {
    link = head;
    data = student;
} //student constructor

/*
// Get data
template<class T>
T Node<T>::getData() {
    return data;
}

// Get link
template<class T>
Node<T>* Node<T>::getLink() const{
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
 */

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

// Get head pointer
template<class T>
typename LinkedList<T>::NodePtr LinkedList<T>::getHead() const{
    return *head;
}

// Linked List operators
// insert at head
template<class T>
void LinkedList<T>::head_insert(NodePtr head, T student) {
    cout << "running head_insert..." << endl;
    NodePtr temp_ptr;
    temp_ptr = new Node<T>;

    temp_ptr->data = student;
    cout << "temp data is student" << endl;

    temp_ptr->link = head;
    cout << "temp link is head" << endl;

    head = temp_ptr;
    cout << "completed head_insert" << endl;
}

// insert in organized list
template<class T>
void LinkedList<T>::insert(NodePtr after_me, T student) {
    NodePtr temp_ptr;
    temp_ptr = new Node<T>;

    temp_ptr->data = student;

    temp_ptr->link = after_me->link;
    after_me->link = temp_ptr;
}

/*
// insert at head International
template<class T>
void LinkedList<T>::head_insert_int(NodePtr& head, T student) {
    Node<T>* temp_ptr;// = new Node<T>(student);
    temp_ptr = new Node<T>;

    temp_ptr->data = student;
    cout << "temp data is student" << endl;

    temp_ptr->link = head;
    cout << "temp link is head" << endl;

    head = temp_ptr;
    cout << "completed head_insert" << endl;
}

// insert in organized list International
template<class T>
void LinkedList<T>::insert_int(NodePtr after_me, T student) {
    NodePtr temp_ptr;
    temp_ptr = new Node<T>;

    temp_ptr->data = student;

    temp_ptr->link = after_me->link;
    after_me->link = temp_ptr;
}
*/

// remove node with student ID
template<class T>
bool LinkedList<T>::remove(NodePtr &head, string first, string last) {
    

    while(head != nullptr)
    {
        if (head == nullptr) {
        cout << "Error: Empty list" << endl;
        return false;
        }

        if ((head->data.getFirstName() == first) && (head->data.getLastName() == last)){
            NodePtr discard = head;
            head = head->link;
            delete discard;
            cout << "Applicant " << discard->data.getFirstName() << " " << discard->data.getLastName() << " has been removed" << endl;
            return true;
        }
        head = head->link;
    }

    return true;
}

template<class T>
bool LinkedList<T>::removeHead(NodePtr &head) {
    

    //Traverse until tail where next pointer is null
    if(head != NULL)
    {
        NodePtr discard = head;
        head = head->link;
        delete discard;
        cout << "Top listed applicant has been deleted" << endl;
        return true;
    }
    else{
        cout <<"No applicant to delete" << endl;
        return false;
    }

}

template<class T>
bool LinkedList<T>::removeTail(NodePtr &head) {
    

    //Traverse until tail where next pointer is null
    while(head != nullptr)
    {
        if (head->link == NULL) {
        delete head;
        cout << "Bottom listed applicant deleted" << endl;
        return true;
        }else
        {
        head = head->link;
        }
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
        while (here->data.getId() != target && here->link != nullptr) {
            here = here->link;
        }
        if (here->data.getId() == target) {
            return here;
        }
        else {
            return nullptr;
        }
    }
}

template<class T>
typename LinkedList<T>::NodePtr LinkedList<T>::searchCGPA(NodePtr head, float target) {
    NodePtr here = head;

    if (here == nullptr) {
        return nullptr;
    }
    else {
        while (here->data.getId() != target && here->link != nullptr) {
            here = here->link;
        }
        if (here->data.getId() == target) {
            return here;
        }
        else {
            return nullptr;
        }
    }
}

template<class T>
void LinkedList<T>::printList(NodePtr head)
{
    NodePtr here = head;
    while(here != nullptr)
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
