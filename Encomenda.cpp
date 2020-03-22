#include "Encomenda.h"

Encomenda::Encomenda(const Prato &prato, const Estafeta &estafeta, const Cliente &cliente, const Hora &horaPedido,
                     const Hora &horaEntrega, float preco) : prato(prato), estafeta(estafeta), cliente(cliente),
                                                             horaPedido(horaPedido), horaEntrega(horaEntrega),
                                                             preco(preco) {}

const Prato &Encomenda::getPrato() const {
    return prato;
}

void Encomenda::setPrato(const Prato &prato) {
    Encomenda::prato = prato;
}

const Estafeta &Encomenda::getEstafeta() const {
    return estafeta;
}

void Encomenda::setEstafeta(const Estafeta &estafeta) {
    Encomenda::estafeta = estafeta;
}

const Cliente &Encomenda::getCliente() const {
    return cliente;
}

void Encomenda::setCliente(const Cliente &cliente) {
    Encomenda::cliente = cliente;
}

const Hora &Encomenda::getHoraPedido() const {
    return horaPedido;
}

void Encomenda::setHoraPedido(const Hora &horaPedido) {
    Encomenda::horaPedido = horaPedido;
}

const Hora &Encomenda::getHoraEntrega() const {
    return horaEntrega;
}

void Encomenda::setHoraEntrega(const Hora &horaEntrega) {
    Encomenda::horaEntrega = horaEntrega;
}

float Encomenda::getPreco() const {
    return preco;
}

void Encomenda::setPreco(float preco) {
    Encomenda::preco = preco;
}
