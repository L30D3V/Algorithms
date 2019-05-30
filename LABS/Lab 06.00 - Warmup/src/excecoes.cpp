#include "excecoes.h"

class TrianguloInvalidoException : public std::exception {
    public:
        virtual const char* what() const override;
};
const char* TrianguloInvalidoException::what() const {
    return "Triangulo inválido";
}