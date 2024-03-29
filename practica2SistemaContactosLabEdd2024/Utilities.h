//
// Created by eiler on 28/03/24.
//

#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_UTILITIES_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_UTILITIES_H
#include "list"
#include "FieldTable.h"
#include "Tokenizer.h"
#include "vector"

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

};


#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_UTILITIES_H
