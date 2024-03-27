#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_TOKENS_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_TOKENS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Tokens {
private:
    string name;
    string value;

public:
    Tokens(const string& _name, const string& _value) : name(_name), value(_value) {}

    string getName() const {
        return name;
    }

    string getValue() const {
        return value;
    }
};

#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_TOKENS_H