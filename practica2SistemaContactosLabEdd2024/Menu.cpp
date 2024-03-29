#include "Menu.h"
#include "iostream"
using namespace std;
Menu::~Menu() {
    // Implementación del destructor
}
void Menu::inicio() {
    string input="nadaxd";
    vector<Tokens> tokens;
    ContactGroups contactos;
    int opcion = 1;
    while (opcion > 0) {
        cout << "Elija una opcion: " << endl;
        cout << "1. Consola " << endl << "2. Reportes " << endl << "3. Graficos " << endl << "4. Exportar" << endl;
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                while(input!="exit"){
                    cout << "[sys@contact] ~$ ";
                    std::getline(std::cin, input);
                    tokens = Tokenizer::tokenize(input);
                    /*for (const Tokens& token : tokens) {
                        cout << "Nombre: " << token.getName() << ", Valor: " << token.getValue() << endl;
                    }*/
                    int valorAceptacion=Tokenizer::isCorrect(tokens);
                    if(valorAceptacion==1){//fue agregacion de un grupo
                        //cout<<"El texto ingresado es correcto"<<endl;
                        int indicetab=contactos.insertGroup(Tokenizer::campo);
                        //cout<<"listo para insertar el grupo: "+Tokenizer::campo<<endl;
                        for(Tokenizer::estructura st: Tokenizer::campos){
                            contactos.insertField(Tokenizer::campo,st.value,st.name, indicetab);
                        }
                        contactos.printTable();
                        //cout<<Tokenizer::campos.size()<<endl;
                        cout<<"     Grupo y campos guardados correctamente "<<endl;
                        Tokenizer::campos.clear();
                    }else if(valorAceptacion==2){
                        int index=contactos.existGruop(Tokenizer::campo);
                        if(index!=-5){
                            cout<<"existe el grupo, en el indice "<<index<<endl;
                            if(contactos.traerTablaDeGrupo(index,Tokenizer::campo).fields.size()==Tokenizer::campos.size()){
                            //verifica si los parametros que le esta enviando son iguales a los que guardo
                            cout<<"Contiene la misma cantidad de parametros"<<endl;
                            }
                            cout<<contactos.traerTablaDeGrupo(index,Tokenizer::campo).fields.size()<<endl;
                            cout<<Tokenizer::campos.size()<<endl;
                            for(Tokenizer::estructura st:Tokenizer::campos){
                                cout<<st.name<<"-"<<st.value<<endl;
                            }
                        }else{
                            cout<<"el grupo no existe"<<endl;
                        }
                        Tokenizer::campos.clear();
                        contactos.printTable();
                    }
                    else{
                        if(input!="exit"){
                            cout<<"Comando no valido"<<endl;
                            Tokenizer::campos.clear();
                            input="nada";
                        }
                        Tokenizer::campos.clear();
                    }
                    Tokenizer::campos.clear();
                }
                input="nada";
                break;
            case 2:
                cout << "Seleccionó la opción de Reportes." << endl;
                break;
            case 3:
                cout << "Seleccionó la opción de Gráficos." << endl;
                break;
            case 4:
                cout << "Seleccionó la opción de Exportar." << endl;
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    }
}