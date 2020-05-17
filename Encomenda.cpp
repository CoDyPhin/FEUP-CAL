#include "Encomenda.h"




Encomenda::~Encomenda() {
    free(horaEntrega);
    free(horaPedido);
}

ostream &operator<<(ostream &os, const Encomenda &encomenda) {
    os << "ID: " << encomenda.getId();
    os << "\nPrato: "<< encomenda.getPrato()->getNome();
    os << "\nRestaurante: " << encomenda.getRestaurante()->getNome();
    os << "\nHora de pedido: " << *encomenda.getHoraPedido();
    os << "\nHora de entrega: " << *encomenda.getHoraEntrega();
    return os;
}

Encomenda::Encomenda(unsigned int id, Prato *prato, Restaurante *restaurante, Hora *horaPedido, Hora *horaEntrega) : id(
        id), prato(prato), restaurante(restaurante), horaPedido(horaPedido), horaEntrega(horaEntrega) {}

unsigned int Encomenda::getId() const {
    return id;
}

void Encomenda::setId(unsigned int id) {
    Encomenda::id = id;
}

Prato *Encomenda::getPrato() const {
    return prato;
}

void Encomenda::setPrato(Prato *prato) {
    Encomenda::prato = prato;
}

Restaurante *Encomenda::getRestaurante() const {
    return restaurante;
}

void Encomenda::setRestaurante(Restaurante *restaurante) {
    Encomenda::restaurante = restaurante;
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




