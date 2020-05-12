#ifndef CAL_ENCOMENDA_H
#define CAL_ENCOMENDA_H


#include <ostream>
#include "Prato.h"
#include "Estafeta.h"
#include "Cliente.h"
#include "Hora.h"
#include "Restaurante.h"

class Encomenda {
private:
    Prato *prato;
    Restaurante *restaurante;
    Estafeta *estafeta;
    Cliente *cliente;
    Hora *horaPedido;
    Hora *horaEntrega;
public:

    ~Encomenda();

    Encomenda(Prato *prato, Restaurante *restaurante, Estafeta *estafeta, Cliente *cliente, Hora *horaPedido,
              Hora *horaEntrega);

    Prato *getPrato() const;

    void setPrato(Prato *prato);

    Restaurante *getRestaurante() const;

    void setRestaurante(Restaurante *restaurante);

    Estafeta *getEstafeta() const;

    void setEstafeta(Estafeta *estafeta);

    Cliente *getCliente() const;

    void setCliente(Cliente *cliente);

    Hora *getHoraPedido() const;

    void setHoraPedido(Hora *horaPedido);

    Hora *getHoraEntrega() const;

    void setHoraEntrega(Hora *horaEntrega);

    friend ostream &operator<<(ostream &os, const Encomenda &encomenda);
};


#endif //CAL_ENCOMENDA_H
