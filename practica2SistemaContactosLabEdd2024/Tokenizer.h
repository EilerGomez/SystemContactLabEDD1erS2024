#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_TOKENIZER_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_TOKENIZER_H

#include <vector>
#include <string>
#include <sstream>
#include "Tokens.h"
#include <regex>
#include "list"
#include "FieldTable.h"

using namespace std;

class Tokenizer {


public:

    struct estructura{
        string name;
        string value;//o tipo STRING INTEGER, ETC
        //tiene que tener el puntero hacia un arbol

        estructura(const string& n, const string& v) : name(n), value(v) {}
    };
    static list<estructura> campos;
    static string campo;

    static bool isValidDate(const string& dateStr) {
        regex dateRegex("^\\d{4}-\\d{2}-\\d{2}$");
        return regex_match(dateStr, dateRegex);
    }
    static bool isNumeric(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    static vector<Tokens> tokenize(const string& input) {
        vector<Tokens> tokens;
        stringstream ss(input);
        string word;

        while (ss >> word) {
            if (word == "ADD") {
                tokens.push_back(Tokens("ADD", "ADD"));
            } else if (word == "STRING") {
                tokens.push_back(Tokens("STRING", "STRING"));
            } else if (word == ",") {
                tokens.push_back(Tokens("COMA", ","));
            } else if (word == ";") {
                tokens.push_back(Tokens("FIN", ";"));
            } else if (word == "(") {
                tokens.push_back(Tokens("APARENTESIS", "("));
            } else if (word == ")") {
                tokens.push_back(Tokens("CPARENTESIS", ")"));
            }else if(word=="NEW-GROUP"){
                tokens.push_back(Tokens("NEW-GROUP", "NEW-GROUP"));
            } else if(word=="FIELDS"){
                tokens.push_back(Tokens("FIELDS", "FIELDS"));
            }else if(word=="INTEGER"){
                tokens.push_back(Tokens("INTEGER", "INTEGER"));
            }else if(word=="DATE"){
                tokens.push_back(Tokens("DATE", "DATE"));
            }else if(word=="CHAR"){
                tokens.push_back(Tokens("CHAR", "CHAR"));
            }else if(word=="CONTACT"){
                tokens.push_back(Tokens("CONTACT", "CONTACT"));
            }else if(word=="IN"){
                tokens.push_back(Tokens("IN", "IN"));
            }else if(word=="FIND"){
                tokens.push_back(Tokens("FIND", "FIND"));
            }else if(word=="CONTACT-FIELD"){
                tokens.push_back(Tokens("CONTACT-FIELD", "CONTACT-FIELD"));
            }
            else if(word=="="){
                tokens.push_back(Tokens("COMPARACIONIGUAL", word));
            }
            else if(isValidDate(word)){
                tokens.push_back(Tokens("FECHA", word));
            }
            else if (isNumeric(word)) {
                tokens.push_back(Tokens("NUMERO", word));
            }else if(word.length()==1){
                tokens.push_back(Tokens("CARACTER", word));
            }
            else {
                tokens.push_back(Tokens("TEXTO_PLANO", word));
            }
        }

        return tokens;
    }

    static int isCorrect(vector<Tokens> tokens){
        int iscorrect=0;
        int caso=0;
        string n;
        string v;
        for (const Tokens& token : tokens) {

            switch (caso) {
                case 0:
                    if(token.getName()=="ADD"){caso=1;}
                    else if(token.getName()=="FIND"){caso=16;}
                    else{caso=-1;}
                    break;
                case 1:
                    if(token.getName()=="NEW-GROUP"){caso=2;}
                    else if(token.getName()=="CONTACT"){caso=9;}
                    else{caso=-1;}
                    break;
                case 2:
                    if(token.getName()=="TEXTO_PLANO"){
                        caso=3;
                        campo=token.getValue();
                    }
                    else{caso=-1;}
                    break;
                case 3:
                    if(token.getName()=="FIELDS"){caso=4;}
                    else{caso=-1;}
                    break;
                case 4:
                    if(token.getName()=="APARENTESIS"){caso=5;}
                    else{caso=-1;}
                    break;
                case 5:
                    if(token.getName()=="TEXTO_PLANO"){caso=6;
                        n=token.getValue();
                    }
                    else{caso=-1;}
                    break;
                case 6:
                    if(token.getName()=="STRING"||token.getName()=="INTEGER"||token.getName()=="DATE"
                    ||token.getName()=="CHAR"){
                        caso=7;
                        v=token.getName();
                        campos.push_back(estructura(n,v));
                    }else if(token.getName()=="CPARENTESIS"){caso=8;}
                    else{caso=-1;}
                    break;
                case 7:
                    if(token.getName()=="COMA"){caso=5;}
                    else if(token.getName()=="CPARENTESIS"){caso=8;}
                    else{caso=-1;}
                    break;
                case 8:
                    if(token.getName()=="FIN"){

                        iscorrect=1;//estado de aceptacion
                    }
                    else{caso=-1;}
                    break;
                case 9:
                    if(token.getName()=="IN"){caso=10;}
                    else{caso=-1;}
                    break;
                case 10:if(token.getName()=="TEXTO_PLANO"){
                    caso=11;
                    campo=token.getValue();
                    }
                    else{caso=-1;}
                    break;
                case 11:if(token.getName()=="FIELDS"){caso=12;}
                    else{caso=-1;}
                    break;
                case 12:if(token.getName()=="APARENTESIS"){caso=13;}
                    else{caso=-1;}
                    break;
                case 13:if(token.getName()=="TEXTO_PLANO"||token.getName()=="NUMERO"||token.getName()==
                            "FECHA"||token.getName()=="CARACTER"){
                    caso=14;
                    n=token.getName();
                    v=token.getValue();
                    campos.push_back(estructura(n,v));
                    }
                    else{caso=-1;}
                    break;
                case 14:if(token.getName()=="COMA"){caso=13;}
                        else if(token.getName()=="CPARENTESIS"){caso=15;}
                    else{caso=-1;}
                    break;
                case 15:if(token.getName()=="FIN"){
                    iscorrect= 2;}//ESTADO DE ACEPTACION
                    else{caso=-1;}
                    break;
                case 16:if(token.getName()=="CONTACT"){caso=17;}
                    else{caso=-1;}
                    break;
                case 17:if(token.getName()=="IN"){caso=18;}
                    else{caso=-1;}
                    break;
                case 18:if(token.getName()=="TEXTO_PLANO"){caso=19;
                        campo=token.getValue();
                    }
                    else{caso=-1;}
                    break;
                case 19:if(token.getName()=="CONTACT-FIELD"){caso=20;
                }
                    else{caso=-1;}
                    break;
                case 20:if(token.getName()=="TEXTO_PLANO"){caso=21;
                        n=token.getName();
                        v=token.getValue();
                        campos.push_back(estructura(n,v));
                    }
                    else{caso=-1;}
                    break;
                case 21:if(token.getName()=="COMPARACIONIGUAL"){caso=22;}
                    else{caso=-1;}
                    break;
                case 22:if(token.getName()=="TEXTO_PLANO"||token.getName()=="NUMERO"||token.getName()==
                    "FECHA"||token.getName()=="CARACTER"){caso=23;
                        n=token.getName();
                        v=token.getValue();
                        campos.push_back(estructura(n,v));
                    }
                    else{caso=-1;}
                    break;
                case 23:if(token.getName()=="FIN"){
                    iscorrect=3;}//ultimo estado de aceptacion
                    else{caso=-1;}
                    break;
                case -1:
                        iscorrect=-1;
                    break;
                default:
                    iscorrect=-1;
                    break;
            }
            //cout<<caso<<endl;
        }

        return iscorrect;
    }
};

#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_TOKENIZER_H