#ifndef CAL_HORA_H
#define CAL_HORA_H

#include <string>
#include <ostream>

using namespace std;

class Hora {
private:
    int hora,minuto;
public:
    int getHora() const;
    void setHora(int hora);
    int getMinuto() const;
    void setMinuto(int minuto);
    Hora(int hora, int minuto);
    Hora(string strHora);

    Hora* calcPassagemTempo(int minutos);

    bool operator<(const Hora &rhs) const;

    bool operator>(const Hora &rhs) const;

    bool operator<=(const Hora &rhs) const;

    bool operator>=(const Hora &rhs) const;

    friend ostream &operator<<(ostream &os, const Hora &hora);
};


#endif //CAL_HORA_H
