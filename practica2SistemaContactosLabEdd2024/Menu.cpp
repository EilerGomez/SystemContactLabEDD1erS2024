#include "Menu.h"
#include "iostream"
using namespace std;
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
                    if(Tokenizer::isCorrect(tokens)==1){//fue agregacion de un grupo
                        //cout<<"El texto ingresado es correcto"<<endl;
                        int indicetab=contactos.insertGroup(Tokenizer::campo);
                        //cout<<"listo para insertar el grupo: "+Tokenizer::campo<<endl;
                        for(Tokenizer::estructura st: Tokenizer::campos){
                            contactos.insertField(Tokenizer::campo,st.value,st.name, indicetab);
                        }
                        //contactos.printTable();
                        //cout<<Tokenizer::campos.size()<<endl;
                        cout<<"     Grupo y campos guardados correctamente "<<endl;
                        Tokenizer::campos.clear();
                    }else{
                        if(input!="exit"){
                            cout<<"Comando no valido"<<endl;
                            Tokenizer::campos.clear();
                        }
                    }
                }
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