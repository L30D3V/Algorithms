#ifndef PDS2_EXCECOES_H
#define PDS2_EXCECOES_H

#include <stdexcept>

class TrianguloInvalidoError : public std::exception{
    public:
        virtual const char* what() const noexcept override;
};

#endif