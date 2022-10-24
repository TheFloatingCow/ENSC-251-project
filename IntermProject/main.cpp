//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"
#include "stu_sort.hpp"


int main() {

    int id = 0;

/** -------------------------DOMESTIC STUDENTS------------------------- **/

    // Domestic student array
    DomesticStudent domesticStudents[100];


    //Read the domestic-stu.txt file and exit if failed
    string line;
    ifstream domesticFile("domestic-stu.txt");
    if(!domesticFile.is_open()) {
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
    while( getline(domesticFile, line) ) {
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

        //get lastName separated by comma
        getline(ss, lastName, ',');

        //get province separated by comma
        getline(ss, province, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());

        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());
             
        //add values to array
        domesticStudents[stu_count] = DomesticStudent(firstName, lastName, cgpa, researchScore, province);

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
    if(!internationalFile.is_open()) {
        cout << "Unable to open file international-stu.txt" << endl;
        return -1;
    }

    //Read the first line of international-stu.txt
    getline(internationalFile, line);
    cout << "File format: " << line << endl;

    //Read the rest of the lines in international-stu.txt
    stu_count = 0;
    while( getline(internationalFile, line) ) {
        
        istringstream ss(line);

        //initialize variables
        string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
        float cgpa;
        int researchScore, reading, listening, speaking, writing;
        int TOEFL, TOEFL1, TOEFL2, TOEFL3, TOEFL4, TOEFL5;


        //get firstName separated by comma
        getline(ss, firstName, ',');

        //get lastName separated by comma
        getline(ss, lastName, ',');

        //get province separated by comma
        getline(ss, country, ',');

        //get cpga separated by comma, and convert string to float
        getline(ss, s_cgpa, ',');
        cgpa = atof(s_cgpa.c_str());
        
        //get researchScore separated by comma, and convert it to int
        getline(ss, s_researchScore, ',');
        researchScore = atoi(s_researchScore.c_str());

        //get reading separated by comma, and convert string to int
        getline(ss, s_reading, ',');
        reading = atoi(s_reading.c_str());

        //get listening separated by comma, and convert string to int
        getline(ss, s_listening, ',');
        listening = atoi(s_listening.c_str());

        //get speaking separated by comma, and convert string to int
        getline(ss, s_speaking, ',');
        speaking = atoi(s_speaking.c_str());

        //get writing separated by comma, and convert string to int
        getline(ss, s_writing, ',');
        writing = atoi(s_writing.c_str());

        // Add values to array
        internationalStudents[stu_count] = InternationalStudent(firstName, lastName, cgpa, researchScore, country, reading, listening, speaking, writing);

        stu_count++;
        id++;
    }

    //close international file
    internationalFile.close();

    for (int i = 0; i < 100; i++) {
        cout << internationalStudents[i];
    }


    /** -------------------------Main function loop------------------------- **/

    while(true) {
        cout << endl << "\nStudent Directory\n"
        << "Type 1 to print all domestic students\n"
        << "Type 2 to pring all international students\n"
        << "Type 3 to sort domestic students\n"
        << "Type 4 to sort international students\n"
        << "Type 9 to exit program\n"
        << ">> ";

        int input;
        cin >> input;
        switch(input) {
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
                << ">> ";
                int in1;
                cin >> in1;
                switch(in1) {
                    case 1:
                        // Sort by first name
                        d_firstName_sort(domesticStudents);
                        for (int i = 0; i < 100; i++) {
                        cout << domesticStudents[i];
                        }
                    break;
                    case 2:
                        // Sort by last name
                        d_lastName_sort(domesticStudents);
                        for (int i = 0; i < 100; i++) {
                        cout << domesticStudents[i];
                        }
                    break;
                    case 3:
                        // Sort by CGPA
                        d_cgpa_sort(domesticStudents);
                        for (int i = 0; i < 100; i++) {
                        cout << domesticStudents[i];
                        }
                    break;
                    case 4:
                        // Sort by research score
                        d_researchScore_sort(domesticStudents);
                        for (int i = 0; i < 100; i++) {
                        cout << domesticStudents[i];
                        }
                    break;
                }
            break;
            case 4: //international
                cout << endl << "What field would you like to sort by\n"
                << "Type 1 for first name\n"
                << "Type 2 for last name\n"
                << "Type 3 for CGPA\n"
                << "Type 4 for research score\n"
                << ">> ";
                int in2;
                cin >> in2;
                switch(in2) {
                    case 1:
                        // Sort by first name
                        i_firstName_sort(internationalStudents);
                        for (int i = 0; i < 100; i++) {
                        cout << internationalStudents[i];
                        }
                    break;
                    case 2:
                        // Sort by last name
                        i_lastName_sort(internationalStudents);
                        for (int i = 0; i < 100; i++) {
                        cout << internationalStudents[i];
                        }
                    break;
                    case 3:
                        // Sort by CGPA
                        i_cgpa_sort(internationalStudents);
                        for (int i = 0; i < 100; i++) {
                        cout << internationalStudents[i];
                        }
                    break;
                    case 4:
                        // Sort by research score
                        i_researchScore_sort(internationalStudents);
                        for (int i = 0; i < 100; i++) {
                        cout << internationalStudents[i];
                        }
                    break;
                }
            break;
            case 9:
                cout << "Exiting program..." << endl;
                exit(1);
            break;
        }
    }

    return 0;
}
