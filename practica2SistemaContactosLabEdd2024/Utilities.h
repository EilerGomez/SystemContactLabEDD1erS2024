//
// Created by eiler on 28/03/24.
//

#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_UTILITIES_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_UTILITIES_H
#include "list"
#include "FieldTable.h"
#include "Tokenizer.h"

class Utilities {
public:
    Utilities();

    bool isCorrectUnityDate(string nameFt, string nameE){
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
        for (int i = 0; i < listFT.size(); ++i) {
            for (const auto& pair : listFT) {
                for(const auto& pairE : listE){
                    if(!isCorrectUnityDate(pair.name,pairE.name)){
                        iscorrect=false;
                        break;
                    }
                }

            }
        }

        return iscorrect;
    }

};


#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_UTILITIES_H
