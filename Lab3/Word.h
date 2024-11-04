#ifndef WORD_H
#define WORD_H
#include <string>

using namespace std;

class Word {
private:
    string ukrainian;
    string english;
public:
    Word();
    Word(string ua, string en);
    string getua() const;
    string geteng() const;
    bool operator<(const Word& other) const;
    bool operator>=(const Word& other) const;
};

#endif 