//
// Created by eiler on 27/03/24.
//

#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_CONTACTGROUPS_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_CONTACTGROUPS_H
#include "FieldTable.h"

// Clase para representar la tabla hash de grupos de contactos
class ContactGroups {
private:
    static const int INITIAL_SIZE = 5; // Tamaño inicial de la tabla hash
    constexpr static const double LOAD_FACTOR_THRESHOLD=60; // Umbral de factor de carga para rehashing
    int numGroups; // Número de grupos de contactos
    int tableSize; // Tamaño actual de la tabla
    list<pair<string, FieldTable>>* table; // Tabla hash de grupos de contactos

    // Función hash para dar indice a la tabla
    int hash(const std::string& key) {
        int hashValue = 0;
        for (char c : key) {
            hashValue = (hashValue * 31 + static_cast<int>(c)) % tableSize;
        }
        return hashValue;
    }

    // Realizar rehashing cuando la carga excede el umbral
    void rehash() {
        int newSize = tableSize * 2;
        list<pair<string, FieldTable>>* newTable = new list<pair<string, FieldTable>>[newSize];

        for (int i = 0; i < tableSize; ++i) {
            for (const auto& pair : table[i]) {
                //int newIndex = hash(pair.first);
                newTable[i].push_back(pair);
            }
        }

        delete[] table;
        table = newTable;
        tableSize = newSize;
    }

    int verificarIndice(int indice){
        int index=indice;
        if(!table[index].empty()){
            cout<<"es espacio esta ocupado"<<endl;
            while (index<tableSize && !table[index].empty()){
                cout<<"buscando nuevo espacio"<<endl;
                index++;
            }
            if(!table[index].empty()){
                while (index>=0 && !table[index].empty()){
                    index--;
                }
            }
        }
        return index;
    }

public:
    ContactGroups() : numGroups(0), tableSize(INITIAL_SIZE) {
        table = new list<pair<string, FieldTable>>[tableSize];
    }

    ~ContactGroups() {
        delete[] table;
    }

    // Insertar un grupo de contactos
    int insertGroup(const string& groupName) {
        if ((numGroups * 100) / tableSize > LOAD_FACTOR_THRESHOLD) {
            rehash(); // Realizar rehashing si la carga supera el umbral
        }

        int index = hash(groupName);
        index=verificarIndice(index);
        table[index].push_back({groupName, FieldTable()});
        ++numGroups;
        return index;
    }
    //imprimir tabla
    void printTable() {
        for (int i = 0; i < tableSize; ++i) {
            std::cout << "Bucket " << i << ":" << std::endl;
            for (const auto& pair : table[i]) {
                std::cout << "    Group Name: " << pair.first << std::endl;
                std::cout << "    Fields:" << std::endl;
                pair.second.printFields(); // Método para imprimir los campos de FieldTable
            }
        }
    }

    // Insertar un campo en un grupo de contactos
    void insertField(const string& groupName, const string& fieldName, const string& value, int indice) {
        int index = indice;
        for (auto& pair : table[index]) {
            if (pair.first == groupName) {
                pair.second.insertField(fieldName, value);
                break;
            }
        }
    }

    // Obtener el valor de un campo en un grupo de contactos
    string getField(const string& groupName, const string& fieldName) {
        int index = hash(groupName);
        for (const auto& pair : table[index]) {
            if (pair.first == groupName) {
                return pair.second.getField(fieldName);
            }
        }
        return ""; // Devolver cadena vacía si el grupo no existe
    }

    int existGruop(const string& groupName){
        int exist = -5;
        int index = hash(groupName);
        for (const auto& pair : table[index]) {
            if (pair.first == groupName) {
                exist=index;
            }
        }
        if(exist<0){
            cout<<"el campo no se encuentra en el idice dado por el hash"<<endl;
            for (int i = index; i < tableSize; ++i) {
                for(const auto& pair : table[i]){
                    if(!table[i].empty()){
                        if (pair.first == groupName) {
                            exist=i;
                            i=tableSize;
                        }
                    }
                }
            }
            index = hash(groupName);
            cout<<index<<endl;
            if(exist<0){
                for (int i = index; i >=0 ; --i) {
                    for(const auto& pair : table[i]){
                        if(!table[i].empty()){
                            if (pair.first == groupName) {
                                exist=i;
                                i=-1;
                            }
                        }
                    }
                }
            }

        }
        return exist;
    }

    //devolver la lista de fields de un grupo dado su indice

    FieldTable traerTablaDeGrupo(int index, string groupName){
        FieldTable tmp;
        for (const auto& pair : table[index]) {
            if (pair.first == groupName) {
                return pair.second;
            }
        }

        return tmp;
    }

};




#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_CONTACTGROUPS_H
