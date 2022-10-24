//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

//Make string sort from call function


stu_sort::stu_sort() {

} //constructor

void d_firstName_sort(DomesticStudent s[]) {
    cout << "First name sort...\n";
    for(int i = 0; i < 99; i++)
    {
        for(int j = i+1; j < 100; j++)
        {
            DomesticStudent temp;
            if(s[i].firstName > s[j].firstName)
            {
                //If number or string is bigger than the next then replace s[i] with s[j]
                //Since temp beforehand is s[i], swap by making s[j] temp now
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

}

void d_lastName_sort(DomesticStudent s[]) {
    cout << "Last name sort...\n";

    for(int i = 0; i < 99; i++)
    {

        for(int j = i+1; j < 100; j++)
        {
            DomesticStudent temp;
            if(s[i].lastName > s[j].lastName)
            {
                //If number or string is bigger than the next then replace s[i] with s[j]
                //Since temp beforehand is s[i], swap by making s[j] temp now
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
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
    for(int i = 0; i < 99; i++)
    {
        for(int j = i+1; j < 100; j++)
        {
            DomesticStudent temp;
            if(s[i].CGPA < s[j].CGPA)
            {
                //If number or string is bigger than the next then replace s[i] with s[j]
                //Since temp beforehand is s[i], swap by making s[j] temp now
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }


}

void d_researchScore_sort(DomesticStudent s[]) {
    cout << "Research score sort...\n";
        for(int i = 0; i < 99; i++)
    {
        for(int j = i+1; j < 100; j++)
        {
            DomesticStudent temp;
            if(s[i].researchScore < s[j].researchScore)
            {
                //If number or string is bigger than the next then replace s[i] with s[j]
                //Since temp beforehand is s[i], swap by making s[j] temp now
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void d_sort_all(DomesticStudent s[]) {
    cout << "Sort all";
}

/** International **/

void i_firstName_sort(InternationalStudent s[]) {
    cout << "First name sort...\n";
        for(int i = 0; i < 99; i++)
    {
        for(int j = i+1; j < 100; j++)
        {
            //Create temporary local constructor
            InternationalStudent temp;
            //Conditional
            if(s[i].firstName > s[j].firstName)
            {
                //If number or string is bigger than the next then replace s[i] with s[j]
                //Since temp beforehand is s[i], swap by making s[j] temp now
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void i_lastName_sort(InternationalStudent s[]) {
    cout << "Last name sort...\n";
        for(int i = 0; i < 99; i++)
    {

        for(int j = i+1; j < 100; j++)
        {
            //Create temporary local constructor
            InternationalStudent temp;
            //Conditional
            if(s[i].lastName > s[j].lastName)
            {
                //If number or string is bigger than the next then replace s[i] with s[j]
                //Since temp beforehand is s[i], swap by making s[j] temp now
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void i_cgpa_sort(InternationalStudent s[]) {
    cout << "CGPA sort...\n";
        for(int i = 0; i < 99; i++)
    {
        for(int j = i+1; j < 100; j++)
        {
            //Create temporary local constructor
            InternationalStudent temp;
            //Conditional
            if(s[i].CGPA < s[j].CGPA)
            {   
                //If number or string is bigger than the next then replace s[i] with s[j]
                //Since temp beforehand is s[i], swap by making s[j] temp now
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void i_researchScore_sort(InternationalStudent s[]) {
    cout << "Research score sort...\n";
    for(int i = 0; i < 99; i++)
    {
        for(int j = i+1; j < 100; j++)
        {
            //Create temporary local constructor
            InternationalStudent temp;
            //Conditional
            if(s[i].researchScore < s[j].researchScore)
            {
                //If number or string is bigger than the next then replace s[i] with s[j]
                //Since temp beforehand is s[i], swap by making s[j] temp now
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void i_sort_all(InternationalStudent s[]) {
    cout << "Sort all";
}
