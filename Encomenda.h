#ifndef CAL_ENCOMENDA_H
#define CAL_ENCOMENDA_H


#include "Prato.h"
#include "Estafeta.h"
#include "Cliente.h"
#include "Hora.h"

class Encomenda {
private:
    Prato prato;
    Estafeta estafeta;
    Cliente cliente;
    Hora horaPedido;
    Hora horaEntrega;
    float preco;
public:
    float getPreco() const;
    void setPreco(float preco);
    const Prato &getPrato() const;
    void setPrato(const Prato &prato);
    const Estafeta &getEstafeta() const;
    void setEstafeta(const Estafeta &estafeta);
    const Cliente &getCliente() const;
    void setCliente(const Cliente &cliente);
    const Hora &getHoraPedido() const;
    void setHoraPedido(const Hora &horaPedido);
    const Hora &getHoraEntrega() const;
    void setHoraEntrega(const Hora &horaEntrega);
public:
    Encomenda(const Prato &prato, const Estafeta &estafeta, const Cliente &cliente, const Hora &horaPedido,
              const Hora &horaEntrega, float preco);
};


#endif //CAL_ENCOMENDA_H
