#ifndef CAL_ENCOMENDA_H
#define CAL_ENCOMENDA_H


#include "Prato.h"
#include "Estafeta.h"
#include "Cliente.h"
#include "Hora.h"

class Encomenda {
private:
    Prato *prato;
    Estafeta *estafeta;
    Cliente *cliente;
    Hora *horaPedido;
    Hora *horaEntrega;
    float preco;
public:
    Encomenda(Prato *prato, Estafeta *estafeta, Cliente *cliente, Hora *horaPedido, Hora *horaEntrega, float preco);
    ~Encomenda();

    Prato *getPrato() const;

    void setPrato(Prato *prato);

    Estafeta *getEstafeta() const;

    void setEstafeta(Estafeta *estafeta);

    Cliente *getCliente() const;

    void setCliente(Cliente *cliente);

    Hora *getHoraPedido() const;

    void setHoraPedido(Hora *horaPedido);

    Hora *getHoraEntrega() const;

    void setHoraEntrega(Hora *horaEntrega);

    float getPreco() const;

    void setPreco(float preco);
};


#endif //CAL_ENCOMENDA_H
