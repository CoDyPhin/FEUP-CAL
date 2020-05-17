#ifndef CAL_ENCOMENDA_H
#define CAL_ENCOMENDA_H


#include <ostream>
#include "Prato.h"
#include "Hora.h"
#include "Restaurante.h"
#include "Graph.h"

class Encomenda {
private:
    unsigned int id;
    Prato *prato;
    Restaurante *restaurante;
    Hora *horaPedido;
    Hora *horaEntrega;
public:

    ~Encomenda();

    Encomenda(unsigned int id, Prato *prato, Restaurante *restaurante, Hora *horaPedido, Hora *horaEntrega);

    unsigned int getId() const;

    void setId(unsigned int id);

    Prato *getPrato() const;

    void setPrato(Prato *prato);

    Restaurante *getRestaurante() const;

    void setRestaurante(Restaurante *restaurante);

    Hora *getHoraPedido() const;

    void setHoraPedido(Hora *horaPedido);

    Hora *getHoraEntrega() const;

    void setHoraEntrega(Hora *horaEntrega);

    friend ostream &operator<<(ostream &os, const Encomenda &encomenda);
};


#endif //CAL_ENCOMENDA_H
