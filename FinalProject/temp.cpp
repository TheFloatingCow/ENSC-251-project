//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include <string> //strings
#include <vector>
#include "student.hpp"
#include "stu_sort.hpp"
#include "list.hpp"


/** ------------------------Error checking------------------------ **/

string validCountries[5] = {"Canada", "China", "India", "Iran", "Korea"};
string validProvinces[13] = {"NL", "PE", "NS", "NB", "QC", "ON", "MB", "SK", "AB", "BC", "YT", "NT", "NU"};

// Case-insensitive string compare
// Compare char
bool compareChar(char& c1, char& c2) {
    // Compare chars then compare capitalized chars
    if (c1 == c2) {
        return true;
    }
    else if (toupper(c1) == toupper(c2)) {
        return true;
    }
    return false;
}

// Compare 2 strings
bool stringCompare(string str1, string arr[], int size) {
    for (int i = 0; i < size; i++) {
        string str2 = arr[i];
        if ((str1.size() == str2.size()) && equal(str1.begin(), str1.end(), str2.begin(), &compareChar)) {
            return true;
        }
    }
    return false;
}

// Check for typos, false = no typo (could still be wrong word)
// Step 1: Sort words (using bubble sort) alphabetically and compare
// Step 2: Run through non-sorted strings and check how many letters are out of place
// If 2 letters are out of place, they are swapped
string typoCheck(string str1, string arr[]) {
    for (int index = 0; index < (*arr).length() - 1; index++) {

        string str2 = arr[index];

        // Check if lengths are equal
        if (str1.length() != str2.length()) {
            continue;
        }

        // Temp variables
        string sort1 = str1;
        string sort2 = str2;
        char temp1;
        char temp2;

        // Bubble sort alphabetical order
        for (int i = 0; i < sort1.length(); i++) {
            for (int j = 0; j < sort1.length() - 1; j++) {

                // str1
                if (toupper(sort1[j]) > toupper(sort1[j + 1])) {
                    temp1 = sort1[j];
                    sort1[j] = sort1[j + 1];
                    sort1[j + 1] = temp1;
                }

                // str2
                if (toupper(sort2[j]) > toupper(sort2[j + 1])) {
                    temp2 = sort2[j];
                    sort2[j] = sort2[j + 1];
                    sort2[j + 1] = temp2;
                }
            }
        }

        // Check if words are the same
        bool cont = false;
        for (int i = 0; i < sort1.length(); i++) {
            if (toupper(sort1[i]) != toupper(sort2[i])) {
                cont = true;
            }
        }
        if (cont) {
            continue;
        }


        // Check for error
        for (int i = 0; i < sort1.length(); i++) {
            if (toupper(str1[i]) != toupper(str2[i])) {
                return str2;
            }
        }
    }
    return "";
}

