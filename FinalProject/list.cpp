//list.cpp to implement linked list class

#include "list.hpp"
#include <iostream>
using namespace std;

namespace ENSC251_Final {

    // Constructors
    template<class T>
    LinkedList<T>::LinkedList() {
        head = nullptr;
    } //default constructor

    template<class T>
    LinkedList<T>::LinkedList(const LinkedList &list) {
        head = nullptr;
    } //copy constructor

    // Destructor
    template<typename T>
    LinkedList<T>::~LinkedList() {

    }

    // Linked List operators
    // insert at head
    template<typename T>
    void LinkedList<T>::head_insert(NodePtr &head, T student) {
        return;
    }

    // insert in organized list
    template<typename T>
    void LinkedList<T>::insert(NodePtr after_me, T student) {
        return;
    }

    // remove node
    template<typename T>
    void LinkedList<T>::remove(int target) {
        return;
    }

    /**
    // search for node
    template<typename T>
    NodePtr LinkedList<T>::search(NodePtr head, int target) {
        return head;
    }
    something going on here thats not supposed to happen **/

    // Template instantiations
    template
    class LinkedList<DomesticStudent>;

    template
    class LinkedList<InternationalStudent>;

}