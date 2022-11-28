//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"
#include "validCheck.hpp"
#include "list.hpp"



    /** ------------------------Error checking------------------------ **/

string validCountries[5] = {"Canada", "China", "India", "Iran", "Korea"};
string validProvinces[13] = {"NL", "PE", "NS", "NB", "QC", "ON", "MB", "SK", "AB", "BC", "YT", "NT", "NU"};



int main() {

   /** -------------------------Linked Lists------------------------- **/

    LinkedList<DomesticStudent> domestic_list;
    LinkedList<InternationalStudent> international_list;

    LinkedList<DomesticStudent> test_domestic_list;
    LinkedList<InternationalStudent> test_international_list;

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
    //cout << "File format: " << line << endl;

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
        if (cgpa > 4.33 || cgpa < 0) {
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
        test_domestic_list.insert(new_student);

        stu_count++;
        id++;
    }

    //close domestic file
    domesticFile.close();





    /** -------------------------INTERNATIONAL STUDENTS------------------------- **/

    string line2;
    ifstream internationalFile("international-stu.txt");
    if (!internationalFile.is_open()) {
        cout << "Unable to open file international-stu.txt" << endl;
        return -1;
    }

    //Read the first line of international-stu.txt
    getline(internationalFile, line);
    //cout << "File format: " << line << endl;

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
        if (cgpa > 4.33 || cgpa < 0) {
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
        if (reading > 30 || reading < 0) {
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
        if (listening > 30 || listening < 0) {
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
        if (speaking > 30 || speaking < 0) {
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
        if (writing > 30 || writing < 0) {
            cout << "Error in line " << stu_count + 2 << ": Writing score is invalid" << endl;
            exit(1);
        }

        InternationalStudent student = InternationalStudent(firstName, lastName, cgpa, researchScore, country, reading, listening, speaking, writing, id);
        students[id] = Student(firstName, lastName, cgpa, researchScore, id);

        // check toefl requirements
        if(student.meetToeflRequirements()){
            if (!international_list.insert(student)) {
                cout << "Error inserting student in line " << stu_count + 2 << endl;
                exit(1);
            }
            test_international_list.insert(student);
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





    /** -------------------------Unit testing------------------------- **/

    cout << "UNIT TEST 1---------------------------------------------------" << endl;

    // 1 Insert a DomesticStudent (and InternationalStudent) object into the DomesticStudent (and
    //InternationalStudent) singly linked list in order

    // Normal case (should return true)
    DomesticStudent domesticStudent1 = DomesticStudent("Geoffrey", "Smith", 4.0, 63, "BC", 225);
    InternationalStudent internationalStudent1 = InternationalStudent("Josephine", "McJosephine", 1.2, 99, "India", 12, 15, 22, 11, 251);
    if (domestic_list.insert(domesticStudent1) && international_list.insert(internationalStudent1)) {
        cout << "-------- Passed unit test 1 normal" << endl;
    }
    else {
        cout << "-------- Failed unit test 1 normal" << endl;
    }

    // Corner case (should return true)
    DomesticStudent domesticStudent2 = DomesticStudent("Geoffrey2", "Smith", 4.3, 63, "BC", 134);
    InternationalStudent internationalStudent2 = InternationalStudent("Josephine2", "McJosephine", 0, 100, "China", 0, 2, 30, 0, 9999);
    if (domestic_list.insert(domesticStudent2) && international_list.insert(internationalStudent2)) {
        cout << "-------- Passed unit test 1 corner" << endl;
    }
    else {
        cout << "-------- Failed unit test 1 corner" << endl;
    }

    // Illegal case (should return false)
    DomesticStudent domesticStudent3 = DomesticStudent("", "Smith", 5.0, -55, "BC", 55);
    InternationalStudent internationalStudent3 = InternationalStudent();
    if (domestic_list.insert(domesticStudent3) || international_list.insert(internationalStudent3)) {
        cout << "-------- Failed unit test 1 illegal" << endl;
    }
    else {
        cout << "-------- Passed unit test 1 illegal" << endl;
    }

    cout << "UNIT TEST 2---------------------------------------------------" << endl;

    // 2 Search existing DomesticStudent (and InternationalStudent) objects in the
    //DomesticStudent (and InternationalStudent) linked list based on the user input information
    //“application id”, or “cgpa”, or “researchScore”

    // Normal case (should return true)
    if (domestic_list.searchApplication(20220020) && domestic_list.searchCGPA(3.4) && domestic_list.searchResearch(94)
    && international_list.searchApplication(20220150) && international_list.searchCGPA(3.7) && international_list.searchResearch(95)) {
        cout << "-------- Passed unit test 2 normal" << endl;
    }
    else {
        cout << "-------- Failed unit test 2 normal" << endl;
    }

    // Corner case (Should return false)
    if (domestic_list.searchApplication(20229999) && domestic_list.searchCGPA(0.05) && domestic_list.searchResearch(5)
        && international_list.searchApplication(20224942) && international_list.searchCGPA(1.00) && international_list.searchResearch(20)) {
        cout << "-------- Failed unit test 2 corner" << endl;
    }
    else {
        cout << "-------- Passed unit test 2 corner" << endl;
    }

    // Illegal case (should return false)
    if (domestic_list.searchApplication(-45) || domestic_list.searchCGPA(4.34) || domestic_list.searchResearch(101)
        || international_list.searchApplication(-20220011) || international_list.searchCGPA(-1) || international_list.searchResearch(-4)) {
        cout << "-------- Failed unit test 2 illegal" << endl;
    }
    else {
        cout << "-------- Passed unit test 2 illegal" << endl;
    }

    cout << "UNIT TEST 3---------------------------------------------------" << endl;

    // 3 Search existing DomesticStudent (and InternationalStudent) objects in the
    //DomesticStudent (and InternationalStudent) linked list based on the user input information
    //“firstName and lastName”

    // Normal case (should return true)
    if (domestic_list.searchName("Lucas", "Cook") && international_list.searchName("Jiho","Chung")) {
        cout << "-------- Passed unit test 3 normal" << endl;
    }
    else {
        cout << "-------- Failed unit test 3 normal" << endl;
    }

    // Corner case (should return true)
    if (domestic_list.searchName("Mary", "White") && international_list.searchName("Guanyin", "Yang")) {
        cout << "-------- Passed unit test 3 corner" << endl;
    }
    else {
        cout << "-------- Failed unit test 3 corner" << endl;
    }

    // Illegal case (should return false)
    if (domestic_list.searchName("-89", "/'") || international_list.searchName("/'897", "...")) {
        cout << "-------- Failed unit test 3 illegal" << endl;
    }
    else {
        cout << "-------- Passed unit test 3 illegal" << endl;
    }

    cout << "UNIT TEST 4---------------------------------------------------" << endl;

    // 4 Delete existing DomesticStudent (and InternationalStudent) objects in the
    //DomesticStudent (and InternationalStudent) linked list based on the user input information
    //“firstName and lastName”

    // Normal case (should return true)
    if (domestic_list.remove("Mary", "White") && international_list.remove("Guanyin", "Yang")) {
        cout << "-------- Passed unit test 4 normal" << endl;
    }
    else {
        cout << "-------- Failed unit test 4 normal" << endl;
    }

    // Corner case (should return false because they have already been removed)
    if (domestic_list.remove("Mary", "White") && international_list.remove("Guanyin","Yang")) {
        cout << "-------- Failed unit test 4 corner" << endl;
    }
    else {
        cout << "-------- Passed unit test 4 corner" << endl;
    }

    // Illegal case (should return false)
    if (domestic_list.remove("Marty", "White") || international_list.remove("GU@NY!N", "Yang")) {
        cout << "-------- Failed unit test 4 illegal" << endl;

    }
    else {
        cout << "-------- Passed unit test 4 illegal" << endl;
    }

    cout << "UNIT TEST 5---------------------------------------------------" << endl;

    // 5 Delete both the head node and tail node from the DomesticStudent (and
    //InternationalStudent) linked list in a single delete function

    // Normal case (should return true)
    if (domestic_list.removeHeadTail() && international_list.removeHeadTail()) {
        cout << "-------- Passed unit test 5 normal" << endl;
    }
    else {
        cout << "-------- Failed unit test 5 normal" << endl;
    }

    // Corner case (should return true: 2 students)
    LinkedList<DomesticStudent> testDom1;
    LinkedList<InternationalStudent> testInt1;

    LinkedList<DomesticStudent> testDom2;
    LinkedList<InternationalStudent> testInt2;

    testDom1.insert(DomesticStudent("Samantha", "Smith", 4.1, 90, "BC", 122));
    testDom1.insert(DomesticStudent("Joe", "Schlesinger", 4.2, 63, "BC", 123));

    testInt1.insert(InternationalStudent("Josephine", "McJosephine", 1.2, 99, "India", 98, 99, 65, 97, 124));
    testInt1.insert(InternationalStudent("baguette", "croissant", 1.2, 99, "Korea", 98, 99, 44, 97, 125));

    if (testDom1.removeHeadTail() && testInt1.removeHeadTail()) {
        cout << "-------- Passed unit test 5 corner" << endl;
    }
    else {
        cout << "-------- Failed unit test 5 corner" << endl;
    }

    // Illegal case (should return false: empty lists)
    if (testDom2.removeHeadTail() && testDom2.removeHeadTail()) {
        cout << "-------- Failed unit test 5 illegal" << endl;
    }
    else {
        cout << "-------- Passed unit test 5 illegal" << endl;
    }

    cout << "UNIT TEST 6---------------------------------------------------" << endl;

    // 6 Merge the two sorted DomesticStudent and InternationalStudent linked lists into a single
    //Student linked list

    // Normal case
    LinkedList<Student> testMerge1;
    LinkedList<Student> testMerge2;
    LinkedList<Student> testMerge3;

    LinkedList<Student> test_domestic_2;
    LinkedList<Student> test_international_2;
    LinkedList<Student> test_domestic_3;
    LinkedList<Student> test_international_3;

    test_domestic_2.insert(DomesticStudent("Geoffrey", "Smith", 4.0, 63, "BC", 518));
    test_international_2.insert(InternationalStudent("Josephine", "McJosephine", 1.2, 99, "India", 98, 99, 64, 97, 9999));


    bool exception_caught = true;
    try {
        while(test_domestic_list.getHead() != nullptr){
            Student newStudent(test_domestic_list.getHead()->data);
            newStudent.setType(true);
            newStudent.setHome(test_domestic_list.getHead()->data.getHome());
            testMerge1.insert(newStudent);

            // remove head
            test_domestic_list.removeHead();
        }

        // add international students
        while(test_international_list.getHead() != nullptr){
            Student newStudent(test_international_list.getHead()->data);
            newStudent.setType(false);
            newStudent.setHome(test_international_list.getHead()->data.getHome());
            testMerge1.insert(newStudent);

            // remove head
            test_international_list.removeHead();
        }
        exception_caught = false;
    }
    catch (const exception&) {
        cout << "-------- Failed unit test 6 normal" << endl;
    }
    if (!exception_caught) {
        cout << "-------- Passed unit test 6 normal" << endl;
    }


    // Corner case
    exception_caught = true;
    try {
        while(test_domestic_2.getHead() != nullptr){
            Student newStudent(test_domestic_2.getHead()->data);
            newStudent.setType(true);
            newStudent.setHome(test_domestic_2.getHead()->data.getHome());
            testMerge2.insert(newStudent);

            // remove head
            test_domestic_2.removeHead();
        }

        // add international students
        while(test_international_2.getHead() != nullptr){
            Student newStudent(test_international_2.getHead()->data);
            newStudent.setType(false);
            newStudent.setHome(test_international_2.getHead()->data.getHome());
            testMerge2.insert(newStudent);

            // remove head
            test_international_2.removeHead();
        }
        exception_caught = false;
    }
    catch (const exception&) {
        cout << "-------- Failed unit test 6 corner" << endl;
    }
    if (!exception_caught) {
        cout << "-------- Passed unit test 6 corner" << endl;
    }

    // Illegal case (Empty lists: should still work)
    exception_caught = true;
    try {
        while(test_domestic_3.getHead() != nullptr){
            Student newStudent(test_domestic_3.getHead()->data);
            newStudent.setType(true);
            newStudent.setHome(test_domestic_3.getHead()->data.getHome());
            testMerge1.insert(newStudent);

            // remove head
            test_domestic_3.removeHead();
        }

        // add international students
        while(test_international_3.getHead() != nullptr){
            Student newStudent(test_international_3.getHead()->data);
            newStudent.setType(false);
            newStudent.setHome(test_international_3.getHead()->data.getHome());
            testMerge1.insert(newStudent);

            // remove head
            test_international_3.removeHead();
        }
        exception_caught = false;
    }
    catch (const exception&) {
        cout << "-------- Failed unit test 6 illegal" << endl;
    }
    if (!exception_caught) {
        cout << "-------- Passed unit test 6 illegal" << endl;
    }


    cout << "UNIT TEST 7---------------------------------------------------" << endl;

    // 7 Search existing Student objects in the merged linked list based on the user input
    //information “cgpa_threshold and researchScore_threshold”

    // Normal case
    if (testMerge1.thresholdCGPA(4.1) && testMerge1.thresholdResearch(98)) {
        cout << "-------- Passed unit test 7 normal" << endl;
    }
    else {
        cout << "-------- Failed unit test 7 normal" << endl;
    }

    // Corner case
    if (testMerge1.thresholdCGPA(4.33) && testMerge1.thresholdResearch(100)) {
        cout << "-------- Passed unit test 7 corner" << endl;
    }
    else {
        cout << "-------- Failed unit test 7 corner" << endl;
    }

    // Illegal case
    if (testMerge1.thresholdCGPA(9.2) && testMerge1.thresholdResearch(101)) {
        cout << "-------- Failed unit test 7 illegal" << endl;
    }
    else {
        cout << "-------- Passed unit test 7 illegal" << endl;
    }


    /** -------------------------Main function loop------------------------- **/

    LinkedList<Student> merge;

    while(true) {
        int input;
        cout << endl << "\nStudent Directory\n"
            << "Type 1 to Print all Domestic Students\n"
            << "Type 2 to Print all International Students\n"
            << "Type 3 to Print Merged List\n"
            << "Type 4 for Domestic Student Functions\n"
            << "Type 5 for International Student Functions\n"
            << "Type 6 for Merge List Functions\n"
            << "Type 7 to Merge Linked Lists\n"
            << "Type 8 to Compare Students\n"
            << "Type 9 to exit program\n"
            << ">> ";

        cin >> input;

        switch(input) {
            case 1:
                domestic_list.printList(domestic_list.getHead());
            break;
            case 2:
                international_list.printList(international_list.getHead());
            break;
            case 3:{
                merge.printList(merge.getHead());
                break;
            }
            case 4: //domestic
                cout << endl << "Domestic Functions: \n"
                << "Type 1 to Search by Application ID\n"
                << "Type 2 to Search by CGPA\n"
                << "Type 3 to Search by Research Score\n"
                << "Type 4 to Search by Firstname and Lastname\n"
                << "Type 5 to Insert a New Student\n"
                << "Type 6 to Delete by Firstname and Lastname\n"
                << "Type 7 to Delete Head and Tail Node\n"
                << "Type 8 to exit program\n"
                << ">> ";
                int in1;
                cin >> in1;
                switch(in1) {
                    case 1:
                        domestic_list.searchApplication(validInputId());
                    break;
                    case 2:
                        // Seach by CGPA
                        cout << endl << "Search by specific CGPA score or a minimum threshold?\n"
                        << "Type 1 for specific score\n"
                        << "Type 2 for minimum score\n"
                        << ">> ";
                        
                        int search1;
                        cin >> search1;
                        switch(search1) {
                            case 1:
                                domestic_list.searchCGPA(validInputCGPA());
                            break;
                            case 2:
                                domestic_list.thresholdCGPA(validInputCGPA());
                            break;
                            default:
                                cin.clear();
                                cin.ignore();
                                cout << endl << "Invalid option selected" << endl;
                            break;
                        
                        }
                    break;
                    case 3:
                        // Search by Research
                        cout << endl << "Search by specific research score or a minimum threshold?\n"
                        << "Type 1 for specific score\n"
                        << "Type 2 for minimum score\n"
                        << ">> ";
                        
                        int search2;
                        cin >> search2;
                        switch(search2) {
                            case 1:
                                domestic_list.searchResearch(validInputResearch());
                            break;
                            case 2:
                                domestic_list.thresholdResearch(validInputResearch());
                            break;
                            default:
                                cin.clear();
                                cin.ignore();
                                cout << endl << "Invalid option selected" << endl;
                            break;
                        
                        }
                    break;
                    case 4: {
                        // Search by First and Last name
                        domestic_list.searchName(validFirstName(),validLastName());
                        
                    break;
                    }
                    case 5: {
                        // insert new student
                        DomesticStudent new_student = DomesticStudent(validFirstName(),validLastName(),validInputCGPA(),validInputResearch(),validInputProvince(),validInputId());
                        domestic_list.insert(new_student);
                        break;
                    }
                    case 6: {
                        // delete student
                        domestic_list.remove(validFirstName(),validLastName());
                        break;
                    }
                    case 7: {
                        domestic_list.removeHeadTail();
                        break;
                    }
                    case 8:
                        cout << "Exiting program..." << endl;
                        exit(1);
                    break;

                    default:
                        cin.clear();
                        cin.ignore();
                        cout << endl << "Invalid option selected" << endl;
                    break;
                }
            break;
            case 5: //international
                cout << endl << "International Functions: \n"
                << "Type 1 to Search by Application ID\n"
                << "Type 2 to Search by CGPA\n"
                << "Type 3 to Search by Research Score\n"
                << "Type 4 to Search by Firstname and Lastname\n"
                << "Type 5 to Insert a New Student\n"
                << "Type 6 to Delete by Firstname and Lastname\n"
                << "Type 7 to Delete Head and Tail\n"
                << "Type 8 to exit program\n"
                << ">> ";
                int in2;
                cin >> in2;
                switch(in2) {
                    case 1:
                        // Search by Application id
                        international_list.searchApplication(validInputId());
                    break;
                    case 2:
                        // Seach by CGPA
                        cout << endl << "Search by specific CGPA score or a minimum threshold?\n"
                        << "Type 1 for specific score\n"
                        << "Type 2 for minimum score\n"
                        << ">> ";
                        
                        int search3;
                        cin >> search3;
                        switch(search3) {
                            case 1:
                                international_list.searchCGPA(validInputCGPA());
                            break;
                            case 2:
                                international_list.thresholdCGPA(validInputCGPA());
                            break;
                            default:
                                cin.clear();
                                cin.ignore();
                                cout << endl << "Invalid option selected" << endl;
                            break;
                        
                        }
                    break;
                    case 3:
                        // Search by Research
                        cout << endl << "Search by specific research score or a minimum threshold?\n"
                        << "Type 1 for specific score\n"
                        << "Type 2 for minimum score\n"
                        << ">> ";
                        
                        int search4;
                        cin >> search4;
                        switch(search4) {
                            case 1:
                                international_list.searchResearch(validInputResearch());
                            break;
                            case 2:
                                international_list.thresholdResearch(validInputResearch());
                            break;
                            default:
                                cin.clear();
                                cin.ignore();
                                cout << endl << "Invalid option selected" << endl;
                            break;
                        }
                    break;
                    case 4:
                        // Search Name
                        international_list.searchName(validFirstName(),validLastName());
                    break;
                    case 5: {
                        // Insert student
                        InternationalStudent new_student = InternationalStudent(validFirstName(),validLastName(),validInputCGPA(),
                            validInputResearch(),validInputCountry(),validToefl("Reading"), validToefl("Listening"), validToefl("Speaking"), validToefl("Writing"),validInputId());
                        international_list.insert(new_student);
                    break;
                    }
                    case 6: {
                        international_list.remove(validFirstName(),validLastName());
                    break;
                    }
                    case 7:{
                        international_list.removeHeadTail();
                        break;
                    }
                    case 8: {
                        exit(1);
                    break;
                    }
                    default:
                        cin.clear();
                        cin.ignore();
                        cout << endl << "Invalid option selected" << endl;
                    break;
                }
            break;
            case 6:{
                cout << endl << "Merge Functions: \n"
                << "Type 1 to Search by Threshold\n"
                << "Type 2 to Search by Application ID\n"
                << "Type 3 to Search by CGPA\n"
                << "Type 4 to Search by Research Score\n"
                << "Type 5 to Search by Firstname and Lastname\n"
                << "Type 6 to Insert a New Domestic Student\n"
                << "Type 7 to Insert a New International Student\n"
                << "Type 8 to Delete by Firstname and Lastname\n"
                << "Type 9 to Delete Head and Tail Node\n"
                << "Type 10 to exit program\n"
                << ">> ";
                int in1;
                cin >> in1;
                switch(in1) {
                    case 1:{
                        std::cout << "Enter CGPA and Research Score Threshold: ";
                        merge.threshold(validInputCGPA(),validInputResearch());
                        break;
                    }
                    case 2:
                        merge.searchApplication(validInputId());
                    break;
                    case 3:{
                        merge.searchCGPA(validInputCGPA());
                        break;
                        }
                    break;
                    case 4:{
                        merge.searchResearch(validInputResearch());
                        break;
                    }
                    case 5: {
                        // Search by First and Last name
                        merge.searchName(validFirstName(),validLastName());
                        
                    break;
                    }
                    case 6: {
                        // insert new student
                        DomesticStudent new_student = DomesticStudent(validFirstName(),validLastName(),validInputCGPA(),validInputResearch(),validInputProvince(),validInputId());
                        Student stu(new_student);
                        stu.setHome(new_student.getHome());
                        merge.insert(stu);
                        break;
                    }
                    case 7:{
                        // Insert student
                        InternationalStudent new_student = InternationalStudent(validFirstName(),validLastName(),validInputCGPA(),
                            validInputResearch(),validInputCountry(),validToefl("Reading"), validToefl("Listening"), validToefl("Speaking"), validToefl("Writing"),validInputId());
                        Student stu(new_student);
                        stu.setHome(new_student.getHome());
                        merge.insert(stu);
                        break;
                    }
                    case 8: {
                        // delete student
                        merge.remove(validFirstName(),validLastName());
                        break;
                    }
                    case 9: {
                        merge.removeHeadTail();
                        break;
                    }
                    case 10:
                        cout << "Exiting program..." << endl;
                        exit(1);
                    break;

                    default:
                        cin.clear();
                        cin.ignore();
                        cout << endl << "Invalid option selected" << endl;
                    break;
                }
                break;
            }
            case 7:{
                // Merge Lists
                // add domestic students
                while(domestic_list.getHead() != nullptr){
                    Student newStudent(domestic_list.getHead()->data);
                    newStudent.setType(true);
                    newStudent.setHome(domestic_list.getHead()->data.getHome());
                    merge.insert(newStudent);

                    // remove head
                    domestic_list.removeHead();
                }

                // add international students
                while(international_list.getHead() != nullptr){
                    Student newStudent(international_list.getHead()->data);
                    newStudent.setType(false);
                    newStudent.setHome(international_list.getHead()->data.getHome());
                    merge.insert(newStudent);

                    // remove head
                    international_list.removeHead();
                }

                // print list 
                merge.printList(merge.getHead());

                break;
            }
            case 8: //Input of comparing based on student applicant ID
                cout << endl << "What field would you want to compare by\n"
                << "Type 1 for cgpa\n"
                << "Type 2 for research score\n"
                << "Type 3 for first name\n"
                << "Type 4 for last name\n"
                << ">>";
                int in3;
                cin >> in3;
                switch(in3){
                case 1:
                    cout << endl << "Type in the first student's application number\n"
                    << ">> ";
                    int app1;
                    cin >> app1;
                    cout << endl << "Type in the second student's application number\n"
                    << ">> ";
                    int app2;
                    cin >> app2;

                    if(compareCGPA(students[app1-20220000], students[app2-20220000]) == 1)
                    {
                        cout << endl << "Student " << students[app1-20220000].getId() << " has a greater CGPA of " << students[app1-20220000].getCGPA() << endl
                        << "While student " << students[app2-20220000].getId() << " has a smaller CGPA of " << students[app2-20220000].getCGPA() << endl;
                    } else if(compareCGPA(students[app1-20220000], students[app2-20220000]) == 2)
                    {
                        cout << endl << "Student " << students[app1-20220000].getId() << "has a smaller CGPA of " << students[app1-20220000].getCGPA() << endl
                        << "While student " << students[app2-20220000].getId() << " has a greater CGPA of " << students[app2-20220000].getCGPA() << endl;
                    } else if(compareCGPA(students[app1-20220000], students[app2-20220000]) == 3)
                    {
                        cout << endl << "Student " << students[app1-20220000].getId() << " and student " << students[app2-20220000].getId()
                        << " both have the same CGPA of " << students[app2-20220000].getCGPA() << endl;
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
                    if(compareResearchScore(students[app3-20220000], students[app4-20220000]) == 1)
                    {
                        cout << endl << "Student " << students[app3-20220000].getId() << " has a greater research score of " << students[app3-20220000].getResearchScore() << endl
                        << "While student " << students[app4-20220000].getId() << " has a smaller research score of " << students[app4-20220000].getResearchScore() << endl;
                    } else if(compareResearchScore(students[app3-20220000], students[app4-20220000]) == 2)
                    {
                        cout << endl << "Student " << students[app3-20220000].getId() << " has a smaller research score of " << students[app3-20220000].getResearchScore() << endl
                        << "While student " << students[app4-20220000].getId() << " has a greater research score of " << students[app4-20220000].getResearchScore() << endl;
                    } else if(compareResearchScore(students[app1-20220000], students[app2-20220000]) == 3)
                    {
                        cout << endl << "Student " << students[app3-20220000].getId() << " and student " << students[app4-20220000].getId()
                        << " both have the same research score of " << students[app3-20220000].getResearchScore() << endl;

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
                    
                    if(compareFirstName(students[app5-20220000], students[app6-20220000]) == 1)
                    {
                        cout << "Applicant " << students[app5-20220000].getId() << " begins first with the first name " << students[app5-20220000].getFirstName() << endl
                        << "Applicant " << students[app6-20220000].getId() << " comes second the first name " << students[app6-20220000].getFirstName() << endl;
                    }
                    if(compareFirstName(students[app5-20220000], students[app5-20220000]) == 2)
                    {
                        cout << "Applicant " << students[app6-20220000].getId() << " begins first with the first name " << students[app6-20220000].getFirstName() << endl
                        << "Applicant " << students[app5-20220000].getId() << " comes second the first name " << students[app5-20220000].getFirstName() << endl;
                    }
                    if(compareFirstName(students[app5-20220000], students[app6-20220000]) == 3)
                    {
                        cout << "Both Applicants " << students[app5-20220000].getId() << " and " << students[app6-20220000].getId() << " share the same first name "
                        << students[app5-20220000].getFirstName() << endl;
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
                    
                    if(compareLastName(students[app7-20220000], students[app8-20220000]) == 1)
                    {
                        cout << "Applicant " << students[app7-20220000].getId() << " begins first with the last name " << students[app7-20220000].getLastName() << endl
                        << "Applicant " << students[app8-20220000].getId() << " comes second the last name " << students[app8-20220000].getLastName() << endl;
                    }
                    if(compareLastName(students[app7-20220000], students[app8-20220000]) == 2)
                    {
                        cout << "Applicant " << students[app8-20220000].getId() << " begins first with the last name " << students[app8-20220000].getLastName() << endl
                        << "Applicant " << students[app7-20220000].getId() << " comes second the last name " << students[app7-20220000].getLastName() << endl;
                    }
                    if(compareLastName(students[app7-20220000], students[app8-20220000]) == 3)
                    {
                        cout << "Both Applicants " << students[app7-20220000].getId() << " and " << students[app8-20220000].getId() << " share the same last name"
                        << students[app7-20220000].getLastName() << endl;
                    }

                break;

                default:
                    cin.clear();
                    cin.ignore();
                    cout << endl << "Invalid option selected" << endl;
                break;
                }

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