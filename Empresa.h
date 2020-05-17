#ifndef CAL_EMPRESA_H
#define CAL_EMPRESA_H

#include <deque>
#include "Estafeta.h"
#include "Cliente.h"
#include "Restaurante.h"
#include "Graph.h"
#include "lib/graphviewer.h"

class Empresa {
private:
    Graph<Posicao> grafo;
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
    void readEncomendas();
    deque<Posicao> calcPercurso(Posicao inicio, Posicao fim);

    //Grafo
    void readGrafo();
    void showGrafo();

    vector<Estafeta*> getEstafeta();
    vector<Encomenda*> getEncomentas();
    vector<Restaurante*> getRestaurantes();
    vector<Cliente*> getClientes();
    void eliminarCliente(long int nif);
    void criarEstafeta();
    void eliminarEstafeta();
    vector<Estafeta*> filtrarEstafetas(int option);
};




#endif //CAL_EMPRESA_H
