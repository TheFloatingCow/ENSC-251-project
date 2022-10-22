//header file stu_sort.hpp to declare your sorting functions
#ifndef Stu_Sort_HG
#define Stu_Sort_HG

#include "student.hpp"
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class stu_sort
{
public:
    Student s[10];

    // Constructor
    stu_sort();

    // Functions
    int firstName_sort();
    int lastName_sort();
    int cgpa_sort();
    int researchScore_sort();

};

#endif