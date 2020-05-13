#include "Estafeta.h"

Estafeta::Estafeta(const string &nome, long nif, int idade, const Posicao &posicao, const Transporte &transporte,
                   const vector<Encomenda*> &entregasFeitas, double lucroTotal) : Pessoa(nome, nif, idade, posicao),
                                                                                 transporte(transporte),
                                                                                 entregasFeitas(entregasFeitas),
                                                                                 lucroTotal(lucroTotal) {}

const Transporte &Estafeta::getTransporte() const {
    return transporte;
}

void Estafeta::setTransporte(const Transporte &transporte) {
    Estafeta::transporte = transporte;
}

const vector<Encomenda*> &Estafeta::getEntregasFeitas() const {
    return entregasFeitas;
}

void Estafeta::setEntregasFeitas(const vector<Encomenda*> &entregasFeitas) {
    Estafeta::entregasFeitas = entregasFeitas;
}

double Estafeta::getLucroTotal() const {
    return lucroTotal;
}

void Estafeta::setLucroTotal(double lucroTotal) {
    Estafeta::lucroTotal = lucroTotal;
}
