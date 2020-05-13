#ifndef CAL_ENCOMENDA_H
#define CAL_ENCOMENDA_H


#include <ostream>
#include "Prato.h"
#include "Hora.h"
#include "Restaurante.h"

class Encomenda {
private:
    Prato *prato;
    Restaurante *restaurante;
    Hora *horaPedido;
    Hora *horaEntrega;
public:

    ~Encomenda();

    Encomenda(Prato *prato, Restaurante *restaurante, Hora *horaPedido,
              Hora *horaEntrega);

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
