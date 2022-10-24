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

void sortDomestic(DomesticStudent s[], string sorted);
void sortInternational(InternationalStudent s[], string sorted);

// Not Implemented yet
void sortAll(DomesticStudent d[], InternationalStudent i[], string sorted);

#endif