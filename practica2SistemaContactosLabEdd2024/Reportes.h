#ifndef PRACTICA2SISTEMADECONTACTOS_REPORTES_H
#define PRACTICA2SISTEMADECONTACTOS_REPORTES_H

#include <list>
#include <string>
#include "vector"
#include "FieldTable.h"
#include "Tokenizer.h"
#include <chrono>
#include <ctime>
#include <iomanip>

class Reportes {
    struct stReporte {
        string campo;
        vector<string> listado;
        stReporte(const string& c, const vector<string>& l) : campo(c), listado(l) {}
    };
public:
    vector<string> listLog;
    vector<stReporte> camposTiposDatos;
    void llenarCamposTiposDatos(string campo, list<Tokenizer::estructura> campos);
    void existTipoDato(vector<pair<string,int>> &tipos, string tipo, string campo);
    void imprimirCampsTiposDatos();
    int contarCantidadDatosPorGrupo(list<FieldTable::Field> fields);
    int contarDatosDeUnField(list<FieldTable::Field> fields);
    void cantidadDatosPorGrupo(list<std::pair<std::string, FieldTable>>* table,int tableSize);
    void cantidadDatosTodoElSistema(list<std::pair<std::string, FieldTable>>* table,int tableSize);
    void cantidadContactosPorGrupo(list<std::pair<std::string, FieldTable>>* table,int tableSize);
    string obtenerFechaYHoraActual();
    void guardarAccionLog(string campo,  list<Tokenizer::estructura> campos, int numAccion);
    void mostrarLog();
};

#endif //PRACTICA2SISTEMADECONTACTOS_REPORTES_H
