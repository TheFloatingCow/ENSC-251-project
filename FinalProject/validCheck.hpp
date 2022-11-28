// Valid check header file for checking if student is valid
#ifndef VALIDCHECK_HPP
#define VALIDCHECK_HPP

#include <iostream> //cin and cout
#include <vector>
#include <string>

using namespace std;

// Compare chars
bool compareChar(char& c1, char& c2);
// Compare strings (non case-sensitive)
bool stringCompare(string str1, string arr[], int size);
// Check for typo
string typoCheck(string str1, string arr[]);

// Helper Functions
int validInputId();
float validInputCGPA();
int validInputResearch();
string validFirstName();
string validLastName();
string validInputProvince();
string validInputCountry();
int validToefl(string type);


#endif
