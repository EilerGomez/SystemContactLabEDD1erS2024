#include "Menu.h"
#include "iostream"
using namespace std;
void Menu::inicio() {
    string input;
    vector<Tokens> tokens;

    int opcion = 1;
    while (opcion > 0) {
        cout << "Elija una opcion: " << endl;
        cout << "1. Consola " << endl << "2. Reportes " << endl << "3. Graficos " << endl << "4. Exportar" << endl;
        cin >> opcion;
        cin.ignore();
        switch (opcion) {
            case 1:
                cout << "Seleccionó la opción de Consola." << endl;
                cout << "Ingrese un texto: ";
                std::getline(std::cin, input);
               cout<<"CREAR LA TABLA HASH!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
                tokens = Tokenizer::tokenize(input);
                /*for (const Tokens& token : tokens) {
                    cout << "Nombre: " << token.getName() << ", Valor: " << token.getValue() << endl;
                }*/
                if(Tokenizer::isCorrect(tokens)){
                    cout<<"El texto ingresado es correcto"<<endl;
                }else{
                    cout<<"Comando no valido"<<endl;
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