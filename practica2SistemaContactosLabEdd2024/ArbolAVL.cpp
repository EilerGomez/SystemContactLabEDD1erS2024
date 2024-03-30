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

Nodo* ArbolAVL::insertar(Nodo* nodo, const string& palabra) {
    if (nodo == nullptr) {
        Nodo* nuevo = new Nodo;
        nuevo->palabra = palabra;
        nuevo->izquierda = nullptr;
        nuevo->derecha = nullptr;
        nuevo->siguiente= nullptr;
        nuevo->anterior= nullptr;
        nuevo->altura = 1;
        insertado =nuevo;
        return nuevo;
    }

    if (palabra <= nodo->palabra) {
        nodo->izquierda = insertar(nodo->izquierda, palabra);
    } else {
        nodo->derecha = insertar(nodo->derecha, palabra);
    }

    nodo->altura = 1 + maximo(altura(nodo->izquierda), altura(nodo->derecha));

    int balance = altura(nodo->izquierda) - altura(nodo->derecha);

    // Casos de rotación
    if (balance > 1) {
        if (palabra <= nodo->izquierda->palabra) {
            return rotarDerecha(nodo);
        } else {//rotaciones dobles
            nodo->izquierda = rotarIzquierda(nodo->izquierda);
            return rotarDerecha(nodo);
        }
    }
    if (balance < -1) {
        if (palabra > nodo->derecha->palabra) {
            return rotarIzquierda(nodo);
        } else {
            nodo->derecha = rotarDerecha(nodo->derecha);
            return rotarIzquierda(nodo);
        }
    }

    return nodo;
}

void ArbolAVL::insertar(const string& palabra) {
    raiz = insertar(raiz, palabra);
}

void ArbolAVL::imprimirInOrder() {
    imprimirInOrder(raiz);
    cout << endl;
}

void ArbolAVL::imprimirInOrder(Nodo* nodo) {
    if (nodo != nullptr) {
        imprimirInOrder(nodo->izquierda);
        cout << nodo->palabra << " ";
        imprimirInOrder(nodo->derecha);
    }
}

vector<Nodo*> ArbolAVL::buscarElemento(const string& palabra) {
    vector<Nodo*> nodosEncontrados;
    buscarElemento(raiz, palabra, nodosEncontrados);
    return nodosEncontrados;
}

void ArbolAVL::buscarElemento(Nodo* nodo, const string& palabra, vector<Nodo*>& nodosEncontrados) {
    if (nodo == nullptr) {
        return;
    }

    buscarElemento(nodo->izquierda, palabra, nodosEncontrados);

    if (nodo->palabra == palabra) {
        nodosEncontrados.push_back(nodo);
    }

    buscarElemento(nodo->derecha, palabra, nodosEncontrados);
}


int ArbolAVL::contarElementos(Nodo* nodo) {
    if (nodo == nullptr) {
        return 0;
    }
    return 1 + contarElementos(nodo->izquierda) + contarElementos(nodo->derecha);
}
int ArbolAVL::contarElementos() {
    return contarElementos(raiz);
}

