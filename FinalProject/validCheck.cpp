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