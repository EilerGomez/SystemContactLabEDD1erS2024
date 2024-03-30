//
// Created by eiler on 29/03/24.
//

#include "Reportes.h"
#include "FieldTable.h"
using namespace std;
int Reportes::contarCantidadDatosPorGrupo(list<FieldTable::Field> fields) {
    int cantidad = 0;
    for (const auto& field : fields) {
        cantidad += field.arbol.contarElementos();
    }
    return cantidad;
}
int Reportes::contarDatosDeUnField(list <FieldTable::Field> fields) {
    int cantidad = 0;
    for (const auto& field : fields) {
        cantidad += field.arbol.contarElementos();
        break;
    }
    return cantidad;
}

void Reportes::cantidadDatosPorGrupo(list<pair<string, FieldTable>>* table, int tableSize) {
    for (int i = 0; i < tableSize; ++i) {

        if(!table[i].empty()){
            for (const auto& tabla : table[i]) {
                cout << "   Nombre de Grupo: " << tabla.first <<endl;
                cout << "       Cantidad de datos: " << contarCantidadDatosPorGrupo(tabla.second.fields) << endl;
            }

        }


    }
}
void Reportes::cantidadDatosTodoElSistema(list <std::pair<std::string, FieldTable>> *table, int tableSize) {
    int cantidad=0;
    for (int i = 0; i < tableSize; ++i) {
        if(!table[i].empty()){
            for (const auto& tabla : table[i]) {
                cantidad+= contarCantidadDatosPorGrupo(tabla.second.fields);
            }

        }
    }
    cout<<"     Cantidad de Datos de todo el sistema: "<<cantidad<<endl;
}

void Reportes::cantidadContactosPorGrupo(list <std::pair<std::string, FieldTable>> *table, int tableSize) {
    for (int i = 0; i < tableSize; ++i) {

        if(!table[i].empty()){
            for (const auto& tabla : table[i]) {
                cout << "   Nombre de Grupo: " << tabla.first <<endl;
                cout << "       Cantidad de contactos: " << contarDatosDeUnField(tabla.second.fields) << endl;
            }

        }


    }
}



