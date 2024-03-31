#include "Menu.h"
#include "iostream"
#include "Utilities.h"
#include "Reportes.h"
#include "Exportacion.h"
using namespace std;
Menu::~Menu() {
    // Implementación del destructor
}
void Menu::inicio() {
    string input="nadaxd";
    string nombreGrupo="";

    vector<Tokens> tokens;
    ContactGroups contactos;

    int opcionReportes=-2;
    Reportes reportes;
    Exportacion exportacion;
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
                        reportes.llenarCamposTiposDatos(Tokenizer::campo,Tokenizer::campos);
                        reportes.guardarAccionLog(Tokenizer::campo,Tokenizer::campos,1);
                        contactos.printTable();
                        //cout<<Tokenizer::campos.size()<<endl;
                        cout<<"     Grupo y campos guardados correctamente "<<endl;
                        Tokenizer::campos.clear();
                    }else if(valorAceptacion==2){
                        int index=contactos.existGruop(Tokenizer::campo);
                        if(index!=-5){
                            cout<<"existe el grupo, en el indice "<<index<<endl;
                            if(contactos.traerTablaDeGrupo(index,Tokenizer::campo)->fields.size()==Tokenizer::campos.size()){
                            //verifica si los parametros que le esta enviando son iguales a los que guardo
                                cout<<"Contiene la misma cantidad de parametros"<<endl;
                                if(utilidades.isCompatibily(contactos.traerTablaDeGrupo(index,Tokenizer::campo)->fields,Tokenizer::campos)){
                                    cout<<"los datos son compatibles y estan listos para ser agregados a los arboles"<<endl;
                                    utilidades.insertarANodos(contactos.traerTablaDeGrupo(index,Tokenizer::campo)->fields,Tokenizer::campos);
                                    reportes.guardarAccionLog(Tokenizer::campo,Tokenizer::campos,2);
                                }else{
                                    cout<<"Error: los datos no son compatibles "<<endl;
                                }
                            }else{
                                cout<<"Error: la cantidad de datos no coinciden con la cantidad de campos del grupo "<<Tokenizer::campo<<endl;
                            }
                            cout<<contactos.traerTablaDeGrupo(index,Tokenizer::campo)->fields.size()<<endl;
                            cout<<Tokenizer::campos.size()<<endl;
                            for(Tokenizer::estructura st:Tokenizer::campos){
                                cout<<st.name<<"-"<<st.value<<endl;
                            }
                        }else{
                            cout<<"el grupo no existe"<<endl;

                        }
                        Tokenizer::campos.clear();
                        contactos.printTable();
                    }else if(valorAceptacion==3){
                        int index=contactos.existGruop(Tokenizer::campo);
                        if(index!=-5){
                            cout<<"existe el grupo, en el indice "<<index<<endl;
                            vector<string> lista;
                            for (Tokenizer::estructura pair : Tokenizer::campos) {
                                lista.push_back(pair.value);
                            }
                            for(FieldTable::Field fl:contactos.traerTablaDeGrupo(index,Tokenizer::campo)->fields){
                                if(fl.value==lista[0]){
                                    cout<<"existe el field "<<lista[0]<<" en el cammpo: "<<Tokenizer::campo<<endl;
                                    cout<<"debemos ahora buscar el contacto: "<<lista[1]<<endl;
                                    vector<string> listaFields;
                                    for(FieldTable::Field fll:contactos.traerTablaDeGrupo(index,Tokenizer::campo)->fields){
                                        listaFields.push_back(fll.value);
                                    }
                                    utilidades.imprimirBusqueda(fl.arbol.buscarElemento(lista[1]),listaFields);
                                    reportes.guardarAccionLog(Tokenizer::campo,Tokenizer::campos,3);
                                    break;
                                }
                            }

                        }
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


                while(opcionReportes!=-1){

                    cout << "1.Cantidad de datos por Grupo"<< endl<<"2.Cantidad de datos de todo el sistema"<<endl;
                    cout<<"3.Cantidad de Contactos con el mismo tipo de dato del campo de criterio de ordenamiento."<<endl;
                    cout<<"4.Cantidad de Contactos por Grupo."<<endl<<"5.Archivo Log del sistema."<<endl<<"-1.Salir"<<endl;
                    cin>>opcionReportes;
                    switch (opcionReportes) {
                        case 1:
                            cout<<"-------------------------------------"<<endl;
                            reportes.cantidadDatosPorGrupo(contactos.table,contactos.tableSize);
                            cout<<"-------------------------------------"<<endl;
                            break;
                        case 2:
                            cout<<"----------------------------------------------------"<<endl;
                            reportes.cantidadDatosTodoElSistema(contactos.table,contactos.tableSize);
                            cout<<"----------------------------------------------------"<<endl;
                            break;
                        case 3:
                            cout<<"-------------------------------------"<<endl;
                            reportes.imprimirCampsTiposDatos();
                            cout<<"-------------------------------------"<<endl;
                            break;
                        case 4:
                            cout<<"-------------------------------------"<<endl;
                            reportes.cantidadContactosPorGrupo(contactos.table,contactos.tableSize);
                            cout<<"-------------------------------------"<<endl;
                            break;
                        case 5:cout<<endl;
                            reportes.mostrarLog();
                            break;
                        default:
                            break;
                    }
                }
                opcionReportes=-2;
                break;
            case 3:
                cout << "Seleccionó la opción de Gráficos." << endl;
                break;
            case 4:
                cout << "Ingrese el nombre del grupo de contacto que desee exportar" << std::endl;
                for (int i = 0; i < contactos.tableSize; ++i) {
                    if(!contactos.table[i].empty()){
                        for (const auto& tabla : contactos.table[i]) {
                            cout<<tabla.first<<endl;
                        }
                    }
                }
                cin>>nombreGrupo;

                if(contactos.existGruop(nombreGrupo) != -5){
                    int indice =contactos.existGruop(nombreGrupo);
                    cout<<nombreGrupo<<endl;
                    exportacion.exportar(contactos.table, indice, nombreGrupo);
                    cout<<"Exportacion con exito!"<<endl;
                } else{
                    cout<<"No existe el grupo que deseas exportar "<<endl;
                }

                //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;

            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    }
}