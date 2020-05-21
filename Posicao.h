#ifndef CAL_POSICAO_H
#define CAL_POSICAO_H

#include <cmath>

class Posicao {
private:
    double latitude, longitude;
    long int id;
public:
    Posicao(double latitude, double longitude, long int id);
    double getLatitude() const;
    double getLongitude() const;
    void setLatitude(double latitude);
    void setLongitude(double longitude);

    long getId() const;

    void setId(long id);

    double calcDist(Posicao pos) const;
    friend bool operator==(const Posicao &left,const Posicao &right);
    bool operator!=(const Posicao &rhs) const;
};


#endif //CAL_POSICAO_H
