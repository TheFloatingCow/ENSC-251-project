//header file student.hpp to declare your classes
#ifndef Student_HG
#define Student_HG


#include <string> //you will have to use string in C++
#include <iostream>
#include "toeflscore.hpp"
using namespace std; //use namespace std

class Student
{
protected:
    // Variables
    string firstName;
    string lastName;
    float CGPA;
    int researchScore;
    int id;
    string home;
    bool type; // true->domestic; false->international
public:
    

    // Constructors
    Student(); //default constructor
    Student(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore);
    Student(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const string& home); //non-default constructor without id
    Student(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const int& id); //non-default constructor with id
    Student(const Student& s); //copy constructor

    // Get functions
    string getFirstName();
    string getLastName();
    float getCGPA();
    int getResearchScore();
    int getId();
    string getHome();
    bool getType();

    // Set functions
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setCGPA(const int& CGPA);
    void setResearchScore(const int& researchScore);
    void setId(const int& id);
    void setHome(const string& newhome);
    void setType(const bool& typestudent);

    // Friend functions
    friend int compareCGPA(const Student& stu1, const Student& stu2);
    friend int compareResearchScore(const Student& stu1, const Student& stu2);
    friend int compareFirstName(const Student& stu1, const Student& stu2);
    friend int compareLastName(const Student& stu1, const Student& stu2);
};

class DomesticStudent : public Student
{
protected:
    // Variable
    string home;
public:
    

    // Constructor
    DomesticStudent(); //default constructor
    DomesticStudent(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const string& province); //non-default constructor without ID
    DomesticStudent(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const string& province, const int& id); //non-default constructor with ID
    DomesticStudent(const DomesticStudent& s); //copy constructor

    // Getter
    string getHome();

    // Setter
    void setProvince(const string& province);

    // Overload operator
    friend ostream& operator <<(ostream &out, const DomesticStudent &s);
};

class InternationalStudent : public Student
{
protected:
    // Variables
    string home;
    // int reading, listening, speaking, writing, toefl;
    // float ToeflScore; 

    ToeflScore score;
public:

    // Constructor
    InternationalStudent(); //default constructor
    InternationalStudent(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const string& country, const int& reading, const int& listening, const int& speaking, const int& writing); //non-default constructor
    InternationalStudent(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const string& country, const int& reading, const int& listening, const int& speaking, const int& writing, const int& id); //non-default constructor with id
    InternationalStudent(const InternationalStudent& s); //copy constructor

    // Getter
    string getHome();
    ToeflScore get_score();

    // Setter
    void setCountry(const string& country);

    // Meet Toefl Requirements
    bool meetToeflRequirements();

    // Overload operator
    friend ostream& operator <<(ostream& out, const InternationalStudent& s);
};

#endif