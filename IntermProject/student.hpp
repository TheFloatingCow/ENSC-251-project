//header file student.hpp to declare your classes
#ifndef Student_HG
#define Student_HG

using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class Student {
private:
    string firstName;
    string lastName;
    float CGPA;
    int researchScore;
    int id;

public:
    // Constructors
    Student(); //default constructor
    Student(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const int& id); //non-default constructor
    Student(const Student& s); //copy constructor

};


#endif