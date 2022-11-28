//list.cpp to implement linked list class

#include "list.hpp"
using namespace std;


// Helper Function Declarations
template <class T>
bool compareName(NodePtr<T> node, string first, string last);
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
    data.setHome("N/A");
    data.setType(true);
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


// Get data
template<class T>
T Node<T>::getData() const{
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

    NodePtr<T> temp;
    for(temp = list.head; temp != nullptr; temp = temp->link){
        insert(temp->data);
    }
} //copy constructor

// Destructor
template<class T>
LinkedList<T>::~LinkedList() {
    NodePtr<T> temp1;
    NodePtr<T> temp2;

    temp1 = head;
    while(temp1 != nullptr){
        temp2 = temp1;
        temp1 = temp1->link;

        temp2->link = nullptr;
        delete temp2;
    }
}

// Get head pointer
template<class T>
NodePtr<T> LinkedList<T>::getHead() const{
    return head;
}

// Get tail pointer
template<class T>
NodePtr<T> LinkedList<T>::getTail() const{
    return tail;
}


// set head pointer
template<class T>
void LinkedList<T>::setHead(NodePtr<T> new_head){
    if(new_head == nullptr){
        std::cout << "ERROR, HEAD CANNOT BE NULLPTR\n";
        return;
    }
    new_head->link = head;
    head = new_head;
}

// set tail pointer
template<class T>
void LinkedList<T>::setTail(NodePtr<T> new_tail){
    NodePtr<T> temp = head;
    while(temp->link != nullptr){
        temp = temp->link;
    }
    temp->link = new_tail;
}

// Update Tail
template <class T>
NodePtr<T> LinkedList<T>::updateTail(NodePtr<T> current_head){
    NodePtr<T> temp = current_head;
    while(temp->link != nullptr){
        temp = temp->link;
    }

    return temp;
}

// Compare Nodes (first > second == 1) else 0
template <class T>
int LinkedList<T>::CompareObjects(NodePtr<T> first, NodePtr<T> second){
    int output = 0;
    // std::cout << first->data.getHome() << "\n";
    if(first->data.getResearchScore() > second->data.getResearchScore()){
        output = 1;
    } else if(first->data.getResearchScore() == second->data.getResearchScore()){
        // check cgpa
        if(first->data.getCGPA() > second->data.getCGPA()){
            output = 1;
        } else if(first->data.getCGPA() == second->data.getCGPA()){
            // check if both domestic || both internatial/ different
            // both domestic
            if(first->data.getType() == second->data.getType()){
                // check province or country 
                if(first->data.getHome() < second->data.getHome()){
                    output = 1;
                }
            } else { // different types
                // put domestic higher than international
                if(first->data.getType() == true){
                    output = 1;
                }
            }
        }
    }

    return output;
}

template <class T>
bool LinkedList<T>::insert(T student){ //insert in ordered list
    if (!validCheck(student)) {
        return false;
    }
    // throws exception if bad alloc
    try {
        // new pointer
        NodePtr<T> new_student = new Node<T>;
        new_student->data = student;

        // if linked list is empty node = head
        if(head == nullptr){
            head = new_student;
        } else {
            // insert in overall sorted order
            // research, cgpa, (province, country)
            NodePtr<T> current = head;

            while(current->link != nullptr && (CompareObjects(current->link,new_student) == 1)){
                current = current->link;
            }

            // set new head or insert into list
            if(CompareObjects(new_student,head)){
                new_student->link = head;
                head = new_student;
            } else {
                new_student->link = current->link;
                current->link = new_student;
            }
        }

        // Update tail
        tail = updateTail(head);
        return true;
    }
    catch (const bad_alloc & exception) {
        cout << "Error: Bad alloc. " << exception.what();
        return false;
    }
}

template <class T>
bool LinkedList<T>::remove(string first, string last){
    try {
        NodePtr<T> current = head;
        NodePtr<T> prev = nullptr;

        // Delete Head
        if (current != nullptr && (compareName(current, first, last))) {
            head = head->link;
            delete current;
            std::cout << "Delete\n";
            return true;
        } else {
            while (current != nullptr && !(compareName(current, first, last))) {
                prev = current;
                current = current->link;
            }

            //key not in list
            if (current == nullptr) {
                std::cout << "Not in Linked List\n";
                return false;
            }

            // found current
            // unlink
            prev->link = current->link;
            delete current;
            std::cout << "Deleted\n";

            // update tail
            tail = updateTail(head);
            return true;
        }
    }
    catch (const exception&) {
        return false;
    }
}

template <class T>
bool LinkedList<T>::searchCGPA(float CGPA){
    if (CGPA > 4.33 || CGPA < 0) {
        return false;
    }
    int counter = 0;
    for(NodePtr<T> current = head; current != nullptr; current = current->link){
        if(current->data.getCGPA() == CGPA){
            printNode(current);
            counter++;
        }
    }

    if(counter == 0){
        cout << "No Matching Students\n";
        return false;
    }

    return true;
}

template <class T>
bool LinkedList<T>::searchApplication(int id){
    if (id < 0) {
        return false;
    }
    int counter = 0;
    for(NodePtr<T> current = head; current != nullptr; current = current->link){
        if(current->data.getId() == id){
            printNode(current);
            counter++;
        }
    }

    if(counter == 0){
        cout << "No Matching Students\n";
        return false;
    }

    return true;
}

template <class T>
bool LinkedList<T>::searchResearch(int score){
    if (score > 100 || score < 0) {
        return false;
    }
    int counter = 0;
    for(NodePtr<T> current = head; current != nullptr; current = current->link){
        if(current->data.getResearchScore() == score){
            printNode(current);
            counter++;
        }
    }

    if(counter == 0){
        cout << "No Matching Students\n";
        return false;
    }

    return true;
}

