//
// Created by eiler on 01/04/24.
//

#ifndef PRACTICA2SISTEMADECONTACTOS_GRAFICAS_H
#define PRACTICA2SISTEMADECONTACTOS_GRAFICAS_H
#include "list"
#include "FieldTable.h"
using namespace std;
class Graficas {
public:
    void graficarTodaLaEstructura(list <std::pair<std::string, FieldTable>>* table, string filename,int sizeTable);
    bool esFecha(string& palabra);
    void graficarEstructuraConDatos(list <std::pair<std::string, FieldTable>>* table, string filename,int sizeTable);
    void graficarSoloUnaEstructra(list <std::pair<std::string, FieldTable>>* table, string filename,int index);

};


#endif //PRACTICA2SISTEMADECONTACTOS_GRAFICAS_H
