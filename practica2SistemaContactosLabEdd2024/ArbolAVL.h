//
// Created by eiler on 28/03/24.
//

#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_ARBOLAVL_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_ARBOLAVL_H


#include <iostream>
#include "Date.h"
using namespace std;

struct Nodo {
    string texto;//funciona si son texto o caracteres
    Date fecha;//si el arbol es para fechas
    int telefono;//si es numero mas comun es que sea telefono
    Nodo* izquierda;
    Nodo* derecha;
    int altura;
};

class ArbolAVL {
public:
    ArbolAVL();
    void insertar(int telefono);
    void insertarTxt(string txt);
    void insertarFecha(Date fecha);
    void imprimirInOrder();

private:
    Nodo* raiz;

    int altura(Nodo* nodo);
    int maximo(int a, int b);
    Nodo* rotarDerecha(Nodo* nodo);
    Nodo* rotarIzquierda(Nodo* nodo);
    Nodo* insertar(Nodo* nodo, int telefono);
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
