#include "Encomenda.h"




Encomenda::~Encomenda() {
    free(horaEntrega);
    free(horaPedido);
}

Encomenda::Encomenda(Prato *prato, Restaurante *restaurante, Estafeta *estafeta, Cliente *cliente, Hora *horaPedido,
                     Hora *horaEntrega) : prato(prato), restaurante(restaurante), estafeta(estafeta),
                                                       cliente(cliente), horaPedido(horaPedido),
                                                       horaEntrega(horaEntrega) {}

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



ostream &operator<<(ostream &os, const Encomenda &encomenda) {
    os << "prato: " << encomenda.prato << " restaurante: " << encomenda.restaurante << " estafeta: "
       << encomenda.estafeta << " cliente: " << encomenda.cliente << " horaPedido: " << encomenda.horaPedido
       << " horaEntrega: " << encomenda.horaEntrega;
    return os;
}


