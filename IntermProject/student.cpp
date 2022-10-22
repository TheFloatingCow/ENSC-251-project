//student.cpp to implement your classes
#include "student.hpp"


//constructors
Student::Student() {
    this->firstName = "N/A";
    this->lastName = "N/A";
    this->CGPA = 0;
    this->researchScore = 0;
    this->id = 20220000;
} //default constructor

Student::Student(const string &firstName, const string &lastName, const float &CGPA, const int &researchScore,
                 const int &id) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->CGPA = CGPA;
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


// Friend functions
// 1 = >, 2 = <, 3 = =
int compareCGPA(const Student &stu1, const Student &stu2) {
    int output;
    if (stu1.CGPA > stu2.CGPA) {
        output = 1;
    }
    if (stu1.CGPA < stu2.CGPA) {
        output = 2;
    }
    if (stu1.CGPA == stu2.CGPA) {
        output = 3;
    }
    return output;
}

int compareResearchScore(const Student &stu1, const Student &stu2) {
    int output;
    if (stu1.researchScore > stu2.researchScore) {
        output = 1;
    }
    if (stu1.researchScore < stu2.researchScore) {
        output = 2;
    }
    if (stu1.researchScore == stu2.researchScore) {
        output = 3;
    }
    return output;
}

int compareFirstName(const Student &stu1, const Student &stu2) {
    int output;
    if (stu1.firstName.compare(stu2.firstName) < 0) {
        output = 1;
    }
    if (stu1.firstName.compare(stu2.firstName) > 0) {
        output = 2;
    }
    if (stu1.firstName.compare(stu2.firstName) == 0) {
        output = 3;
    }
    return output;
}

int compareLastName(const Student &stu1, const Student &stu2) {
    int output;
    if (stu1.lastName.compare(stu2.lastName) < 0) {
        output = 1;
    }
    if (stu1.lastName.compare(stu2.lastName) > 0) {
        output = 2;
    }
    if (stu1.lastName.compare(stu2.lastName) == 0) {
        output = 3;
    }
    return output;
}

// Get functions
string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

int Student::getCGPA() {
    return CGPA;
}

int Student::getResearchScore() {
    return researchScore;
}

int Student::getId() {
    return id;
}



/** Domestic Student **/

// Constructor
DomesticStudent::DomesticStudent() {

} //default constructor

// Friend function
ostream &operator<<(ostream &out, const DomesticStudent &DomesticStudent) {
    return out;
} //overload << operator



/** International Student **/

// Constructor
InternationalStudent::InternationalStudent() {

} //default constructor

// Friend function
ostream &operator<<(ostream &out, const InternationalStudent &InternationalStudent) {
    return out;
} //overload << operator