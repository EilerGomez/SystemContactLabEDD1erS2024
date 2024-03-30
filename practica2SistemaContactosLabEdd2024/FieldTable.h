//
// Created by eiler on 27/03/24.
//

#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_FIELDTABLE_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_FIELDTABLE_H

#include <iostream>
#include <list>
#include <string>
#include <cmath>
#include "ArbolAVL.h"

using namespace std;

// Clase para representar los campos de un grupo
class FieldTable {
public:
     struct Field {
        string name;
        string value;//o tipo STRING INTEGER, ETC
        //tiene que tener el puntero hacia un arbol
        mutable ArbolAVL arbol;

        Field(const string& n, const string& v, const ArbolAVL arbol) : name(n), value(v), arbol(arbol) {
        }
    };



public:
    list<Field> fields;
    void printFields() const {
        for (const auto& field : fields) {
            std::cout << "        " << field.name << ": " << field.value << std::endl;
            field.arbol.imprimirInOrder(); // Llama a la función de impresión directamente desde el objeto original
        }
    }

    // Insertar un campo en el grupo de contactos
    void insertField(const string& fieldName, const string& value) {
        ArbolAVL tmp = *new ArbolAVL();
        fields.push_back(Field(fieldName, value,tmp));
    }

    // Obtener el valor de un campo dado su nombre
    string getField(const string& fieldName) const {
        for (const auto& field : fields) {
            if (field.name == fieldName) {
                return field.value;
            }
        }
        return ""; // Devolver cadena vacía si el campo no existe
    }
    //obtener el arbol de un campo dado su nombre

    ArbolAVL getThreeAVL(const string& fieldName) const{
        for (const auto& field : fields) {
            if (field.name == fieldName) {
                return field.arbol;
            }
        }

    }

    //verificar si el campoexiste dado su nombre

    bool existCamp(const string& fieldName) const{
        bool exist=false;
        for (const auto& field : fields) {
            if (field.name == fieldName) {
                exist=true;
                break;
            }
        }
        return exist;
    }
};

#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_FIELDTABLE_H
