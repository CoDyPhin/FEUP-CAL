#include "Cliente.h"

Cliente::Cliente(const string &nome, long nif, int idade, const Posicao &posicao,
                 const vector<Encomenda*> &encomendasFeitas, double totalGasto) : Pessoa(nome, nif, idade, posicao),
                                                                                  encomendasFeitas(encomendasFeitas),
                                                                                  totalGasto(totalGasto) {}

const vector<Encomenda*> &Cliente::getEncomendasFeitas() const {
    return encomendasFeitas;
}

void Cliente::setEncomendasFeitas(const vector<Encomenda*> &encomendasFeitas) {
    Cliente::encomendasFeitas = encomendasFeitas;
}

double Cliente::getTotalGasto() const {
    return totalGasto;
}

void Cliente::setTotalGasto(double totalGasto) {
    Cliente::totalGasto = totalGasto;
}

long Cliente::getNif() const {
    return Pessoa::getNif();
}
