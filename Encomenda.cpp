#include "Encomenda.h"



Encomenda::Encomenda(Prato *prato, Estafeta *estafeta, Cliente *cliente, Hora *horaPedido, Hora *horaEntrega,
                     float preco) : prato(prato), estafeta(estafeta), cliente(cliente), horaPedido(horaPedido),
                                    horaEntrega(horaEntrega), preco(preco) {}

Prato *Encomenda::getPrato() const {
    return prato;
}

void Encomenda::setPrato(Prato *prato) {
    Encomenda::prato = prato;
}

Estafeta *Encomenda::getEstafeta() const {
    return estafeta;
}

void Encomenda::setEstafeta(Estafeta *estafeta) {
    Encomenda::estafeta = estafeta;
}

Cliente *Encomenda::getCliente() const {
    return cliente;
}

void Encomenda::setCliente(Cliente *cliente) {
    Encomenda::cliente = cliente;
}

Hora *Encomenda::getHoraPedido() const {
    return horaPedido;
}

void Encomenda::setHoraPedido(Hora *horaPedido) {
    Encomenda::horaPedido = horaPedido;
}

Hora *Encomenda::getHoraEntrega() const {
    return horaEntrega;
}

void Encomenda::setHoraEntrega(Hora *horaEntrega) {
    Encomenda::horaEntrega = horaEntrega;
}

float Encomenda::getPreco() const {
    return preco;
}

void Encomenda::setPreco(float preco) {
    Encomenda::preco = preco;
}

Encomenda::~Encomenda() {
    free(horaEntrega);
    free(horaPedido);
}

ostream &operator<<(ostream &os, const Encomenda &encomenda) {
    os << "prato: " << encomenda.prato << " estafeta: " << encomenda.estafeta << " cliente: " << encomenda.cliente
       << " horaPedido: " << encomenda.horaPedido << " horaEntrega: " << encomenda.horaEntrega << " preco: "
       << encomenda.preco;
    return os;
}
