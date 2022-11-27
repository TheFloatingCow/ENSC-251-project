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

    LinkedList<DomesticStudent> dlist1;
    LinkedList<InternationalStudent> ilist1;


    int id = 0;
    //Total Student Array
    Student students[200];


/** -------------------------DOMESTIC STUDENTS------------------------- **/

    // Domestic student array
    DomesticStudent domesticStudents[100];


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
        domesticStudents[stu_count] = DomesticStudent(firstName, lastName, cgpa, researchScore, province, id);
        students[id] = Student(firstName, lastName, cgpa, researchScore, id);

        /** issue here I think **/
        //dlist1.head_insert(dlist1.getHead(), DomesticStudent(firstName, lastName, cgpa, researchScore, province, id));

        stu_count++;
        id++;
    }

    //close domestic file
    domesticFile.close();

    // Print domestic students
    for (int i = 0; i < 100; i++) {
        cout << domesticStudents[i];
    }



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
            cout << "Error in line " << stu_count + 2 << ": There has been a typo. Autocorrecting to " << typoCheck(country, validCountries) << endl;
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

        // Add values to array
        internationalStudents[stu_count] = InternationalStudent(firstName, lastName, cgpa, researchScore, country,
                                                                reading, listening, speaking, writing, id);
        students[id] = Student(firstName, lastName, cgpa, researchScore, id);

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

    for (int i = 0; i < 100; i++) {
        cout << internationalStudents[i];
    }



