//
// Created by eiler on 29/03/24.
//

#ifndef PRACTICA2SISTEMADECONTACTOS_REPORTES_H
#define PRACTICA2SISTEMADECONTACTOS_REPORTES_H
#include <list>
#include <string>
#include "FieldTable.h" // Asegúrate de incluir el archivo correcto aquí

class Reportes {
public:
    int contarCantidadDatosPorGrupo(list<FieldTable::Field> fields);
    int contarDatosDeUnField(list<FieldTable::Field> fields);
    void cantidadDatosPorGrupo(list<std::pair<std::string, FieldTable>>* table,int tableSize);
    void cantidadDatosTodoElSistema(list<std::pair<std::string, FieldTable>>* table,int tableSize);
    void cantidadContactosPorGrupo(list<std::pair<std::string, FieldTable>>* table,int tableSize);
};





#endif //PRACTICA2SISTEMADECONTACTOS_REPORTES_H
