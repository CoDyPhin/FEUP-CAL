#ifndef CAL_CLIENTE_H
#define CAL_CLIENTE_H


#include "Pessoa.h"
#include "Encomenda.h"

class Cliente: public Pessoa {
private:
    vector<Encomenda> encomendasFeitas;
    double totalGasto;
public:
    const vector<Encomenda> &getEncomendasFeitas() const;
    void setEncomendasFeitas(const vector<Encomenda> &encomendasFeitas);
    double getTotalGasto() const;
    void setTotalGasto(double totalGasto);
    Cliente(const string &nome, long nif, int idade, const Posicao &posicao, const vector<Encomenda> &encomendasFeitas,
            double totalGasto);
};


#endif //CAL_CLIENTE_H
