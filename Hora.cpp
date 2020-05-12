#include "Hora.h"
#include "utils.h"

Hora::Hora(int hora, int minuto) : hora(hora), minuto(minuto) {}

int Hora::getHora() const {
    return hora;
}

void Hora::setHora(int hora) {
    Hora::hora = hora;
}

int Hora::getMinuto() const {
    return minuto;
}

void Hora::setMinuto(int minuto) {
    Hora::minuto = minuto;
}

Hora::Hora(string strHora) {
    vector<string> parts = string_split(strHora,':');
    this->hora = stoi(parts.at(0));
    this->minuto = stoi(parts.at(1));
}

