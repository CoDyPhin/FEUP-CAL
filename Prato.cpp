#include "Prato.h"


Prato::Prato(string nome, vector<string> ingredientes, float volume) : nome(nome),
                                                                                     ingredientes(ingredientes),
                                                                                     volume(volume) {}

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

float Prato::getVolume() const {
    return volume;
}

void Prato::setVolume(float volume) {
    Prato::volume = volume;
}

float Prato::getPreco() const {
    return preco;
}

void Prato::setPreco(float preco) {
    Prato::preco = preco;
}
