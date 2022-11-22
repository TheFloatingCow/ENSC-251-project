//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

//Make string sort from call function

/*
Takes in Domestic Students and a string to specify what order sort
can pass in "firstname", "lastname", "cgpa", "research"
*/
void sortDomestic(DomesticStudent s[], string sorted){
    if(sorted == "firstname"){
        cout << "First name sort...\n";
        for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                DomesticStudent temp;
                if(s[i].getFirstName() > s[j].getFirstName())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    } else if(sorted == "lastname"){
        cout << "Last name sort...\n";
        for(int i = 0; i < 99; i++)
        {

            for(int j = i+1; j < 100; j++)
            {
                DomesticStudent temp;
                if(s[i].getLastName() > s[j].getLastName())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    } else if(sorted == "cgpa"){
        for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                DomesticStudent temp;
                if(s[i].getCGPA() < s[j].getCGPA())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    } else if(sorted == "research"){
        cout << "Research score sort...\n";
        for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                DomesticStudent temp;
                if(s[i].getResearchScore() < s[j].getResearchScore())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        } 
    } else if(sorted == "overall") {
         // sort overall CGPA, Province (Alphabetical)
         for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                DomesticStudent temp;
                if(s[i].getCGPA() == s[j].getCGPA()){
                    if((s[i].getProvince()) > (s[j].getProvince())){
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
                if(s[i].getCGPA() < s[j].getCGPA())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        } 
    } else {
        cout << "Invalid Input\n";
    }
} 

/*
Takes in International Students and a string to specify what order sort
can pass in "firstname", "lastname", "cgpa", "research", "TOEFL"
*/
void sortInternational(InternationalStudent s[], string sorted){
    if(sorted == "firstname"){
        cout << "First name sort...\n";
        for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                //Create temporary local constructor
                InternationalStudent temp;
                //Conditional
                if(s[i].getFirstName() > s[j].getFirstName())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    } else if(sorted == "lastname"){
        cout << "Last name sort...\n";
        for(int i = 0; i < 99; i++)
        {

            for(int j = i+1; j < 100; j++)
            {
                //Create temporary local constructor
                InternationalStudent temp;
                //Conditional
                if(s[i].getLastName() > s[j].getLastName())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    } else if(sorted == "cgpa"){
        cout << "CGPA sort...\n";
        for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                //Create temporary local constructor
                InternationalStudent temp;
                //Conditional
                if(s[i].getCGPA() < s[j].getCGPA())
                {   
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    } else if(sorted == "research"){
        cout << "Research score sort...\n";
        for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                //Create temporary local constructor
                InternationalStudent temp;
                //Conditional
                if(s[i].getResearchScore() < s[j].getResearchScore())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    } else if(sorted == "TOEFL") {
        cout << "TOEFL sort...\n";
        for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                //Create temporary local constructor
                InternationalStudent temp;
                //Conditional
                if(s[i].getToefl() < s[j].getToefl())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
    } else if(sorted == "overall") {
       // Drop students with toefl score < 90 and check if min 20 is achieved in all catagories
       // Put students in vector
        vector<InternationalStudent> i_students;
        for(int i = 0; i < 101; i++){
            if(s[i].getToefl() >= 93 && s[i].getReading() >= 20 && s[i].getWriting() >= 20 && s[i].getSpeaking() >= 20 && s[i].getListening() >= 20){
                i_students.push_back(s[i]);
            }
        }

        for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                //Create temporary local constructor
                InternationalStudent temp;
                if(i_students[i].getCGPA() == i_students[j].getCGPA()){
                    if((i_students[i].getCountry()) > (i_students[j].getCountry())){
                        temp = i_students[i];
                        i_students[i] = i_students[j];
                        i_students[j] = temp;
                    }
                }
                //Conditional
                if(i_students[i].getCGPA() < i_students[j].getCGPA())
                {
                    //If number or string is bigger than the next then replace s[i] with s[j]
                    //Since temp beforehand is s[i], swap by making s[j] temp now
                    temp = i_students[i];
                    i_students[i] = i_students[j];
                    i_students[j] = temp;
                }
            }
        }

        for(int i = 0; i < i_students.size()-1; i++){
            cout << i_students[i];
        }

    } else {
        cout << "Invalid Input\n";
    }
} 





