#include "triangulo.h"

Triangulo::Triangulo(double x, double y, double z) {
    if (_x <= 0 || _y <= 0 || _z <= 0) {
        throw TrianguloInvalidoException();
    }
    if (!((_x > abs(_y - _z)) && (_x < (_y + _z)))) {
        throw TrianguloInvalidoException();
    }
    if (!((_y > abs(_x - _z)) && (_x < (_x + _z)))) {
        throw TrianguloInvalidoException();
    }
    if (!((_z > abs(_y - _x)) && (_x < (_y + _x)))) {
        throw TrianguloInvalidoException();
    }
    
    _x = x;
    _y = y;
    _z = z;
}

Tipo Triangulo::determinar_tipo() { 
    if (_x == _y == _z) {
        return Tipo::EQUILATERO;
    } else if ((_x == _y != _z) || (_x == _z != _y) || (_z == _y != _x)) {
        return Tipo::ISOSCELES;
    } else if (_x != _y != _z) {
        return Tipo::ESCALENO;
    }
}