#include "Encomenda.h"




Encomenda::~Encomenda() {
    free(horaEntrega);
    free(horaPedido);
}

ostream &operator<<(ostream &os, const Encomenda &encomenda) {
    os << "ID: " << encomenda.getId();
    os << "\nPratos: ";
    for (auto par : encomenda.getPratos())
    {
        os << par.first->getNome() << " - " << par.second << ", ";
    }
    os << "\nRestaurante: " << encomenda.getRestaurante()->getNome();
    os << "\nHora de pedido: " << *encomenda.getHoraPedido();
    os << "\nHora de entrega: " << *encomenda.getHoraEntrega();
    return os;
}


unsigned int Encomenda::getId() const {
    return id;
}

void Encomenda::setId(unsigned int id) {
    Encomenda::id = id;
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

Encomenda::Encomenda(unsigned int id,
                     const vector<pair<Prato*,int>> &pratos, Restaurante * restaurante, Hora * horaPedido, Hora * horaEntrega)
        : id(id), pratos(pratos), restaurante(restaurante), horaPedido(horaPedido), horaEntrega(horaEntrega) {}

const vector<pair<Prato*,int>>  Encomenda::getPratos() const{
return
pratos;
}

void Encomenda::setPratos(const vector<pair<Prato*,int>>  pratos) {
    Encomenda::pratos = pratos;
}




