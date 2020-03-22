#include "Transporte.h"

Transporte::Transporte(const string &matricula, float velocidade, double capacidade, double peso) : matricula(
        matricula), velocidade(velocidade), capacidade(capacidade), peso(peso) {}

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

double Transporte::getCapacidade() const {
    return capacidade;
}

void Transporte::setCapacidade(double capacidade) {
    Transporte::capacidade = capacidade;
}

double Transporte::getPeso() const {
    return peso;
}

void Transporte::setPeso(double peso) {
    Transporte::peso = peso;
}
