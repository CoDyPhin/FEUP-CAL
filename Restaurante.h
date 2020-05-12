#ifndef CAL_RESTAURANTE_H
#define CAL_RESTAURANTE_H

#include <string>
#include "Posicao.h"
#include "Prato.h"

using namespace std;

class Restaurante {
private:
    string nome;
    Posicao posicao;
    vector<Prato*> pratosDisponiveis;
public:
    const string &getNome() const;
    void setNome(const string &nome);
    const Posicao &getPosicao() const;
    void setPosicao(const Posicao &posicao);
    const vector<Prato*> &getPratosDisponiveis() const;
    void setPratosDisponiveis(const vector<Prato*> &pratosDisponiveis);
public:
    Restaurante(const string &nome, const Posicao &posicao, const vector<Prato*> &pratosDisponiveis);
};


#endif //CAL_RESTAURANTE_H
