#include <iostream>
#include "triangulo.h"
#include "excecoes.h"

Triangulo::Triangulo(double x, double y, double z) throw(TrianguloInvalidoError) {
    if ((x <= 0) || (y <= 0) || (z <= 0)) {
        throw TrianguloInvalidoError();
    }
    if (!((x > abs(y - z)) && (x < (y + z)))) {
        throw TrianguloInvalidoError();
    }
    
    _x = x;
    _y = y;
    _z = z;
}

Tipo Triangulo::determinar_tipo() { 
    if (_x == _y) {
        if (_x == _z) {
            return Tipo::EQUILATERO;
        } else {
            return Tipo::ISOSCELES;
        }
    }
    else if (_x == _z) {
        if (_x == _y) {
            return Tipo::EQUILATERO;
        } else {
            return Tipo::ISOSCELES;
        }
    }
    else if (_z == _y) {
        if (_z == _x) {
            return Tipo::EQUILATERO;
        } else {
            return Tipo::ISOSCELES;
        }
    }
    else {
        return Tipo::ESCALENO;
    }
}