#pragma once
#include <string>

class Word {
public:
    std::string ukrainian;
    std::string english;

    Word();
    Word(std::string ua, std::string en);

    bool operator<(const Word& other) const;
    bool operator>=(const Word& other) const;
};

