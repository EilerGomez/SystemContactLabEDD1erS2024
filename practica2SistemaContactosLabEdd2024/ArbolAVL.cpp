//
// Created by eiler on 28/03/24.
//

#include "ArbolAVL.h"
#include "Date.h"

ArbolAVL::ArbolAVL() : raiz(nullptr) {}

int ArbolAVL::altura(Nodo* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}

int ArbolAVL::maximo(int a, int b) {
    return (a > b) ? a : b;
}

Nodo* ArbolAVL::rotarDerecha(Nodo* nodo) {
    Nodo* izquierda = nodo->izquierda;
    Nodo* temp = izquierda->derecha;

    izquierda->derecha = nodo;
    nodo->izquierda = temp;

    nodo->altura = maximo(altura(nodo->izquierda), altura(nodo->derecha)) + 1;
    izquierda->altura = maximo(altura(izquierda->izquierda), altura(izquierda->derecha)) + 1;

    return izquierda;
}

Nodo* ArbolAVL::rotarIzquierda(Nodo* nodo) {
    Nodo* derecha = nodo->derecha;
    Nodo* temp = derecha->izquierda;

    derecha->izquierda = nodo;
    nodo->derecha = temp;

    nodo->altura = maximo(altura(nodo->izquierda), altura(nodo->derecha)) + 1;
    derecha->altura = maximo(altura(derecha->izquierda), altura(derecha->derecha)) + 1;

    return derecha;
}

Nodo* ArbolAVL::insertar(Nodo* nodo, int telefono) {
    if (nodo == nullptr) {
        Nodo* nuevo = new Nodo;
        nuevo->telefono = telefono;
        nuevo->izquierda = nullptr;
        nuevo->derecha = nullptr;
        nuevo->altura = 1;
        return nuevo;
    }

    if (telefono < nodo->telefono) {
        nodo->izquierda = insertar(nodo->izquierda, telefono);
    } else if (telefono > nodo->telefono) {
        nodo->derecha = insertar(nodo->derecha, telefono);
    } else {
        return nodo; // Si el número ya existe, no hacemos nada
    }

    nodo->altura = 1 + maximo(altura(nodo->izquierda), altura(nodo->derecha));

    int balance = altura(nodo->izquierda) - altura(nodo->derecha);

    // Casos de rotación
    if (balance > 1 && telefono < nodo->izquierda->telefono) {
        return rotarDerecha(nodo);
    }
    if (balance < -1 && telefono > nodo->derecha->telefono) {
        return rotarIzquierda(nodo);
    }
    if (balance > 1 && telefono > nodo->izquierda->telefono) {
        nodo->izquierda = rotarIzquierda(nodo->izquierda);
        return rotarDerecha(nodo);
    }
    if (balance < -1 && telefono < nodo->derecha->telefono) {
        nodo->derecha = rotarDerecha(nodo->derecha);
        return rotarIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVL::insertar(int telefono) {
    raiz = insertar(raiz, telefono);
}

void ArbolAVL::imprimirInOrder() {
    imprimirInOrder(raiz);
    cout << endl;
}

void ArbolAVL::imprimirInOrder(Nodo* nodo) {
    if (nodo != nullptr) {
        imprimirInOrder(nodo->izquierda);
        cout << nodo->telefono << " ";
        imprimirInOrder(nodo->derecha);
    }
}
