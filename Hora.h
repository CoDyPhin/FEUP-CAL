#ifndef CAL_HORA_H
#define CAL_HORA_H

#include <string>
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

    bool operator<(const Hora &rhs) const;

    bool operator>(const Hora &rhs) const;

    bool operator<=(const Hora &rhs) const;

    bool operator>=(const Hora &rhs) const;
};


#endif //CAL_HORA_H
