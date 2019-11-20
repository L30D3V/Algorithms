#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

struct Island {
    int price;
    int score;
};

int main(int argc, char* argv[]) {
    int n, m;
    std::vector<Island> islands;

    // Verifica se o dataset foi informado.
    if (argc < 2) {
        std::cout << "Dataset de testes não informado na execução do programa." << std::endl;
        return 1;
    }

    // Recupera dataset e inicializa testes.
    std::ifstream dataset;
    dataset.open(argv[1]);
    if (!dataset) {
        std::cout << "Dataset não encontrado." << std::endl;
        return 1;
    }

    dataset >> n;
    dataset >> m;

    /// ==================Debug messages=====================
    std::cout << "Valor máximo: " << n << std::endl;
    std::cout << "Número de Ilhas: " << m << std::endl;
    /// =====================================================


    // Inicializa valores das ilhas
    islands.resize(m);

    for (int i = 0; i < m; i++) {
        Island island;
        dataset >> island.price;
        dataset >> island.score;
        
        islands[i] = island;
    }

    /// ==================Debug messages=====================
    for (int i = 0; i < m; i++) 
        std::cout << "Ilha: " << islands[i].price << " " << islands[i].score << std::endl;
    /// =====================================================


    // Executa algoritmo guloso

    // Executa algoritmo dinâmico

    return 0;
}