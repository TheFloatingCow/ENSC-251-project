//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"
#include "stu_sort.hpp"
#include "list.hpp"
#include <vector>

int main() {

    /** -------------------------Linked Lists------------------------- **/

    LinkedList<DomesticStudent> Dlist1;
    LinkedList<InternationalStudent> Ilist1;




    int id = 0;
    //Total Student Array
    Student students[200];
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
        domesticStudents[stu_count] = DomesticStudent(firstName, lastName, cgpa, researchScore, province, id);
        students[id] = Student(firstName, lastName, cgpa, researchScore, id);

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
        internationalStudents[stu_count] = InternationalStudent(firstName, lastName, cgpa, researchScore, country, reading, listening, speaking, writing, id);
        students[id] = Student(firstName, lastName, cgpa, researchScore, id);

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
        int input;
        int size_d = sizeof(domesticStudents)/sizeof(DomesticStudent);
        int size_i = sizeof(internationalStudents)/sizeof(InternationalStudent);
        cout << endl << "\nStudent Directory\n"
            << "Type 1 to print all domestic students\n"
            << "Type 2 to pring all international students\n"
            << "Type 3 to sort domestic students\n"
            << "Type 4 to sort international students\n"
            << "Type 5 to compare students\n"
            << "Type 6 to exit program\n"
            << ">> ";

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
                << "Type 5 for overall sort\n"
                << ">> ";
                int in1;
                cin >> in1;
                switch(in1) {

                    case 1:
                        // Sort by first name
                        sortDomestic(domesticStudents,"firstname",size_d);
                        for (int i = 0; i < 100; i++) {
                        cout << domesticStudents[i];
                        }
                    break;
                    case 2:
                        // Sort by last name
                        sortDomestic(domesticStudents,"lastname",size_d);
                        for (int i = 0; i < 100; i++) {
                        cout << domesticStudents[i];
                        }
                    break;
                    case 3:
                        // Sort by CGPA
                        sortDomestic(domesticStudents,"cgpa",size_d);
                        for (int i = 0; i < 100; i++) {
                        cout << domesticStudents[i];
                        }
                    break;
                    case 4:
                        // Sort by research score
                        sortDomestic(domesticStudents,"research",size_d);
                        for (int i = 0; i < 100; i++) {
                        cout << domesticStudents[i];
                        }
                    break;
                    case 5:
                        sortDomestic(domesticStudents, "overall",size_d);
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
                switch(in2) {
                    case 1:
                        // Sort by first name
                        sortInternational(internationalStudents,"firstname",size_i);
                        for (int i = 0; i < 100; i++) {
                        cout << internationalStudents[i];
                        }
                    break;
                    case 2:
                        // Sort by last name
                        sortInternational(internationalStudents,"lastname",size_i);
                        for (int i = 0; i < 100; i++) {
                        cout << internationalStudents[i];
                        }
                    break;
                    case 3:
                        // Sort by CGPA
                        sortInternational(internationalStudents,"cgpa",size_i);
                        for (int i = 0; i < 100; i++) {
                        cout << internationalStudents[i];
                        }
                    break;
                    case 4:
                        // Sort by research score
                        sortInternational(internationalStudents,"research",size_i);
                        for (int i = 0; i < 100; i++) {
                        cout << internationalStudents[i];
                        }
                    break;
                    case 5:
                        sortInternational(internationalStudents,"TOEFL",size_i);
                        for (int i = 0; i < 100; i++) {
                        cout << internationalStudents[i];
                        }
                    break;
                    case 6:
                        sortInternational(internationalStudents,"overall",size_i);
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

            case 6:
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