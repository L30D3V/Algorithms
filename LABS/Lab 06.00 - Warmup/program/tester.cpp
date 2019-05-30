#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "triangulo.h"

TEST_CASE("Triângulo Equilátero") {
    Triangulo equilatero(5, 5, 5);
    Tipo eq = equilatero.determinar_tipo();
    CHECK(eq == Tipo::EQUILATERO);
}

TEST_CASE("Triângulo Isóceles") {
    Triangulo isoceles(5, 5, 15);
    Tipo eq = isoceles.determinar_tipo();
    CHECK(eq == Tipo::ISOSCELES);
}

TEST_CASE("Triângulo Escaleno") {
    Triangulo escaleno(5, 25, 15);
    Tipo eq = escaleno.determinar_tipo();
    CHECK(eq == Tipo::ESCALENO);
}

TEST_CASE("Triângulo Inválido") {
    Triangulo invalido(5, -5, 5);
    Tipo eq = invalido.determinar_tipo();
    CHECK(eq == Tipo::EQUILATERO);
}
