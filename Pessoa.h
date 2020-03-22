#ifndef CAL_PESSOA_H
#define CAL_PESSOA_H

#include <string>
#include "Posicao.h"

using namespace std;

class Pessoa {
public:
    Pessoa(const string &nome, long nif, int idade, Posicao posicao);

private:
    string nome;
    long int nif;
    int idade;
    Posicao posicao;
public:
    const string &getNome() const;
    void setNome(const string &nome);
    long getNif() const;
    void setNif(long nif);
    int getIdade() const;
    void setIdade(int idade);
    const Posicao &getPosicao() const;
    void setPosicao(const Posicao &posicao);




};


#endif //CAL_PESSOA_H