int main() {

/** -------------------------Linked Lists------------------------- **/

    LinkedList<DomesticStudent> domestic_list;
    LinkedList<InternationalStudent> international_list;


    int id = 0;
    //Total Student Array
    Student students[200];


/** -------------------------DOMESTIC STUDENTS------------------------- **/

  
    //Read the domestic-stu.txt file and exit if failed
    string line;
    ifstream domesticFile("domestic-stu.txt");
    if (!domesticFile.is_open()) {
        cout << "Unable to open file domestic-stu.txt" << endl;
        return -1;
    }

    //Read the first line of domestic-stu.txt, which specifies
    //the file format. And then print it out to the screen
    getline(domesticFile, line);
    cout << "File format: " << line << endl;

    /*Keep reading the rest of the lines in domestic-stu.txt.
     *In the example code here, I will read each data separated
     *by a comma, and then print it out to the screen.
     *In your lab assignment 1, you should use these read data
     *to initialize your DomesticStudent object. Then you can
     *use get and set functions to manipulate your object, and
     *print the object content to the screen
     */
    int stu_count = 0;
    while (getline(domesticFile, line)) {
        /*process each line, get each field separated by a comma.
         *We use istringstream to handle it.
         *Note in this example code here, we assume the file format
         *is perfect and do NOT handle error cases. We will leave the
         *error and exception handling of file format to Lab Assignment 4
         */
        istringstream ss(line);

        string firstName, lastName, province, s_cgpa, s_researchScore;
        float cgpa;
        int researchScore;

        //get firstName separated by comma
        getline(ss, firstName, ',');
        if (firstName.empty()) {
            cout << "Error in line " << stu_count + 2 << ": First name is empty" << endl;
            exit(1);
        }

        //get lastName separated by comma
        getline(ss, lastName, ',');
        if (lastName.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Last name is empty" << endl;
            exit(1);
        }

        //get province separated by comma
        getline(ss, province, ',');
        if (province.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Province is empty" << endl;
            exit(1);
        }
        if (!stringCompare(province,  validProvinces, sizeof(validProvinces)/sizeof(validProvinces[0]))) {
            cout << "Error in line " << stu_count + 2 << ": Invalid province" << endl;
            exit(1);
        }

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        if (s_cgpa.empty()) {
            cout << "Error in line " << stu_count + 2 << ": CGPA is empty" << endl;
            exit(1);
        }
        if (cgpa > 100 || cgpa < 0) {
            cout << "Error in line " << stu_count + 2 << ": CGPA is invalid" << endl;
            exit(1);
        }

        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        if (s_researchScore.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Research score is empty" << endl;
            exit(1);
        }
        researchScore = atoi(s_researchScore.c_str());
        if (researchScore > 100 || researchScore < 0) {
            cout << "Error in line " << stu_count + 2 << ": Research score is invalid" << endl;
            exit(1);
        }

        //add values to array
        DomesticStudent new_student = DomesticStudent(firstName, lastName, cgpa, researchScore, province, id);
        students[id] = Student(firstName, lastName, cgpa, researchScore, id);

        domestic_list.insert(new_student);

        stu_count++;
        id++;
    }

    //close domestic file
    domesticFile.close();


/** -------------------------INTERNATIONAL STUDENTS------------------------- **/

    // International student arrays
    InternationalStudent internationalStudents[100];

    string line2;
    ifstream internationalFile("international-stu.txt");
    if (!internationalFile.is_open()) {
        cout << "Unable to open file international-stu.txt" << endl;
        return -1;
    }

    //Read the first line of international-stu.txt
    getline(internationalFile, line);
    cout << "File format: " << line << endl;

    //Read the rest of the lines in international-stu.txt
    stu_count = 0;
    while (getline(internationalFile, line)) {

        istringstream ss(line);

        //initialize variables
        string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
        float cgpa;
        int researchScore, reading, listening, speaking, writing;


        //get firstName separated by comma
        getline(ss, firstName, ',');
        if (firstName.empty()) {
            cout << "Error in line " << stu_count + 2 << ": First name is empty" << endl;
            exit(1);
        }

        //get lastName separated by comma
        getline(ss, lastName, ',');
        if (lastName.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Last name is empty" << endl;
            exit(1);
        }

        //get province separated by comma
        getline(ss, country, ',');
        if (country.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Country is empty" << endl;
            exit(1);
        }
        if (typoCheck(country, validCountries).empty()) {
            if (!stringCompare(country, validCountries, sizeof(validCountries)/sizeof(validCountries[0]))) {
                cout << "Error in line " << stu_count + 2 << ": Invalid country" << endl;
                exit(1);
            }

        }
        else {
            country = typoCheck(country, validCountries);
            cout << "Error in line " << stu_count + 2 << ": There has been a typo. Autocorrecting to " << country << endl;
        }

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        if (s_cgpa.empty()) {
            cout << "Error in line " << stu_count + 2 << ": CGPA is empty" << endl;
            exit(1);
        }
        cgpa = atof(s_cgpa.c_str());
        if (cgpa > 100 || cgpa < 0) {
            cout << "Error in line " << stu_count + 2 << ": CGPA is invalid" << endl;
            exit(1);
        }

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        if (s_researchScore.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Research score is empty" << endl;
            exit(1);
        }
        researchScore = atoi(s_researchScore.c_str());
        if (researchScore > 100 || researchScore < 0) {
            cout << "Error in line " << stu_count + 2 << ": Research score is invalid" << endl;
            exit(1);
        }

        //get reading separated by comma, and convert string to int
        getline(ss, s_reading, ',');
        if (s_reading.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Reading score is empty" << endl;
            exit(1);
        }
        reading = atoi(s_reading.c_str());
        if (reading > 100 || reading < 0) {
            cout << "Error in line " << stu_count + 2 << ": Reading score is invalid" << endl;
            exit(1);
        }

        //get listening separated by comma, and convert string to int
        getline(ss, s_listening, ',');
        if (s_listening.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Listening score is empty" << endl;
            exit(1);
        }
        listening = atoi(s_listening.c_str());
        if (listening > 100 || listening < 0) {
            cout << "Error in line " << stu_count + 2 << ": Listening score is invalid" << endl;
            exit(1);
        }

        //get speaking separated by comma, and convert string to int
        getline(ss, s_speaking, ',');
        if (s_speaking.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Speaking score is empty" << endl;
            exit(1);
        }
        speaking = atoi(s_speaking.c_str());
        if (speaking > 100 || speaking < 0) {
            cout << "Error in line " << stu_count + 2 << ": Speaking score is invalid" << endl;
            exit(1);
        }

        //get writing separated by comma, and convert string to int
        getline(ss, s_writing, ',');
        if (s_writing.empty()) {
            cout << "Error in line " << stu_count + 2 << ": Writing score is empty" << endl;
            exit(1);
        }
        writing = atoi(s_writing.c_str());
        if (writing > 100 || writing < 0) {
            cout << "Error in line " << stu_count + 2 << ": Writing score is invalid" << endl;
            exit(1);
        }

        InternationalStudent student = InternationalStudent(firstName, lastName, cgpa, researchScore, country, reading, listening, speaking, writing, id);
        students[id] = Student(firstName, lastName, cgpa, researchScore, id);

        // check toefl requirements
        if(student.meetToeflRequirements()){
            international_list.insert(student);
        }

        stu_count++;
        id++;
    }
    //variables for adding students outside multiple switch cases
    string add_fName;
    string add_lName;
    float add_cgpa;
    int add_researchScore;

    //close international file
    internationalFile.close();

   
}
