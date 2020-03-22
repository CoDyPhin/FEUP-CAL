#ifndef CAL_TRANSPORTE_H
#define CAL_TRANSPORTE_H

#include <string>

using namespace std;

class Transporte {
private:
    string matricula;
    float velocidade;
    double capacidade;
    double peso;
public:
    const string &getMatricula() const;
    void setMatricula(const string &matricula);
    float getVelocidade() const;
    void setVelocidade(float velocidade);
    double getCapacidade() const;
    void setCapacidade(double capacidade);
    double getPeso() const;
    void setPeso(double peso);
public:
    Transporte(const string &matricula, float velocidade, double capacidade, double peso);
};


#endif //CAL_TRANSPORTE_H
