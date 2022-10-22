//header file student.hpp to declare your classes
#ifndef Student_HG
#define Student_HG

using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class Student {
public:
    string firstName;
    string lastName;
    float CGPA;
    int researchScore;
    int id;

    // Constructors
    Student(); //default constructor
    Student(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const int& id); //non-default constructor
    Student(const Student& s); //copy constructor

    // Friend functions
    friend int compareCGPA(const Student& stu1, const Student& stu2);
    friend int compareResearchScore(const Student& stu1, const Student& stu2);
    friend int compareFirstName(const Student& stu1, const Student& stu2);
    friend int compareLastName(const Student& stu1, const Student& stu2);
};

class DomesticStudent : public Student
{
    string province;
};

class InternationalStudent : public Student
{
    string country;
};

#endif