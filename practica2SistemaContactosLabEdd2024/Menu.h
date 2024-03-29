#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_MENU_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_MENU_H
#include "ContactGroups.h"
#include <iostream>
#include <vector>
#include <string>
#include "Tokenizer.h"
#include "Tokens.h"
#include "Utilities.h"

using namespace std;

class Menu {
public:
    void inicio();
    Utilities utilidades;
    ~Menu();
};

#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_MENU_H
