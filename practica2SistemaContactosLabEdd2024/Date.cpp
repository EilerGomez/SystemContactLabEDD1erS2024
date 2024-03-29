//
// Created by eiler on 28/03/24.
//

#include "Date.h"
Date::Date(string fecha) {
    convertirFecha(fecha);
}
Date::Date() {
    // Inicializar los miembros de la clase Date
    day = 1;
    month = 1;
    year = 2000;
}
