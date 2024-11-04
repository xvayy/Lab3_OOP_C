#include "Word.h"

Word::Word() {
    this->ukrainian = "";
    this->english = "";
}

Word::Word(string ua, string en){
    this->ukrainian = ua;
    this->english = en;
}

string Word::getua() const {
    return ukrainian;
}

string Word::geteng() const {
    return english;
}

bool Word::operator<(const Word& other) const {
    return ukrainian < other.ukrainian;
}

bool Word::operator>=(const Word& other) const {
    return ukrainian >= other.ukrainian;
}
