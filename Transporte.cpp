

#include "Transporte.h"

Transporte::Transporte(string &matricula, float velocidade, unsigned int capacidade)
        : matricula(matricula), velocidade(velocidade), capacidade(capacidade) {}

const string &Transporte::getMatricula() const {
    return matricula;
}

void Transporte::setMatricula(const string &matricula) {
    Transporte::matricula = matricula;
}

float Transporte::getVelocidade() const {
    return velocidade;
}

void Transporte::setVelocidade(float velocidade) {
    Transporte::velocidade = velocidade;
}

unsigned int Transporte::getCapacidade() const {
    return capacidade;
}

void Transporte::setCapacidade(unsigned int capacidade) {
    Transporte::capacidade = capacidade;
}
