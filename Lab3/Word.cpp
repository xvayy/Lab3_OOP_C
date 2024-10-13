#include "Word.h"

Word::Word() {
    this->ukrainian = "";
    this->english = "";
}

Word::Word(std::string ua, std::string en) {
    this->ukrainian = ua;
    this->english = en;
}

bool Word::operator<(const Word& other) const {
    return this->ukrainian < other.ukrainian;
}

bool Word::operator>=(const Word& other) const {
    return this->ukrainian >= other.ukrainian;
}
