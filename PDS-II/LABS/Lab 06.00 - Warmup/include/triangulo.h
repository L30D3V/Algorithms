#ifndef PDS2_TRIANGULO_H
#define PDS2_TRIANGULO_H

#include "excecoes.h"

enum Tipo {EQUILATERO, ISOSCELES, ESCALENO};

class Triangulo {
private:
    double _x;
    double _y;
    double _z;
public:
    Triangulo(double x, double y, double z) throw(TrianguloInvalidoError);
    Tipo determinar_tipo();
};

#endif
