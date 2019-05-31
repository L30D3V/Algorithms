#include <iostream>
#include "triangulo.h"

int main() {
    Triangulo t = Triangulo(5,5,5);
    int tipo = t.determinar_tipo();

    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "X: " << t.getX() << std::endl;
    std::cout << "Y: " << t.getY() << std::endl;
    std::cout << "Z: " << t.getZ() << std::endl;

    return 0;
}
