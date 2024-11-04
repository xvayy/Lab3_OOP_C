#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Word.h"

using namespace std;
class Dictionary {
private:
    Word* words;
    int size;
    int capacity;

public:
    Dictionary(int capacity);
    ~Dictionary();

    void addWord(const Word& word);
    void removeWord(const Word& word);
    void sortByUkrainian();
    void printWords() const;

    Dictionary& operator+(const Word& word);
    Dictionary& operator-(const Word& word);
    
    
};

#endif
