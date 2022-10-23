//header file stu_sort.hpp to declare your sorting functions
#ifndef Stu_Sort_HG
#define Stu_Sort_HG

#include "student.hpp"
using namespace std; //use namespace std
#include <string> //you will have to use string in C++

class stu_sort
{
public:

    // Constructor
    stu_sort();

};

// Functions
/* think theres a way to combine them so you only need one function
* for both domestic and international students but not sure how */
void d_firstName_sort(DomesticStudent s[]);
void d_lastName_sort(DomesticStudent s[]);
void d_cgpa_sort(DomesticStudent s[]);
void d_researchScore_sort(DomesticStudent s[]);
void d_sort_all(DomesticStudent s[]);

void i_firstName_sort(InternationalStudent s[]);
void i_lastName_sort(InternationalStudent s[]);
void i_cgpa_sort(InternationalStudent s[]);
void i_researchScore_sort(InternationalStudent s[]);
void i_sort_all(InternationalStudent s[]);

#endif