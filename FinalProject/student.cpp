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

Student::Student(const string &firstName, const string &lastName, const float &CGPA, const int &researchScore) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->CGPA = CGPA;
    this->researchScore = researchScore;
} //non-default constructor

Student::Student(const string &firstName, const string &lastName, const float &CGPA, const int &researchScore, const int& id) {
    this->firstName = firstName;
    this->lastName = lastName;
    this->CGPA = CGPA;
    this->researchScore = researchScore;
    this->id = 20220000 + id;
} //non-default constructor with ID

Student::Student(const Student& s) {
    this->firstName = s.firstName;
    this->lastName = s.lastName;
    this->CGPA  = s.CGPA;
    this->researchScore = s.researchScore;
    this->id = s.id;
    this->home = s.home;
    this->type = s.type;
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

// Getters
string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

float Student::getCGPA() {
    return CGPA;
}

int Student::getResearchScore() {
    return researchScore;
}

int Student::getId() {
    return id;
}

string Student::getHome(){
    return home;
}

bool Student::getType(){
    return type;
}

// Setters
void Student::setFirstName(const string& firstName) {
    this->firstName = firstName;
}

void Student::setLastName(const string& lastName) {
    this->lastName = lastName;
}

void Student::setCGPA(const int& CGPA) {
    this->CGPA = CGPA;
}

void Student::setResearchScore(const int& researchScore) {
    this->researchScore = researchScore;
}

void Student::setId(const int& id) {
    this->id = id;
}

void Student::setHome(const string& newhome){
    this->home = newhome;
}

void Student::setType(const bool& typestudent){
    this->type = typestudent;
}


/** Domestic Student **/

// Constructor
DomesticStudent::DomesticStudent() {

} //default constructor

DomesticStudent::DomesticStudent(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const string& province)
: Student(firstName, lastName, CGPA, researchScore) {
    this->home = province;
    type = true;
} //non-default constructor without id

DomesticStudent::DomesticStudent(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const string& province, const int& id)
        : Student(firstName, lastName, CGPA, researchScore, id) {
    this->home = province;
    type = true;
} //non-default constructor with id

DomesticStudent::DomesticStudent(const DomesticStudent& s) {
    this->firstName = s.firstName;
    this->lastName = s.lastName;
    this->CGPA  = s.CGPA;
    this->researchScore = s.researchScore;
    this->id = s.id;
    this->home = s.home;
    type = true;
} //copy constructor

// Getter
string DomesticStudent::getHome() {
    return this->home;
}

// Setter
void DomesticStudent::setProvince(const string& province) {
    this->home = province;
}

// Friend function
ostream& operator <<(ostream &out, const DomesticStudent &s) {
    out << "Domestic student " << s.firstName << " "
        << s.lastName << " " << s.id << " from "
        << s.home << " province has cgpa of "
        << s.CGPA << ", and research score of " << s.researchScore << endl;
    return out;
} //overload << operator



/** International Student **/

// Constructor
InternationalStudent::InternationalStudent() {

} //default constructor

InternationalStudent::InternationalStudent(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const string& country, const int& reading, const int& listening, const int& speaking, const int& writing)
: Student(firstName, lastName, CGPA, researchScore) {
    this->home = country;
    this->score.set_reading(reading);
    this->score.set_listening(listening);
    this->score.set_speaking(speaking);
    this->score.set_writing(writing);
    type = false;
} //non-default constructor

InternationalStudent::InternationalStudent(const string& firstName, const string& lastName, const float& CGPA, const int& researchScore, const string& country, const int& reading, const int& listening, const int& speaking, const int& writing, const int& id)
        : Student(firstName, lastName, CGPA, researchScore, id) {
    this->home = country;
    this->score.set_reading(reading);
    this->score.set_listening(listening);
    this->score.set_speaking(speaking);
    this->score.set_writing(writing);
    type = false;
} //non-default constructor

InternationalStudent::InternationalStudent(const InternationalStudent& s) {
    this->firstName = s.firstName;
    this->lastName = s.lastName;
    this->CGPA  = s.CGPA;
    this->researchScore = s.researchScore;
    this->id = s.id;
    this->home = s.home;
    this->score.set_reading(s.score.get_reading());
    this->score.set_listening(s.score.get_listening());
    this->score.set_speaking(s.score.get_speaking());
    this->score.set_writing(s.score.get_writing());
    type = false;
} //copy constructor

// Getter
string InternationalStudent::getHome() {
    return this->home;
}

ToeflScore InternationalStudent::get_score(){
    return this->score;
}

// Setter
void InternationalStudent::setCountry(const string& country) {
    this->home = country;
}

// Check if toefl requrements are met
bool InternationalStudent::meetToeflRequirements(){
    if(score.get_totalScore() >= 93 && score.get_reading() >= 20 && score.get_speaking() >= 20 && score.get_listening() >= 20 && score.get_writing() >= 20){
        return true;
    } 
    return false;
}

// Friend function
ostream& operator <<(ostream &out, const InternationalStudent &s) {
    out << "International student " << s.firstName << " "
             << s.lastName << " " << s.id << " from "
             << s.home << " has cgpa of "
             << s.CGPA << ", research of " << s.researchScore
             << ", and TOEFL of " << s.score.get_totalScore() << endl;
    return out;
} //overload << operator