#ifndef CAL_EMPRESA_H
#define CAL_EMPRESA_H


#include "Estafeta.h"

class Empresa {
private:
    vector<Estafeta*> estafetas;
    vector<Cliente*> clientes;
    vector<Encomenda*> encomendas;
public:
    Empresa();

};


#endif //CAL_EMPRESA_H
