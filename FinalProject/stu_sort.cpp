//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"

//Make string sort from call function

/*
Takes in Domestic Students and a string to specify what order sort
can pass in "firstname", "lastname", "cgpa", "research"
*/

// Helper Functions
// Domestic
void merge_d(DomesticStudent s[], int low, int high, int mid, string sorted);
void merge_i(InternationalStudent s[], int low, int high, int mid, string sorted);

void mergeSort_domestic(DomesticStudent s[], int low, int high, string sorted);
void mergeSort_international(InternationalStudent s[], int low, int high, string sorted);

void sortDomestic(DomesticStudent s[], string sorted, int size){
    mergeSort_domestic(s,0,size-1,sorted);
}

/*
Takes in International Students and a string to specify what order sort
can pass in "firstname", "lastname", "cgpa", "research", "TOEFL"
*/
void sortInternational(InternationalStudent s[], string sorted, int size){
    if(sorted == "overall"){
        // Drop low toefl students
        vector<InternationalStudent> i_students;
        for(int i = 0; i < size; i++){
            if(s[i].get_score().get_totalScore() >= 93 && s[i].get_score().get_reading() >= 20 && s[i].get_score().get_speaking() >= 20 && s[i].get_score().get_listening() >= 20 && s[i].get_score().get_writing() >= 20){
                i_students.push_back(s[i]);
            }
        }
        InternationalStudent* temps = &i_students[0];


        mergeSort_international(temps,0,i_students.size()-1,sorted);

        // print
        for(int i = 0; i < i_students.size()-1; i++){
            std::cout << i_students[i];
        }
    } else {
        mergeSort_international(s,0,size-1,sorted);
    }
}


// Declarations of Helper Functions

void merge_d(DomesticStudent s[], int low, int high, int mid, string sorted){
    int i,j,k;
    DomesticStudent temp[200];
    i = low;
    k = low;
    j = mid + 1;

    while(i <= mid && j <= high){
        if(sorted == "firstname"){
            if(s[i].getFirstName() < s[j].getFirstName()){
                temp[k] = s[i];
                k++;
                i++;
            } else {
                temp[k] = s[j];
                k++;
                j++;
            }
        } else if(sorted == "lastname"){
            if(s[i].getLastName() < s[j].getLastName()){
                temp[k] = s[i];
                k++;
                i++;
            } else if(s[i].getLastName() > s[j].getLastName()){
                temp[k] = s[j];
                k++;
                j++;
            } else {
                //equal names sort by first name
                if(s[i].getFirstName() < s[j].getFirstName()){
                    temp[k] = s[i];
                    k++;
                    i++;
                } else {
                    temp[k] = s[j];
                    k++;
                    j++;
                }
            }
        } else if(sorted == "cgpa"){
            if(s[i].getCGPA() > s[j].getCGPA()){
                temp[k] = s[i];
                k++;
                i++;
            } else {
                temp[k] = s[j];
                k++;
                j++;
            }
        } else if(sorted == "research"){
            if(s[i].getResearchScore() > s[j].getResearchScore()){
                temp[k] = s[i];
                k++;
                i++;
            } else {
                temp[k] = s[j];
                k++;
                j++;
            }
        } else if (sorted == "overall") {
            // sort research score, cgpa, province
            if(s[i].getResearchScore() > s[j].getResearchScore()){
                temp[k] = s[i];
                k++;
                i++;
            } else if(s[i].getResearchScore() < s[j].getResearchScore()){
                temp[k] = s[j];
                k++;
                j++;
            } else {
                // same research sort by cgpa
                if(s[i].getCGPA() > s[j].getCGPA()){
                    temp[k] = s[i];
                    k++;
                    i++;
                } else if(s[i].getCGPA() < s[j].getCGPA()){
                    temp[k] = s[j];
                    k++;
                    j++;
                } else {
                    // same cgpa sort by province
                    if(s[i].getProvince() < s[j].getProvince()){
                        temp[k] = s[i];
                        k++;
                        i++;
                    } else {
                        temp[k] = s[j];
                        k++;
                        j++;
                    }
                }
            }
        }
    }

    while(i <= mid){
        temp[k] = s[i];
        k++;
        i++;
    }

    while(j <= high){
        temp[k] = s[j];
        k++;
        j++;
    }

    for(i = low; i < k; i++){
        s[i] = temp[i];
    }
}

