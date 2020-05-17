#include "Prato.h"


Prato::Prato(const string &nome, const vector<string> &ingredientes, float preco) : nome(nome),
                                                                                    ingredientes(ingredientes),
                                                                                    preco(preco) {}

const string &Prato::getNome() const {
    return nome;
}

void Prato::setNome(const string &nome) {
    Prato::nome = nome;
}

const vector<string> &Prato::getIngredientes() const {
    return ingredientes;
}

void Prato::setIngredientes(const vector<string> &ingredientes) {
    Prato::ingredientes = ingredientes;
}

float Prato::getPreco() const {
    return preco;
}

void Prato::setPreco(float preco) {
    Prato::preco = preco;
}