template <class T>
bool LinkedList<T>::searchName(string first, string last){
    int counter = 0;
    for(NodePtr<T> current = head; current != nullptr; current = current->link){
        if(current->data.getFirstName() == first && current->data.getLastName() == last){
            printNode(current);
            counter++;
        }
    }

    if(counter == 0){
        cout << "No Matching Students\n";
        return false;
    }

    return true;
}

template <class T>
bool LinkedList<T>::thresholdCGPA(float CGPA){
    if (CGPA > 4.33 || CGPA < 0) {
        return false;
    }
    int counter = 0;
    for(NodePtr<T> current = head; current != nullptr; current = current->link){
        if(current->data.getCGPA() >= CGPA){
            printNode(current);
            counter++;
        }
    }

    if(counter == 0){
        cout << "No Students Above CGPA " << CGPA << endl;
        return false;
    }
    return true;
}

template <class T>
bool LinkedList<T>::thresholdResearch(int score){
    if (score > 100 || score < 0) {
        return false;
    }
    int counter = 0;
    for(NodePtr<T> current = head; current != nullptr; current = current->link){
        if(current->data.getResearchScore() >= score){
            printNode(current);
            counter++;
        }
    }

    if(counter == 0){
        cout << "No Students Above Research Score " << score << endl;;
        return false;
    }
    return true;
}

template <class T>
void LinkedList<T>::threshold(float CGPA,int score){
    int counter = 0;
    for(NodePtr<T> current = head; current != nullptr; current = current->link){
        if(current->data.getCGPA() >= CGPA && current->data.getResearchScore() >= score){
            printNode(current);
            counter++;
        }
    }

    if(counter == 0){
        cout << "No Students Above CGPA " << CGPA << endl;
    }
}

template <class T>
bool LinkedList<T>::removeHead(){
    if(head == nullptr){
        return false;
    }
    NodePtr<T> temp = head;
    head = head->link;
    delete temp;
    return true;
}

template <class T>
bool LinkedList<T>::removeTail(){
    if(head == nullptr){
        return false;
    }
    // head is tail
    if(head->link == nullptr){
        delete head;
        return true;
    }
    //Traverse until tail where next pointer is null
    NodePtr<T> temp = head;
    while(temp->link->link != nullptr){
        temp = temp->link;
    }
    //Delete once reached the bottom of list
    delete temp->link;
    temp->link = nullptr;
    std::cout<<"Bottom listed applicant deleted\n";
    return true;

}

template<class T>
bool LinkedList<T>::removeHeadTail() {
    bool output = false;
    if(this->removeHead() && this->removeTail()){
        return true;
    }
    return false;
}

// Check if student values are valid
template<class T>
bool LinkedList<T>::validCheck(T student) {
    // Valid countries and provinces
    string validCountries[5] = {"Canada", "China", "India", "Iran", "Korea"};
    string validProvinces[13] = {"NL", "PE", "NS", "NB", "QC", "ON", "MB", "SK", "AB", "BC", "YT", "NT", "NU"};

    if (student.getFirstName().empty()) {
        return false;
    }
    if (student.getLastName().empty()) {
        return false;
    }
    if (student.getCGPA() > 4.33 || student.getCGPA() < 0) {
        return false;
    }
    if (!student.getResearchScore() || student.getResearchScore() > 100 || student.getResearchScore() < 0) {
        return false;
    }
    if (!student.getId() || student.getId() < 0) {
        return false;
    }
    if (student.getHome().empty()) {
        return false;
    }
    if (student.getType()) { // domestic
        if (!stringCompare(student.getHome(),  validProvinces, sizeof(validProvinces)/sizeof(validProvinces[0]))) {
            return false;
        }
    }
    else { // international
        if (typoCheck(student.getHome(), validCountries).empty()) {
            if (!stringCompare(student.getHome(), validCountries, sizeof(validCountries)/sizeof(validCountries[0]))) {
                return false;
            }
        }
    }
    return true;
}


template<class T>
void LinkedList<T>::printList(NodePtr<T> head)
{
    if(head == nullptr){
        std::cout << "List has not been created yet\n";
        return;
    }
    NodePtr<T> here = head;
    while(here != nullptr)
    {
        //<< here->data.getId() << " "
        if(here->data.getType() == true){
            cout << "Domestic ";
        } else if(here->data.getType() == false){
            cout << "International ";
        } 
        cout << here->data.getFirstName() << " "
        << here->data.getLastName() << " "
        << here->data.getHome() << " "
        << here->data.getCGPA() << " "
        << here->data.getResearchScore() << " "
        << here->data.getId() << " " << endl;
        here = here->link;
    }
}

template<class T>
void LinkedList<T>::printNode(NodePtr<T> here)
{
         //<< here->data.getId() << " "
        if(here->data.getType() == true){
            cout << "Domestic ";
        } else if(here->data.getType() == false){
            cout << "International ";
        } 
        cout << here->data.getFirstName() << " "
        << here->data.getLastName() << " "
        << here->data.getHome() << " "
        << here->data.getCGPA() << " "
        << here->data.getResearchScore() << " "
        << here->data.getId() << " " << endl;
        here = here->link;
}

// Helper Functions 
template <class T>
bool compareName(NodePtr<T> node, string first, string last){
    if(node->getData().getFirstName() == first){
        if(node->getData().getLastName() == last){
            return true;
        }
    }
    return false;
}


// Template instantiations
template class LinkedList<DomesticStudent>;
template class LinkedList<InternationalStudent>;
template class LinkedList<Student>;