void mergeSort_domestic(DomesticStudent s[], int low, int high, string sorted){
    if(low < high){
        int mid;
        mid = (low+high)/2;
        mergeSort_domestic(s,low, mid,sorted);
        mergeSort_domestic(s,mid+1,high,sorted);


        merge_d(s,low,high,mid,sorted);

    }
    return;
}

void merge_i(InternationalStudent s[], int low, int high, int mid, string sorted){
    int i,j,k;
    InternationalStudent temp[200];
    i = low;
    k = low;
    j = mid + 1;

    while(i <= mid && j <= high){
        if(sorted == "firstname"){
            if(s[i].getFirstName() < s[j].getFirstName()){
                temp[k] = s[i];
                k++;
                i++;
            } else {
                temp[k] = s[j];
                k++;
                j++;
            }
        } else if(sorted == "lastname"){
            if(s[i].getLastName() < s[j].getLastName()){
                temp[k] = s[i];
                k++;
                i++;
            } else if(s[i].getLastName() > s[j].getLastName()){
                temp[k] = s[j];
                k++;
                j++;
            } else {
                //equal names sort by first name
                if(s[i].getFirstName() < s[j].getFirstName()){
                    temp[k] = s[i];
                    k++;
                    i++;
                } else {
                    temp[k] = s[j];
                    k++;
                    j++;
                }
            }
        } else if(sorted == "cgpa"){
            if(s[i].getCGPA() > s[j].getCGPA()){
                temp[k] = s[i];
                k++;
                i++;
            } else {
                temp[k] = s[j];
                k++;
                j++;
            }
        } else if(sorted == "research"){
            if(s[i].getResearchScore() > s[j].getResearchScore()){
                temp[k] = s[i];
                k++;
                i++;
            } else {
                temp[k] = s[j];
                k++;
                j++;
            }
        } else if (sorted == "TOEFL"){
            if(s[i].get_score().get_totalScore() > s[j].get_score().get_totalScore()){
                temp[k] = s[i];
                k++;
                i++;
            } else {
                temp[k] = s[j];
                k++;
                j++;
            }
        } else if (sorted == "overall") {
            // sort research score, cgpa, country
            if(s[i].getResearchScore() > s[j].getResearchScore()){
                temp[k] = s[i];
                k++;
                i++;
            } else if(s[i].getResearchScore() < s[j].getResearchScore()){
                temp[k] = s[j];
                k++;
                j++;
            } else {
                // same research sort by cgpa
                if(s[i].getCGPA() > s[j].getCGPA()){
                    temp[k] = s[i];
                    k++;
                    i++;
                } else if(s[i].getCGPA() < s[j].getCGPA()){
                    temp[k] = s[j];
                    k++;
                    j++;
                } else {
                    // same cgpa sort by province
                    if(s[i].getCountry() < s[j].getCountry()){
                        temp[k] = s[i];
                        k++;
                        i++;
                    } else {
                        temp[k] = s[j];
                        k++;
                        j++;
                    }
                }
            }
        }
    }

    while(i <= mid){
        temp[k] = s[i];
        k++;
        i++;
    }

    while(j <= high){
        temp[k] = s[j];
        k++;
        j++;
    }

    for(i = low; i < k; i++){
        s[i] = temp[i];
    }
}

void mergeSort_international(InternationalStudent s[], int low, int high, string sorted){
    if(low < high){
        int mid;
        mid = (low+high)/2;
        mergeSort_international(s,low, mid,sorted);
        mergeSort_international(s,mid+1,high,sorted);


        merge_i(s,low,high,mid,sorted);

    }
    return;
}







