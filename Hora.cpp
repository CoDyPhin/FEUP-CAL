#include "Hora.h"

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

