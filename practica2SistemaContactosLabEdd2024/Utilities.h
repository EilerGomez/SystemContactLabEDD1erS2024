//
// Created by eiler on 28/03/24.
//

#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_UTILITIES_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_UTILITIES_H
#include "list"
#include "FieldTable.h"
#include "Tokenizer.h"
#include "vector"
#include "iostream"
#include "ArbolAVL.h"

class Utilities {
public:
    Utilities();

    bool isCorrectUnityDate(string nameFt, string nameE){
        cout<<"comparando "<<nameFt<<" == "<<nameE<<endl;
        bool iscorrect=false;
        if(nameFt=="STRING"&&nameE=="TEXTO_PLANO"){
            iscorrect=true;
        }else if(nameFt=="INTEGER"&&nameE=="NUMERO"){
            iscorrect=true;
        }else if(nameFt=="DATE"&&nameE=="FECHA"){
            iscorrect=true;
        }else if(nameFt=="CHAR"&&nameE=="CARACTER"){
            iscorrect=true;
        }

        return iscorrect;
    }
    bool isCompatibily(list<FieldTable::Field> listFT,list<Tokenizer::estructura> listE){
        bool iscorrect=true;
            vector<string> listFtmp;
            vector<string> listEtmp;
        for (const auto& pair : listFT) {
            listFtmp.push_back(pair.name);
        }
        for(Tokenizer::estructura st:listE){
            listEtmp.push_back(st.name);
        }
        for (int i = 0; i < listFtmp.size(); ++i) {
            if(!isCorrectUnityDate(listFtmp[i],listEtmp[i])){
                iscorrect=false;
                break;
            }
        }


        return iscorrect;
    }

    void insertarANodos(list<FieldTable::Field>& listFT, list<Tokenizer::estructura> listE) {
        vector<string> listEtmp;
        for (const auto& st : listE) {
            listEtmp.push_back(st.value);
        }

        Nodo* tmp = nullptr;
        int i = 0;
        for (const auto& pair : listFT) {
            pair.arbol.insertar(listEtmp[i]);
            if (i == 0) {
                tmp = pair.arbol.insertado;
                tmp->anterior=nullptr;
            } else if (i == listEtmp.size() - 1) {
                tmp->siguiente = pair.arbol.insertado;
                pair.arbol.insertado->anterior=tmp;
                pair.arbol.insertado->siguiente = nullptr;
                tmp=pair.arbol.insertado;
            } else {
                tmp->siguiente = pair.arbol.insertado;
                pair.arbol.insertado->anterior = tmp;
                tmp = pair.arbol.insertado;
            }
            i++;
        }

        while(tmp!=nullptr){
            cout<<tmp->palabra<<" --- ";
            tmp=tmp->anterior;
        }
        cout<<endl;
    }

    void llevarAlInicio(Nodo* &tmp){
        while(tmp->anterior != nullptr){
            tmp = tmp->anterior;
        }
    }

    void imprimirContacto(Nodo* nodo, vector<string> fields){
        int i = 0;
        cout << "CONTACTO: [ ";
        while(nodo != nullptr){
            cout << fields[i] << " : " << nodo->palabra << " ";
            nodo = nodo->siguiente; // Avanzar al siguiente nodo
            i++;
        }
        cout << " ]" << endl;
    }

    void imprimirBusqueda(vector<Nodo*> nodos, vector<string> fields){
        for(Nodo* nodo : nodos){
            llevarAlInicio(nodo);
            imprimirContacto(nodo, fields);
        }
    }




};


#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_UTILITIES_H
