#include "Exportacion.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;
vector<string> Exportacion::traerFieldsDeGrupo(list<pair<string, FieldTable>> *table, int indice) {
    vector<string> lista;


        for (const auto& pair : table[indice]) {

            for (const auto& field : pair.second.fields) {
                lista.push_back(field.value);
            }
        }

    return lista;
}

string Exportacion::contacto(Nodo *nodo, vector <std::string> fields) {
    string contacto="CONTACTO: [ ";
    int i = 0;

    while(nodo != nullptr){
        contacto+=fields[i] + " : " + nodo->palabra + " ";
        nodo = nodo->siguiente; // Avanzar al siguiente nodo
        i++;
    }
    contacto+=" ]";

    return contacto;
}
fs::path Exportacion::crearCarpeta(std::string folderName) {
    fs::path documentsDir = fs::path(getenv("HOME")) / "Documentos";

    // Verificar si el directorio de documentos existe
    if (!fs::exists(documentsDir)) {
        std::cerr << "Error: El directorio de documentos no existe." << std::endl;
    }

    // Crear la ruta completa de la carpeta a crear
    fs::path folderPath = documentsDir / folderName;

    // Verificar si la carpeta ya existe
    if (fs::exists(folderPath)) {
        //std::cout << "La carpeta '" << folderPath << "' ya existe. Eliminando..." << std::endl;
        try {
            fs::remove_all(folderPath); // Eliminar la carpeta y su contenido
        } catch (const fs::filesystem_error& e) {
            std::cerr << "Error al eliminar la carpeta: " << e.what() << std::endl;
        }
    }

    // Crear la carpeta
    if (!fs::create_directory(folderPath)) {
        std::cerr << "Error: No se pudo crear la carpeta." << std::endl;
    }
    return folderPath;

}

void Exportacion::crearGuardarArchivo(fs::path folderPath, std::string nameTxt, std::string txt) {
    // Crear la ruta completa del archivo de texto dentro de la carpeta
    fs::path filePath = folderPath / (nameTxt+".txt");

    // Crear un objeto de flujo de salida para escribir en el archivo
    std::ofstream file(filePath);

    // Verificar si se pudo abrir el archivo correctamente
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
    }

    // Escribir en el archivo
    file << txt;

    // Cerrar el archivo
    file.close();

    //std::cout << "Se creó el archivo '" << filePath << "' correctamente." << std::endl;
}

void Exportacion::exportar(list <std::pair<std::string, FieldTable>> *table, int index, string grupoNombre) {
        //std::cout << "contacts:" << std::endl;
        /*for (const auto& f : traerFieldsDeGrupo(table, index)) {
            std::cout << "     " << f << std::endl;
        }*/
    vector<string> lista=traerFieldsDeGrupo(table, index);
    vector<Nodo*> todosLosNodos;
    for (const auto& pair : table[index]) {
        for (const auto& field : pair.second.fields) {
            if(field.value==lista[0]){
                todosLosNodos=field.arbol.obtenerTodosLosNodos();
                break;
            }
        }
    }
    fs::path ruta=crearCarpeta(grupoNombre);
    int i=0;
    for(Nodo* nodo:todosLosNodos){
        string nombre=nodo->palabra;
        //cout<<contacto(nodo,lista)<<endl;
        crearGuardarArchivo(ruta,nombre, contacto(nodo,lista));

        i++;
    }
    cout << "Se creron: "<< i <<" archivos correctamente en: '" << ruta << "' " << endl;

}
