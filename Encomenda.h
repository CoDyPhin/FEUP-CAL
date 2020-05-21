#ifndef CAL_ENCOMENDA_H
#define CAL_ENCOMENDA_H


#include <ostream>
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

    friend ostream &operator<<(ostream &os, const Encomenda &encomenda);
};


#endif //CAL_ENCOMENDA_H
