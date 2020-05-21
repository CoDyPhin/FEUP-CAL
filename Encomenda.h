#ifndef CAL_ENCOMENDA_H
#define CAL_ENCOMENDA_H


#include <ostream>
#include <deque>
#include "Prato.h"
#include "Hora.h"
#include "Restaurante.h"

class Encomenda {
private:
    unsigned int id;
    vector<pair<Prato*,int>> pratos;
    Restaurante *restaurante;
    Hora *horaPedido;
    Hora *horaEntrega;
    float custo;
    deque<Posicao> caminho;
public:

    ~Encomenda();

    Encomenda(unsigned int id,
              const vector<pair<Prato*,int>> &pratos, Restaurante * restaurante, Hora * horaPedido, Hora * horaEntrega, float custo);

    unsigned int getId() const;

    void setId(unsigned int id);

    const vector<pair<Prato*,int>>  getPratos() const;

    void setPratos(const vector<pair<Prato*,int>> pratos);

    Restaurante *getRestaurante() const;

    void setRestaurante(Restaurante *restaurante);

    Hora *getHoraPedido() const;

    void setHoraPedido(Hora *horaPedido);

    Hora *getHoraEntrega() const;

    void setHoraEntrega(Hora *horaEntrega);

    float getCusto() const;

    void setCusto(float custo);

    const deque<Posicao> & getCaminho() const;

    void setCaminho(const deque<Posicao> & caminho);

    friend ostream &operator<<(ostream &os, const Encomenda &encomenda);
};


#endif //CAL_ENCOMENDA_H
