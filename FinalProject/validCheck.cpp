// Functions for checking validity of inputs
#include "validCheck.hpp"
using namespace std;

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

// Check for typos, output false when no typo found (could still be wrong word)
// Sort words (using bubble sort) alphabetically and compare
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

// Helper Functions
// Keep asking for valid input until one is given
int validInputId(){
    int id;
    cout << "Enter Application ID: ";
    cin >> id;
    cout << "\n";

    // bad user input
    while(!cin.good()){
        cin.clear();
        cin.ignore();
        // Ask again
        cout << "Enter Application ID: ";
        cin >> id;
        cout << "\n";
    }

    return id;
}

float validInputCGPA(){
    float input;
    cout << "Enter CGPA: ";
    cin >> input;
    cout << "\n";

    // bad user input
    while(!cin.good()){
        cin.clear();
        cin.ignore();
        // Ask again
        cout << "Enter CGPA: ";
        cin >> input;
        cout << "\n";
    }
    return input;
}

int validInputResearch(){
    int score;
    cout << "Enter Research Score: ";
    cin >> score;
    cout << "\n";

    // bad user input
    while(!cin.good()){
        cin.clear();
        cin.ignore();
        // Ask again
        cout << "Enter Application ID: ";
        cin >> score;
        cout << "\n";
    }
    return score;
}

string validFirstName(){
    string first;
    cout << "Enter First Name: ";
    cin >> first;
    cout << "\n";

    // bad user input
    while(!cin.good()){
        cin.clear();
        cin.ignore();
        // Ask again
        cout << "Enter First Name: ";
        cin >> first;
        cout << "\n";
    }
    return first;
}

string validLastName(){
    string last;
    cout << "Enter Last Name: ";
    cin >> last;
    cout << "\n";

    // bad user input
    while(!cin.good()){
        cin.clear();
        cin.ignore();
        // Ask again
        cout << "Enter Last Name: ";
        cin >> last;
        cout << "\n";
    }
    return last;
}

string validInputProvince(){
    string provinces[13] = {"NL","PE","NS","NB","QC","ON","MB","SK","AB","BC","YT","NT","NU"};
    string province;
    bool valid = false;

    cout << "Enter Province: ";
    cin >> province;
    cout << "\n";

    for(int i = 0; i < 13; i++){
        if(province == provinces[i]){
            valid = true;
            break;
        }
    }
    // bad user input
    while(!cin.good() || !valid){
        cin.clear();
        cin.ignore();
        // Ask again
        cout << "Enter Valid Province:: ";
        cin >> province;
        cout << "\n";

        for(int i = 0; i < 13; i++){
            if(province == provinces[i]){
                valid = true;
                break;
            }
        }
    }
    return province;
}

string validInputCountry(){
    string countries[5] = {"Canada","China","India","Iran","Korea"};
    string country;
    bool valid = false;

    cout << "Enter Country: ";
    cin >> country;
    cout << "\n";

    for(int i = 0; i < 13; i++){
        if(country == countries[i]){
            valid = true;
            break;
        }
    }
    // bad user input
    while(!cin.good() || !valid){
        cin.clear();
        cin.ignore();
        // Ask again
        cout << "Enter Valid Province:: ";
        cin >> country;
        cout << "\n";

        for(int i = 0; i < 13; i++){
            if(country == countries[i]){
                valid = true;
                break;
            }
        }
    }
    return country;
}

int validToefl(string type){
    int input;

    cout << "Enter " + type + ": ";
    cin >> input;
    cout << "\n";

    // bad user input
    while(!cin.good() || !(input >= 0 && input <= 30)){
        cin.clear();
        cin.ignore();
        // Ask again
        cout << "Enter " + type + ": ";;
        cin >> input;
        cout << "\n";
    }
    return input;
}