#ifndef CAL_EMPRESA_H
#define CAL_EMPRESA_H


#include "Estafeta.h"
#include "Cliente.h"
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
	vector<Estafeta*> getEstafeta();
    vector<Encomenda*> getEncomentas();
    vector<Restaurante*> getRestaurantes();
    void eleminarCliente(long int nif);
    void readEncomendas();
};




#endif //CAL_EMPRESA_H
