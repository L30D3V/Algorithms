#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {

    int n, i, j, temp;
    std::ifstream dataset;

    // Verifica se o dataset foi informado como parâmetro para execução do programa.
    if (argc < 2) {
        std::cout << "Dataset não informado na execução do programa.";
        std::cout << std::endl;

        return 1;
    }

    // Recupera nome do dataset e inicializa o arquivo para leitura.
    dataset.open(argv[1]);
    if (!dataset) {
        std::cout << "Dataset não encontrado." << std::endl;

        return 1;
    }

    // Inicializa variáveis de controle do programa.
    dataset >> n;
    dataset >> i;
    dataset >> j;

    // Inicializa SUDOKU
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            dataset >> temp;
            std::cout << temp << "\t";
        }
        std::cout << std::endl;
    }

    // Verifica 

    return 0;
}