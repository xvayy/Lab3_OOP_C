#pragma once
#include "Word.h"

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
    void sortWords();
    void printWords() const;
    Word findWord(const std::string& ua) const;
    void inputWords(int count);
};