/** -------------------------Main function loop------------------------- **/

    while (true) {
        int input;
        int size_d = sizeof(domesticStudents) / sizeof(DomesticStudent);
        int size_i = sizeof(internationalStudents) / sizeof(InternationalStudent);
        cout << endl << "\nStudent Directory\n"
             << "Type 1 to print all domestic students\n"
             << "Type 2 to pring all international students\n"
             << "Type 3 to sort domestic students\n"
             << "Type 4 to sort international students\n"
             << "Type 5 to compare students\n"
             << "Type 6 to search sorted list\n"
             << "Type 7 to add or delete student\n"
             << "Type 8 to remove top and lowest students\n"
             << "Type 9 to exit program\n"
             << ">> ";

        cin >> input;

        switch (input) {
            case 1:
                for (int i = 0; i < 100; i++) {
                    cout << domesticStudents[i];
                }
                break;
            case 2:
                for (int i = 0; i < 100; i++) {
                    cout << internationalStudents[i];
                }
                break;
            case 3: //domestic
                cout << endl << "What field would you like to sort by\n"
                     << "Type 1 for first name\n"
                     << "Type 2 for last name\n"
                     << "Type 3 for CGPA\n"
                     << "Type 4 for research score\n"
                     << "Type 5 for overall sort\n"
                     << ">> ";
                int in1;
                cin >> in1;
                switch (in1) {

                    case 1:
                        // Sort by first name
                        sortDomestic(domesticStudents, "firstname", size_d);
                        for (int i = 0; i < 100; i++) {
                            cout << domesticStudents[i];
                        }
                        break;
                    case 2:
                        // Sort by last name
                        sortDomestic(domesticStudents, "lastname", size_d);
                        for (int i = 0; i < 100; i++) {
                            cout << domesticStudents[i];
                        }
                        break;
                    case 3:
                        // Sort by CGPA
                        sortDomestic(domesticStudents, "cgpa", size_d);
                        for (int i = 0; i < 100; i++) {
                            cout << domesticStudents[i];
                        }
                        break;
                    case 4:
                        // Sort by research score
                        sortDomestic(domesticStudents, "research", size_d);
                        for (int i = 0; i < 100; i++) {
                            cout << domesticStudents[i];
                        }
                        break;
                    case 5:
                        sortDomestic(domesticStudents, "overall", size_d);
                        for (int i = 0; i < 100; i++) {
                            cout << domesticStudents[i];
                        }
                        break;

                    default:
                        cin.clear();
                        cin.ignore();
                        cout << endl << "Invalid option selected" << endl;
                        break;
                }
                break;
            case 4: //international
                cout << endl << "What field would you like to sort by\n"
                     << "Type 1 for first name\n"
                     << "Type 2 for last name\n"
                     << "Type 3 for CGPA\n"
                     << "Type 4 for research score\n"
                     << "Type 5 for TOEFL\n"
                     << "Type 6 for overall sort\n"
                     << ">> ";
                int in2;
                cin >> in2;
                switch (in2) {
                    case 1:
                        // Sort by first name
                        sortInternational(internationalStudents, "firstname", size_i);
                        for (int i = 0; i < 100; i++) {
                            cout << internationalStudents[i];
                        }
                        break;
                    case 2:
                        // Sort by last name
                        sortInternational(internationalStudents, "lastname", size_i);
                        for (int i = 0; i < 100; i++) {
                            cout << internationalStudents[i];
                        }
                        break;
                    case 3:
                        // Sort by CGPA
                        sortInternational(internationalStudents, "cgpa", size_i);
                        for (int i = 0; i < 100; i++) {
                            cout << internationalStudents[i];
                        }
                        break;
                    case 4:
                        // Sort by research score
                        sortInternational(internationalStudents, "research", size_i);
                        for (int i = 0; i < 100; i++) {
                            cout << internationalStudents[i];
                        }
                        break;
                    case 5:
                        sortInternational(internationalStudents, "TOEFL", size_i);
                        for (int i = 0; i < 100; i++) {
                            cout << internationalStudents[i];
                        }
                        break;
                    case 6:
                        sortInternational(internationalStudents, "overall", size_i);
                        break;

                    default:
                        cin.clear();
                        cin.ignore();
                        cout << endl << "Invalid option selected" << endl;
                        break;
                }
                break;
            case 5: //Input of comparing based on student applicant ID
                cout << endl << "What field would you want to compare by\n"
                     << "Type 1 for cgpa\n"
                     << "Type 2 for research score\n"
                     << "Type 3 for first name\n"
                     << "Type 4 for last name\n"
                     << ">>";
                int in3;
                cin >> in3;
                switch (in3) {
                    case 1:
                        cout << endl << "Type in the first student's application number\n"
                             << ">> ";
                        int app1;
                        cin >> app1;
                        cout << endl << "Type in the second student's application number\n"
                             << ">> ";
                        int app2;
                        cin >> app2;

                        if (compareCGPA(students[app1 - 20220000], students[app2 - 20220000]) == 1) {
                            cout << endl << "Student " << students[app1 - 20220000].getId() << " has a greater CGPA of "
                                 << students[app1 - 20220000].getCGPA() << endl
                                 << "While student " << students[app2 - 20220000].getId() << " has a smaller CGPA of "
                                 << students[app2 - 20220000].getCGPA() << endl;
                        } else if (compareCGPA(students[app1 - 20220000], students[app2 - 20220000]) == 2) {
                            cout << endl << "Student " << students[app1 - 20220000].getId() << "has a smaller CGPA of "
                                 << students[app1 - 20220000].getCGPA() << endl
                                 << "While student " << students[app2 - 20220000].getId() << " has a greater CGPA of "
                                 << students[app2 - 20220000].getCGPA() << endl;
                        } else if (compareCGPA(students[app1 - 20220000], students[app2 - 20220000]) == 3) {
                            cout << endl << "Student " << students[app1 - 20220000].getId() << " and student "
                                 << students[app2 - 20220000].getId()
                                 << " both have the same CGPA of " << students[app2 - 20220000].getCGPA() << endl;
                        }
                        break;
                    case 2:
                        cout << endl << "Type in the first student's application number\n"
                             << ">> ";
                        int app3;
                        cin >> app3;
                        cout << endl << "Type in the second student's application number\n"
                             << ">> ";
                        int app4;
                        cin >> app4;
                        if (compareResearchScore(students[app3 - 20220000], students[app4 - 20220000]) == 1) {
                            cout << endl << "Student " << students[app3 - 20220000].getId()
                                 << " has a greater research score of " << students[app3 - 20220000].getResearchScore()
                                 << endl
                                 << "While student " << students[app4 - 20220000].getId()
                                 << " has a smaller research score of " << students[app4 - 20220000].getResearchScore()
                                 << endl;
                        } else if (compareResearchScore(students[app3 - 20220000], students[app4 - 20220000]) == 2) {
                            cout << endl << "Student " << students[app3 - 20220000].getId()
                                 << " has a smaller research score of " << students[app3 - 20220000].getResearchScore()
                                 << endl
                                 << "While student " << students[app4 - 20220000].getId()
                                 << " has a greater research score of " << students[app4 - 20220000].getResearchScore()
                                 << endl;
                        } else if (compareResearchScore(students[app1 - 20220000], students[app2 - 20220000]) == 3) {
                            cout << endl << "Student " << students[app3 - 20220000].getId() << " and student "
                                 << students[app4 - 20220000].getId()
                                 << " both have the same research score of "
                                 << students[app3 - 20220000].getResearchScore() << endl;

                        }
                        break;
                    case 3:
                        cout << endl << "Type in the first student's application number\n"
                             << ">> ";
                        int app5;
                        cin >> app5;
                        cout << endl << "Type in the second student's application number\n"
                             << ">> ";
                        int app6;
                        cin >> app6;

                        if (compareFirstName(students[app5 - 20220000], students[app6 - 20220000]) == 1) {
                            cout << "Applicant " << students[app5 - 20220000].getId()
                                 << " begins first with the first name " << students[app5 - 20220000].getFirstName()
                                 << endl
                                 << "Applicant " << students[app6 - 20220000].getId() << " comes second the first name "
                                 << students[app6 - 20220000].getFirstName() << endl;
                        }
                        if (compareFirstName(students[app5 - 20220000], students[app5 - 20220000]) == 2) {
                            cout << "Applicant " << students[app6 - 20220000].getId()
                                 << " begins first with the first name " << students[app6 - 20220000].getFirstName()
                                 << endl
                                 << "Applicant " << students[app5 - 20220000].getId() << " comes second the first name "
                                 << students[app5 - 20220000].getFirstName() << endl;
                        }
                        if (compareFirstName(students[app5 - 20220000], students[app6 - 20220000]) == 3) {
                            cout << "Both Applicants " << students[app5 - 20220000].getId() << " and "
                                 << students[app6 - 20220000].getId() << " share the same first name "
                                 << students[app5 - 20220000].getFirstName() << endl;
                        }
                        break;
                    case 4:
                        cout << endl << "Type in the first student's application number\n"
                             << ">> ";
                        int app7;
                        cin >> app7;
                        cout << endl << "Type in the second student's application number\n"
                             << ">> ";
                        int app8;
                        cin >> app8;

                        if (compareLastName(students[app7 - 20220000], students[app8 - 20220000]) == 1) {
                            cout << "Applicant " << students[app7 - 20220000].getId()
                                 << " begins first with the last name " << students[app7 - 20220000].getLastName()
                                 << endl
                                 << "Applicant " << students[app8 - 20220000].getId() << " comes second the last name "
                                 << students[app8 - 20220000].getLastName() << endl;
                        }
                        if (compareLastName(students[app7 - 20220000], students[app8 - 20220000]) == 2) {
                            cout << "Applicant " << students[app8 - 20220000].getId()
                                 << " begins first with the last name " << students[app8 - 20220000].getLastName()
                                 << endl
                                 << "Applicant " << students[app7 - 20220000].getId() << " comes second the last name "
                                 << students[app7 - 20220000].getLastName() << endl;
                        }
                        if (compareLastName(students[app7 - 20220000], students[app8 - 20220000]) == 3) {
                            cout << "Both Applicants " << students[app7 - 20220000].getId() << " and "
                                 << students[app8 - 20220000].getId() << " share the same last name"
                                 << students[app7 - 20220000].getLastName() << endl;
                        }

                        break;

                    default:
                        cin.clear();
                        cin.ignore();
                        cout << endl << "Invalid option selected" << endl;
                        break;
                }

                break;

            case 6: //Input of searching students based on app ID, cgpa & research score
                //Print out data that meets requirement
            {
                cout << "What field would you like to search by?\n"
                     << "Type 1 for applicant ID\n"
                     << "Type 2 for CGPA\n"
                     << "Type 3 for research score\n"
                     << ">> ";
                int in4;
                cin >> in4;
                switch (in4) {
                    case 1: {
                        cout << "Type in applicant ID\n"
                             << ">> ";
                        int searchId;
                        cin >> searchId;

                        break;
                    }
                    case 2: {
                        cout << "Type in cgpa\n"
                             << ">> ";
                        float searchCGPA;
                        cin >> searchCGPA;
                        break;
                    }
                    case 3: {
                        cout << "Type in research score\n"
                             << ">> ";
                        int searchResearchScore;
                        cin >> searchResearchScore;
                        break;
                    }
                    default:
                        cin.clear();
                        cin.ignore();
                        cout << endl << "Invalid option selected" << endl;
                        break;
                }

                break;
                case 7:
                    cout << endl << "Choose to add or delete a student" << endl
                         << "Type 1 to add domestic student\n"
                         << "Type 2 to delete domestic student\n"
                         << "Type 3 to add international student\n"
                         << "Type 4 to delete international student\n"
                         << ">>";
                int in5;
                cin >> in5;
                switch (in4) {

                    case 1: {
                        cout << endl << "Input first name: \n" << ">>";
                        cin >> add_fName;
                        cout << endl << "Input last name: \n" << ">>";
                        cin >> add_lName;
                        cout << endl << "Input cgpa: \n" << ">>";
                        cin >> add_cgpa;
                        cout << endl << "Input research score: \n" << ">>";
                        cin >> add_researchScore;
                        cout << endl << "Input province: \n" << ">>";
                        string add_province;
                        cin >> add_province;
                        ++id;
                        ++stu_count;
                        domesticStudents[stu_count] = DomesticStudent(add_fName, add_lName, add_cgpa, add_researchScore,
                                                                      add_province, id);
                        students[id] = Student(add_fName, add_lName, add_cgpa, add_researchScore, id);
                        cout << endl << "Creating student: \n";
                        break;
                    }
                    case 2: {
                        cout << "Insert first and last name of applicant to delete\n"
                             << " >>";

                    }
                    case 3: {
                        cout << endl << "Input first name: \n" << ">>";
                        cin >> add_fName;
                        cout << endl << "Input last name: \n" << ">>";
                        cin >> add_lName;
                        cout << endl << "Input cgpa: \n" << ">>";
                        cin >> add_cgpa;
                        cout << endl << "Input research score: \n" << ">>";
                        cin >> add_researchScore;
                        cout << endl << "Input country: \n" << ">>";
                        string add_country;
                        cin >> add_country;
                        cout << endl << "Input reading TOEFL score: \n" << ">>";
                        int add_reading;
                        cin >> add_reading;
                        cout << endl << "Input listening TOEFL score: \n" << ">>";
                        int add_listening;
                        cin >> add_listening;
                        cout << endl << "Input speaking TOEFL score: \n" << ">>";
                        int add_speaking;
                        cin >> add_speaking;
                        cout << endl << "Input writing TOEFL score: \n" << ">>";
                        int add_writing;
                        cin >> add_writing;
                        ++id;
                        ++stu_count;
                        internationalStudents[stu_count] = InternationalStudent(add_fName, add_lName, add_cgpa,
                                                                                add_researchScore, add_country,
                                                                                add_reading, add_listening,
                                                                                add_speaking, add_writing, id);
                        students[id] = Student(add_fName, add_lName, add_cgpa, add_researchScore, id);
                        cout << endl << "Creating student... \n";
                        break;
                    }
                    case 4: {
                        cout << "Insert first and last name of applicant to delete\n"
                             << " >>";
                    }


                }

                break;
                case 8:
                    break;
                case 9:
                    cout << "Exiting program..." << endl;
                    exit(1);
                break;

                default:
                    cin.clear();
                    cin.ignore();
                    cout << endl << "Invalid option selected" << endl;
                break;
            }
        }

        return 0;
    }
}