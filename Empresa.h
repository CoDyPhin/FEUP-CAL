#ifndef CAL_EMPRESA_H
#define CAL_EMPRESA_H


#include "Estafeta.h"
#include "Restaurante.h"

class Empresa {
private:
    vector<Restaurante*> restaurantes;
    vector<Estafeta*> estafetas;
    vector<Cliente*> clientes;
    vector<Encomenda*> encomendas;
public:
    Empresa();

    //Encomendas
    void criarEncomenda();
    void eliminarEncomenda();
    vector<Encomenda*> filtrarEncomendas(int option);
};




#endif //CAL_EMPRESA_H
