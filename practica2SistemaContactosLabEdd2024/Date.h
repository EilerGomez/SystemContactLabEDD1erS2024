//
// Created by eiler on 28/03/24.
//

#ifndef PRACTICA2SISTEMACONTACTOSLABEDD2024_DATE_H
#define PRACTICA2SISTEMACONTACTOSLABEDD2024_DATE_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// Clase Date
class Date {
private:
    int day;
    int month;
    int year;

public:
    void convertirFecha(const string& fecha) {
        stringstream ss(fecha);
        string token;

        // Obtener día
        getline(ss, token, '-');
        day = stoi(token);

        // Obtener mes
        getline(ss, token, '-');
        month = stoi(token);

        // Obtener año
        getline(ss, token, '-');
        year = stoi(token);
    }
    Date();
    Date(string fecha);
    Date(int d, int m, int y) : day(d), month(m), year(y) {}


    // Métodos getter
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Sobrecarga del operador < para comparación
    bool operator<(const Date& other) const {
        if (year < other.year) return true;
        if (year > other.year) return false;
        if (month < other.month) return true;
        if (month > other.month) return false;
        return day < other.day;
    }

    // Sobrecarga del operador > para comparación
    bool operator>(const Date& other) const {
        if (year > other.year) return true;
        if (year < other.year) return false;
        if (month > other.month) return true;
        if (month < other.month) return false;
        return day > other.day;
    }

    // Sobrecarga del operador == para comparación
    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    // Sobrecarga del operador de inserción de flujo para salida
    friend ostream& operator<<(ostream& os, const Date& date) {
        os << date.day << "-" << date.month << "-" << date.year;
        return os;
    }
};


#endif //PRACTICA2SISTEMACONTACTOSLABEDD2024_DATE_H
