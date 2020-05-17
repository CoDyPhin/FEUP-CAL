#ifndef CAL_TRANSPORTE_H
#define CAL_TRANSPORTE_H

#include <string>

using namespace std;

class Transporte {
private:
    string matricula;
    float velocidade;
    unsigned int capacidade;
public:
    Transporte(string &matricula, float velocidade, unsigned int capacidade);

    const string &getMatricula() const;

    void setMatricula(const string &matricula);

    float getVelocidade() const;

    void setVelocidade(float velocidade);

    unsigned int getCapacidade() const;

    void setCapacidade(unsigned int capacidade);
};


#endif //CAL_TRANSPORTE_H
