#include "Estafeta.h"



ostream &operator<<(ostream &os, const Estafeta &estafeta) {
    os << "Nome: \n" << estafeta.getNome() << "\nNIF: \n" << estafeta.getNif() << "\nIdade: \n" << estafeta.getIdade()
       << "\nMatricula do veiculo: \n" << estafeta.getTransporte()->getMatricula();
    return os;
}

Estafeta::Estafeta(const string &nome, long nif, int idade, const Posicao &posicao, Transporte *transporte,
                   const vector<Encomenda*> & entregasFeitas, double lucroTotal) : Pessoa(nome, nif, idade, posicao),
                                                                                 transporte(transporte),
                                                                                 entregasFeitas(entregasFeitas),
                                                                                 lucroTotal(lucroTotal) {}

Transporte *Estafeta::getTransporte() const {
    return transporte;
}

void Estafeta::setTransporte(Transporte *transporte) {
    Estafeta::transporte = transporte;
}

const vector<Encomenda*> & Estafeta::getEntregasFeitas() const{
return
entregasFeitas;
}

void Estafeta::setEntregasFeitas(const vector<Encomenda *>& entregasFeitas) {
    Estafeta::entregasFeitas = entregasFeitas;
}

double Estafeta::getLucroTotal() const {
    return lucroTotal;
}

void Estafeta::setLucroTotal(double lucroTotal) {
    Estafeta::lucroTotal = lucroTotal;
}
