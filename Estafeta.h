#ifndef CAL_ESTAFETA_H
#define CAL_ESTAFETA_H

#include "Pessoa.h"
#include "Transporte.h"
#include "Encomenda.h"

class Estafeta: public Pessoa {
    Transporte transporte;
    vector<Encomenda> entregasFeitas;
    double lucroTotal;
public:
    const Transporte &getTransporte() const;
    void setTransporte(const Transporte &transporte);
    const vector<Encomenda> &getEntregasFeitas() const;
    void setEntregasFeitas(const vector<Encomenda> &entregasFeitas);
    double getLucroTotal() const;
    void setLucroTotal(double lucroTotal);
public:
    Estafeta(const string &nome, long nif, int idade, const Posicao &posicao, const Transporte &transporte,
             const vector<Encomenda> &entregasFeitas, double lucroTotal);
};


#endif //CAL_ESTAFETA_H
