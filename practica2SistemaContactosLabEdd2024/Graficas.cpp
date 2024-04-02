//
// Created by eiler on 01/04/24.
//

#include "Graficas.h"
#include <iostream>
#include <fstream>
#include <functional>
#include <regex>
using namespace std;


bool Graficas::esFecha(string& palabra) {
    std::regex regexFecha("\\d{4}-\\d{2}-\\d{2}");

    return std::regex_match(palabra, regexFecha);
}

void Graficas::graficarTodaLaEstructura(list <std::pair<std::string, FieldTable>> *tables, string filename, int sizeTable) {

    ofstream dotFile(filename);
    if (!dotFile) {
        cerr << "Error: No se puede abrir el archivo DOT." << endl;
        return;
    }

    dotFile << "digraph AVLTree {" << endl;
    string general="CONTACTOS";
    dotFile << "label=\"" << general << "\";" << endl; // Agregar nombre del árbol
    dotFile << "labelloc=top;" << endl; // Colocar el nombre del árbol encima
    // Función auxiliar para generar nodos y conexiones recursivamente

    int uniqueId = 0; // Contador para nodos con el mismo nombre
    for (int i = 0; i < sizeTable; ++i) {
        if(!tables[i].empty()){
            for (const auto& pair : tables[i]) {
                string campo = pair.first;
                dotFile << campo << "_" << uniqueId << " [label=\"" << campo << "\", shape=plaintext];" << endl;
                int fieldId = 0; // Contador para nodos de campos
                for (const auto& field : pair.second.fields) {
                    string campoSep = campo + "_campoSep_" + to_string(fieldId) + "_" + to_string(uniqueId);
                    dotFile << campoSep << " [label=\"" << field.value << "\", shape=plaintext];" << endl;
                    dotFile << campo << "_" << uniqueId << "-> " << campoSep << ";" << endl; // Flecha apuntando a la raíz

                    ++fieldId;
                }
                ++uniqueId;
            }
        }
    }

    dotFile << "}" << endl;
    dotFile.close();
}

void Graficas::graficarEstructuraConDatos(list <std::pair<std::string, FieldTable>> *tables, std::string filename,
                                          int sizeTable) {
    ofstream dotFile(filename);
    if (!dotFile) {
        cerr << "Error: No se puede abrir el archivo DOT." << endl;
        return;
    }

    dotFile << "digraph AVLTree {" << endl;
    string general="CONTACTOS";
    dotFile << "label=\"" << general << "\";" << endl; // Agregar nombre del árbol
    dotFile << "labelloc=top;" << endl; // Colocar el nombre del árbol encima
    // Función auxiliar para generar nodos y conexiones recursivamente
    int i=0;
    function<void(Nodo*)> generateNodes = [&](Nodo* node) {
        if (node == nullptr) return;

        string nodoPalabra;
        if (esFecha(node->palabra)) { // Suponiendo que tienes una función esFecha para verificar si la palabra es una fecha
            nodoPalabra = "\"" + node->palabra + "\""; // Envuelve la fecha entre comillas
        } else {
            nodoPalabra = node->palabra;
        }

        dotFile << nodoPalabra << " [label=\"" << node->palabra << "\\n" << node->altura << "\"];" << endl;


        if (node->izquierda != nullptr) {
            string nodoIzquierda;
            nodoIzquierda = "\"" + node->izquierda->palabra + "\"";

            dotFile << nodoPalabra << " -> " << nodoIzquierda << ";" << endl;
            generateNodes(node->izquierda);
        }

        if (node->derecha != nullptr) {

            string nodoDerecha;
            nodoDerecha = "\"" + node->derecha->palabra + "\"";

            dotFile << nodoPalabra << " -> " << nodoDerecha << ";" << endl;
            generateNodes(node->derecha);
        }
    };

    int uniqueId = 0; // Contador para nodos con el mismo nombre
    for (int i = 0; i < sizeTable; ++i) {
        if(!tables[i].empty()){
            for (const auto& pair : tables[i]) {
                string campo = pair.first;
                dotFile << campo << "_" << uniqueId << " [label=\"" << campo << "\", shape=plaintext];" << endl;
                int fieldId = 0; // Contador para nodos de campos
                for (const auto& field : pair.second.fields) {
                    string campoSep = campo + "_campoSep_" + to_string(fieldId) + "_" + to_string(uniqueId);
                    dotFile << campoSep << " [label=\"" << field.value << "\", shape=plaintext];" << endl;
                    dotFile << campo << "_" << uniqueId << "-> " << campoSep << ";" << endl; // Flecha apuntando a la raíz
                    string nodo="\"" + field.arbol.raiz->palabra + "\"";
                    dotFile << campoSep << "-> " << nodo << ";" << endl;
                    generateNodes(field.arbol.raiz);
                    ++fieldId;
                }
                ++uniqueId;
            }
        }
    }

    dotFile << "}" << endl;
    dotFile.close();
}

void Graficas::graficarSoloUnaEstructra(list <std::pair<std::string, FieldTable>> *table, std::string filename,
                                        int index) {
    ofstream dotFile(filename);
    if (!dotFile) {
        cerr << "Error: No se puede abrir el archivo DOT." << endl;
        return;
    }

    dotFile << "digraph AVLTree {" << endl;
    string general="CONTACTOS";
    dotFile << "label=\"" << general << "\";" << endl; // Agregar nombre del árbol
    dotFile << "labelloc=top;" << endl; // Colocar el nombre del árbol encima
    // Función auxiliar para generar nodos y conexiones recursivamente
    int i=0;
    function<void(Nodo*)> generateNodes = [&](Nodo* node) {
        if (node == nullptr) return;

        string nodoPalabra;
        if (esFecha(node->palabra)) { // Suponiendo que tienes una función esFecha para verificar si la palabra es una fecha
            nodoPalabra = "\"" + node->palabra + "\""; // Envuelve la fecha entre comillas
        } else {
            nodoPalabra = node->palabra;
        }

        dotFile << nodoPalabra << " [label=\"" << node->palabra << "\\n" << node->altura << "\"];" << endl;


        if (node->izquierda != nullptr) {
            string nodoIzquierda;
            nodoIzquierda = "\"" + node->izquierda->palabra + "\"";

            dotFile << nodoPalabra << " -> " << nodoIzquierda << ";" << endl;
            generateNodes(node->izquierda);
        }

        if (node->derecha != nullptr) {

            string nodoDerecha;
            nodoDerecha = "\"" + node->derecha->palabra + "\"";

            dotFile << nodoPalabra << " -> " << nodoDerecha << ";" << endl;
            generateNodes(node->derecha);
        }
    };

    int uniqueId = 0; // Contador para nodos con el mismo nombre
    for (const auto& pair : table[index]) {
        string campo = pair.first;
        dotFile << campo << "_" << uniqueId << " [label=\"" << campo << "\", shape=plaintext];" << endl;
        int fieldId = 0; // Contador para nodos de campos
        for (const auto& field : pair.second.fields) {
            string campoSep = campo + "_campoSep_" + to_string(fieldId) + "_" + to_string(uniqueId);
            dotFile << campoSep << " [label=\"" << field.value << "\", shape=plaintext];" << endl;
            dotFile << campo << "_" << uniqueId << "-> " << campoSep << ";" << endl; // Flecha apuntando a la raíz
            string nodo="\"" + field.arbol.raiz->palabra + "\"";
            dotFile << campoSep << "-> " << nodo << ";" << endl;
            generateNodes(field.arbol.raiz);
            ++fieldId;
        }
        ++uniqueId;
    }

    dotFile << "}" << endl;
    dotFile.close();

}