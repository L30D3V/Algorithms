#include "excecoes.h"

const char* TrianguloInvalidoError::what() const noexcept {
    return "Triangulo inválido!";
}