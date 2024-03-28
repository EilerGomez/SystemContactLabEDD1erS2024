//
// Created by eiler on 27/03/24.
//

#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_FIELDTABLE_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_FIELDTABLE_H

#include <iostream>
#include <list>
#include <string>
#include <cmath>

using namespace std;

// Clase para representar los campos de un grupo
class FieldTable {
private:
    struct Field {
        string name;
        string value;//o tipo STRING INTEGER, ETC
        //tiene que tener el puntero hacia un arbol

        Field(const string& n, const string& v) : name(n), value(v) {}
    };

    list<Field> fields;

public:
    void printFields() const {
        for (const auto& pair : fields) {
            std::cout << "        " << pair.name << ": " << pair.value << std::endl;
        }
    }
    // Insertar un campo en el grupo de contactos
    void insertField(const string& fieldName, const string& value) {
        fields.push_back(Field(fieldName, value));
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
};

#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_FIELDTABLE_H
