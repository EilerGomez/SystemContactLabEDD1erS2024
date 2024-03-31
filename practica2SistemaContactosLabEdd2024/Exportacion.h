//
// Created by eiler on 31/03/24.
//

#ifndef PRACTICA2SISTEMADECONTACTOS_EXPORTACION_H
#define PRACTICA2SISTEMADECONTACTOS_EXPORTACION_H
#include "iostream"
#include "FieldTable.h"
#include "ContactGroups.h"
#include "Tokenizer.h"
#include "vector"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
class Exportacion {
public:

    void exportar(list <std::pair<std::string, FieldTable>>* table, int index, string groupname);
    vector<string> traerFieldsDeGrupo(list<pair<string, FieldTable>>* table, int indice);
    string contacto(Nodo* nodo, vector<string> fields);
    fs::path crearCarpeta(string nombreCarpeta);

    void crearGuardarArchivo(fs::path folderPath, string nameTxt, string txt);
};


#endif //PRACTICA2SISTEMADECONTACTOS_EXPORTACION_H
