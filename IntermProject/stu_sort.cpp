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
    } else if(sorted == "lastname"){
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
    } else if(sorted == "cgpa"){
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
    } else if(sorted == "research"){
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
    } else if(sorted == "lastname"){
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
    } else if(sorted == "cgpa"){
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
    } else if(sorted == "research"){
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
    } else if(sorted == "TOEFL") {
        cout << "TOEFL sort...\n";
        for(int i = 0; i < 99; i++)
        {
            for(int j = i+1; j < 100; j++)
            {
                //Create temporary local constructor
                InternationalStudent temp;
                //Conditional
                if(s[i].toefl < s[j].toefl)
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

// Sort All by combining all domestic and international to one array
void sortAll(DomesticStudent d[], InternationalStudent i[], string sorted){
    
}



