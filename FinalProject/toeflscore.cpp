#include "toeflscore.hpp"

// Default Constructor
ToeflScore::ToeflScore(){
    // init all scores to 0
    reading = 0;
    writing = 0;
    listening = 0;
    speaking = 0;

    totalScore = 0;
}

// Parameter Constructor
ToeflScore::ToeflScore(int _reading, int _speaking, int _writing, int _listening){
    reading = _reading;
    writing = _writing;
    speaking = _speaking;
    listening = _listening;

    totalScore = reading+writing+speaking+listening;
}

// Copy Constructor
ToeflScore::ToeflScore(const ToeflScore& ts){
    reading = ts.reading;
    writing = ts.writing;
    speaking = ts.speaking;
    listening = ts.listening;

    totalScore = ts.totalScore;
}

// Getters
int ToeflScore::get_reading() const{
    return reading;
}
int ToeflScore::get_speaking() const{
    return speaking;
}
int ToeflScore::get_writing() const{
    return writing;
}
int ToeflScore::get_listening() const{
    return listening;
}
int ToeflScore::get_totalScore() const{
    return totalScore;
}

// Setters
void ToeflScore::set_reading(int _reading){
    reading = _reading;
    // update total score
    totalScore = reading+speaking+listening+writing;
}

void ToeflScore::set_writing(int _writing){
    writing = _writing;
    // update total score
    totalScore = reading+speaking+listening+writing;
}

void ToeflScore::set_listening(int _listening){
    listening = _listening;
    // update total score
    totalScore = reading+speaking+listening+writing;
}

void ToeflScore::set_speaking(int _speaking){
    speaking = _speaking;
    // update total score
    totalScore = reading+speaking+listening+writing;
}