//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

//Make string sort from call function


stu_sort::stu_sort() {

} //constructor

void d_firstName_sort(DomesticStudent s[]) {
    cout << "First name sort...\n";
}

void d_lastName_sort(DomesticStudent s[]) {
    cout << "Last name sort...\n";
}

void d_cgpa_sort(DomesticStudent s[]) {
    cout << "CGPA sort...\n";
/*
    int len = 100;
    int pos = 0;
    bool running1 = true;

    while(running1) {
        bool running2 = true;
        Student temp;
        int minPos;
        if (pos == len) {
            running1 = false;
        }
        int i = pos;
        int j = len - 1;
        while (running2) {
            if (i == j) {
                minPos = i;
                if (s[i].CGPA < s[minPos].CGPA) {
                    minPos = i;
                }
                running2 = false;
            }
        }

        if (minPos != pos) {
            temp.setCGPA(s[pos].CGPA);
            s[pos].setCGPA(s[minPos].CGPA);
            s[minPos].setCGPA(temp.CGPA);
        }
        pos++;
    }*/
}

void d_researchScore_sort(DomesticStudent s[]) {
    cout << "Research score sort...\n";
}

void d_sort_all(DomesticStudent s[]) {
    cout << "Sort all";
}

/** International **/

void i_firstName_sort(InternationalStudent s[]) {
    cout << "First name sort...\n";
}

void i_lastName_sort(InternationalStudent s[]) {
    cout << "Last name sort...\n";
}

void i_cgpa_sort(InternationalStudent s[]) {
    cout << "CGPA sort...\n";
}

void i_researchScore_sort(InternationalStudent s[]) {
    cout << "Research score sort...\n";
}

void i_sort_all(InternationalStudent s[]) {
    cout << "Sort all";
}