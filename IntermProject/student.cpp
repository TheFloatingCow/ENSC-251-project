//student.cpp to implement your classes
#include "student.hpp"


//constructors
Student::Student() {

} //default constructor

Student::Student(const string &firstName, const string &lastName, const float &CGPA, const int &researchScore,
                 const int &id) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->CGPA  = CGPA;
    this->researchScore = researchScore;
    this->id = id;
} //non-default constructor

Student::Student(const Student& s) {
    this->firstName = s.firstName;
    this->lastName = s.lastName;
    this->CGPA  = s.CGPA;
    this->researchScore = s.researchScore;
    this->id = s.id;
} //copy constructor
