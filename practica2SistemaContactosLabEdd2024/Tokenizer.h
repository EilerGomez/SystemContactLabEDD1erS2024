#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_TOKENIZER_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_TOKENIZER_H

#include <vector>
#include <string>
#include <sstream>
#include "Tokens.h"
#include <regex>

using namespace std;

class Tokenizer {
public:
    static bool isValidDate(const string& dateStr) {
        regex dateRegex("^\\d{2}-\\d{2}-\\d{4}$");
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

    static bool isCorrect(vector<Tokens> tokens){
        bool iscorrect=false;
        int caso=0;
        for (const Tokens& token : tokens) {

            switch (caso) {
                case 0:
                    if(token.getName()=="ADD"){caso=1;}
                    else if(token.getName()=="FIND"){caso=16;}
                    break;
                case 1:
                    if(token.getName()=="NEW-GROUP"){caso=2;}
                    else if(token.getName()=="CONTACT"){caso=9;}
                    break;
                case 2:
                    if(token.getName()=="TEXTO_PLANO"){caso=3;}
                    break;
                case 3:
                    if(token.getName()=="FIELDS"){caso=4;}
                    break;
                case 4:
                    if(token.getName()=="APARENTESIS"){caso=5;}
                    break;
                case 5:
                    if(token.getName()=="TEXTO_PLANO"){caso=6;}
                    break;
                case 6:
                    if(token.getName()=="STRING"||token.getName()=="INTEGER"||token.getName()=="DATE"){
                        caso=7;
                    }else if(token.getName()=="CPARENTESIS"){caso=8;}
                    break;
                case 7:
                    if(token.getName()=="COMA"){caso=5;}
                    else if(token.getName()=="CPARENTESIS"){caso=8;}
                    break;
                case 8:
                    if(token.getName()=="FIN"){

                        iscorrect=true;//estado de aceptacion
                    }
                    break;
                case 9:
                    if(token.getName()=="IN"){caso=10;}
                    break;
                case 10:if(token.getName()=="TEXTO_PLANO"){caso=11;}
                    break;
                case 11:if(token.getName()=="FIELDS"){caso=12;}
                    break;
                case 12:if(token.getName()=="APARENTESIS"){caso=13;}
                    break;
                case 13:if(token.getName()=="TEXTO_PLANO"||token.getName()=="NUMERO"||token.getName()==
                "FECHA"||token.getName()=="CARACTER"){caso=14;}
                    break;
                case 14:if(token.getName()=="COMA"){caso=13;}
                        else if(token.getName()=="CPARENTESIS"){caso=15;}
                    break;
                case 15:if(token.getName()=="FIN"){
                    iscorrect= true;}//ESTADO DE ACEPTACION
                    break;
                case 16:if(token.getName()=="CONTACT"){caso=17;}
                    break;
                case 17:if(token.getName()=="IN"){caso=18;}
                    break;
                case 18:if(token.getName()=="TEXTO_PLANO"){caso=19;}
                    break;
                case 19:if(token.getName()=="CONTACT-FIELD"){caso=20;}
                    break;
                case 20:if(token.getName()=="TEXTO_PLANO"){caso=21;}
                    break;
                case 21:if(token.getName()=="COMPARACIONIGUAL"){caso=22;}
                    break;
                case 22:if(token.getName()=="TEXTO_PLANO"){caso=23;}
                    break;
                case 23:if(token.getName()=="FIN"){
                    iscorrect=true;}//ultimo estado de aceptacion
                    break;
                default:
                    break;
            }
            //cout<<caso<<endl;
        }

        return iscorrect;
    }
};

#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_TOKENIZER_H