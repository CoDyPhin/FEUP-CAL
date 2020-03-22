#ifndef CAL_ESTAFETA_H
#define CAL_ESTAFETA_H

#include "Pessoa.h"
#include "Transporte.h"
#include "Encomenda.h"

class Estafeta: public Pessoa {
    Transporte transporte;
    vector<Encomenda> entregasFeitas;
};


#endif //CAL_ESTAFETA_H
