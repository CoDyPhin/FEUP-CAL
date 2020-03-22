#include "Restaurante.h"

Restaurante::Restaurante(const string &nome, const Posicao &posicao, const vector<Prato> &pratosDisponiveis) : nome(
        nome), posicao(posicao), pratosDisponiveis(pratosDisponiveis) {}

const string &Restaurante::getNome() const {
    return nome;
}

void Restaurante::setNome(const string &nome) {
    Restaurante::nome = nome;
}

const Posicao &Restaurante::getPosicao() const {
    return posicao;
}

void Restaurante::setPosicao(const Posicao &posicao) {
    Restaurante::posicao = posicao;
}

const vector<Prato> &Restaurante::getPratosDisponiveis() const {
    return pratosDisponiveis;
}

void Restaurante::setPratosDisponiveis(const vector<Prato> &pratosDisponiveis) {
    Restaurante::pratosDisponiveis = pratosDisponiveis;
}
