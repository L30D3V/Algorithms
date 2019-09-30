#include <iostream>
#include "triangulo.h"

int main() {
    Triangulo t = Triangulo(5,5,5);
    int tipo = t.determinar_tipo();

    std::cout << "Tipo: " << tipo << std::endl;

    return 0;
}
