#include "Posicao.h"


Posicao::Posicao(double latitude, double longitude) : latitude(latitude), longitude(longitude) {}

double Posicao::getLatitude() const {
    return latitude;
}

double Posicao::getLongitude() const {
    return longitude;
}

void Posicao::setLatitude(double latitude) {
    this->latitude = latitude;
}

void Posicao::setLongitude(double longitude) {
    this->longitude = longitude;
}

double Posicao::calcDist(Posicao pos) {
    double diffLat = latitude - pos.latitude;
    double diffLong = longitude - pos.longitude;
    return pow(pow(diffLat,2) + pow(diffLong,2),0.5);
}

bool operator==(const Posicao &left, const Posicao &right) {
    return left.latitude == right.latitude && left.longitude == right.longitude;
}
