//
// Created by eiler on 29/03/24.
//

#include "Reportes.h"
#include "FieldTable.h"
using namespace std;
int Reportes::contarCantidadDatosPorGrupo(list<FieldTable::Field> fields) {
    int cantidad = 0;
    for (const auto& field : fields) {
        cantidad += field.arbol.contarElementos();
    }
    return cantidad;
}
int Reportes::contarDatosDeUnField(list <FieldTable::Field> fields) {
    int cantidad = 0;
    for (const auto& field : fields) {
        cantidad += field.arbol.contarElementos();
        break;
    }
    return cantidad;
}

void Reportes::cantidadDatosPorGrupo(list<pair<string, FieldTable>>* table, int tableSize) {
    for (int i = 0; i < tableSize; ++i) {

        if(!table[i].empty()){
            for (const auto& tabla : table[i]) {
                cout << "   Nombre de Grupo: " << tabla.first <<endl;
                cout << "       Cantidad de datos: " << contarCantidadDatosPorGrupo(tabla.second.fields) << endl;
            }

        }


    }
}
void Reportes::cantidadDatosTodoElSistema(list <std::pair<std::string, FieldTable>> *table, int tableSize) {
    int cantidad=0;
    for (int i = 0; i < tableSize; ++i) {
        if(!table[i].empty()){
            for (const auto& tabla : table[i]) {
                cantidad+= contarCantidadDatosPorGrupo(tabla.second.fields);
            }

        }
    }
    cout<<"     Cantidad de Datos de todo el sistema: "<<cantidad<<endl;
}

void Reportes::cantidadContactosPorGrupo(list <std::pair<std::string, FieldTable>> *table, int tableSize) {
    for (int i = 0; i < tableSize; ++i) {

        if(!table[i].empty()){
            for (const auto& tabla : table[i]) {
                cout << "   Nombre de Grupo: " << tabla.first <<endl;
                cout << "       Cantidad de contactos: " << contarDatosDeUnField(tabla.second.fields) << endl;
            }

        }


    }
}
void Reportes::existTipoDato(vector <pair<std::string, int>> & tipos, string tipo, string campo) {
    bool exist = false;
    for (auto& tip : tipos) {
        if(tip.first==tipo){
            exist=true;
            tip.second++;
            break;
        }
    }
    if(exist==false){
        tipos.push_back(make_pair(tipo, 1));
    }


}
void Reportes::llenarCamposTiposDatos(std::string campo, list <Tokenizer::estructura> campos) {
    vector<pair<string, int>> listado;
    vector<string> listadoAlmacenar;
    for (const auto& camp : campos) {
        existTipoDato(listado,camp.value,campo);
    }
    for (auto& vec : listado) {
        listadoAlmacenar.push_back(vec.first + ": " + to_string(vec.second));
    }
    camposTiposDatos.push_back(stReporte(campo,listadoAlmacenar));

}
void Reportes::imprimirCampsTiposDatos() {
    for (const auto& camp : camposTiposDatos) {
        cout<<camp.campo<<endl;
        for (const auto& camp : camp.listado) {
            cout<<"     ";
            cout<<camp;
            cout<<endl;
        }
    }
}
string Reportes::obtenerFechaYHoraActual() {
    // Obtener el tiempo actual
    auto ahora = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    // Convertir a estructura de tiempo local
    struct std::tm* tmLocal = std::localtime(&ahora);

    // Crear un stringstream para formatear la fecha y hora
    std::stringstream ss;
    ss << std::put_time(tmLocal, "%Y-%m-%d %H:%M:%S"); // Formato: YYYY-MM-DD HH:MM:SS

    return ss.str();
}
void Reportes::guardarAccionLog(std::string campo, list <Tokenizer::estructura> campos, int numAccion) {
    if(numAccion==1){
        string accion = "Se guardo el grupo: "+campo +" con los campos: [ ";
        for (const auto& camp : campos) {
            accion +=camp.value +":"+ camp.name+"  ";
        }
        accion+="]      "+obtenerFechaYHoraActual();
        listLog.push_back(accion);

    }else if(numAccion==2){
        string accion = "Se guardo un contacto en  el grupo: "+campo +" con los datos: [ ";
        for (const auto& camp : campos) {
            accion +=  camp.value+"  ";
        }
        accion+="]      "+obtenerFechaYHoraActual();
        listLog.push_back(accion);
    }else if(numAccion==3){
        vector<string> lista;
        for (Tokenizer::estructura pair : campos) {
            lista.push_back(pair.value);
        }
        string accion = "Se busco un contacto en el campo : "+campo +" con la comparacion: [ ";
        accion+=lista[0]+" = "+lista[1];
        accion+="]      "+obtenerFechaYHoraActual();
        listLog.push_back(accion);
    }
}

void Reportes::mostrarLog() {
    for (int i = 0; i < listLog.size(); ++i) {
        cout<<listLog[i]<<endl;
    }
    cout<<endl;
}



