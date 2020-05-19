#ifndef CAL_PESSOA_H
#define CAL_PESSOA_H

#include <string>
#include "Posicao.h"

using namespace std;

class Pessoa {
protected:
    string nome;
    long int nif;
    int idade;
    long idno;
    Posicao posicao;
public:
    Pessoa(const string &nome, long nif, int idade, long idno, Posicao posicao);
    const string &getNome() const;
    void setNome(const string &nome);
    long getNif() const;
    void setNif(long nif);
    int getIdade() const;
    void setIdade(int idade);
    long getIdNo() const;
    void setIdNo(long idno);
    const Posicao &getPosicao() const;
    void setPosicao(const Posicao &posicao);


};


#endif //CAL_PESSOA_H
