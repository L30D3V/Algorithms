#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "triangulo.h"

TEST_CASE("Triângulo Equilátero") {
    Triangulo equilatero(5, 5, 5);
    Tipo eq = equilatero.determinar_tipo();
    CHECK(eq == Tipo::EQUILATERO);
}

TEST_CASE("Triângulo Isóceles") {
    Triangulo isoceles(5, 5, 7);
    Tipo eq = isoceles.determinar_tipo();
    CHECK(eq == Tipo::ISOSCELES);
}

TEST_CASE("Triângulo Escaleno") {
    Triangulo escaleno(5, 8, 10);
    Tipo eq = escaleno.determinar_tipo();
    CHECK(eq == Tipo::ESCALENO);
}

TEST_CASE("Triangulo Isóceles 2") {
    Triangulo isoceles(2, 5, 5);
    Tipo is = isoceles.determinar_tipo();
    CHECK(is == Tipo::ISOSCELES);
}

TEST_CASE("Triângulo Inválido") {
    CHECK_THROWS(new Triangulo(5, -5, 5));
}

TEST_CASE("Triangulo inválido 2") { 
    CHECK_THROWS(new Triangulo(50, 1, 1));
}

TEST_CASE("Triangulo inválido 2") { 
    CHECK_THROWS(new Triangulo(1, 50, 1));
}

TEST_CASE("Triangulo inválido 2") { 
    CHECK_THROWS(new Triangulo(1, 1, 50));
}