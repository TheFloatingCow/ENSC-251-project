#ifndef Toefl_HG
#define Toefl_HG

#include <string> //you will have to use string in C++
#include <iostream>
using namespace std; //use namespace std

class ToeflScore{
protected:
    // Variables
    // Scores range from 0 to 30
    int reading;
    int speaking;
    int writing;
    int listening;
    int totalScore;
public:
    ToeflScore(); // Default Constructor
    ToeflScore(int _reading, int _speaking, int _writing, int _listening);
    ToeflScore(const ToeflScore& ts); // Copy Constructor

    // Getters
    int get_reading() const;
    int get_speaking() const;
    int get_writing() const;
    int get_listening() const;
    int get_totalScore() const;

    // Setters
    void set_reading(int _reading);
    void set_speaking(int _speaking);
    void set_writing(int _writing);
    void set_listening(int _listening);
};






#endif