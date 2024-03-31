//
// Created by eiler on 28/03/24.
//

#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_ARBOLAVL_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_ARBOLAVL_H


#include <iostream>
#include "Date.h"
#include <vector>

using namespace std;

struct Nodo {
    string palabra;//funciona si son texto o caracteres
    Nodo* izquierda;
    Nodo* derecha;
    Nodo* siguiente;
    Nodo* anterior;//siguiente y anterior es para saber quienes pertenecen al mismo campo
    int altura;
};


class ArbolAVL {
public:
    ArbolAVL();
    void insertar(const string& palabra);
    void imprimirInOrder();
    vector<Nodo*> buscarElemento(const string& palabra);
    void buscarElemento(Nodo* nodo, const string& palabra, vector<Nodo*>& nodosEncontrados);
    Nodo* raiz;
    Nodo* insertado;
    int contarElementos(Nodo* nodo);
    int contarElementos();
    vector<Nodo*> obtenerTodosLosNodos();
    void obtenerTodosLosNodos(Nodo* nodo, vector<Nodo*>& todosLosNodos);

private:
    int altura(Nodo* nodo);
    int maximo(int a, int b);
    Nodo* rotarDerecha(Nodo* nodo);
    Nodo* rotarIzquierda(Nodo* nodo);
    Nodo* insertar(Nodo* nodo, const string& palabra);
    void imprimirInOrder(Nodo* nodo);
};

/*
int main() {
    ArbolAVL arbol;
    arbol.insertar(123456789);
    arbol.insertar(987654321);
    arbol.insertar(555555555);
    arbol.insertar(111111111);

    cout << "Recorrido in-order del árbol: ";
    arbol.imprimirInOrder();

    return 0;
}

*/

#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_ARBOLAVL_H
