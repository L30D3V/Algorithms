#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

std::vector<bool> visited;
std::vector<int> position_to_age;
int younger;

int commander(int a, std::vector<std::vector<int> > graph);
bool swap(int a, int b, std::vector<std::vector<int> > graph);

int search_younger_age(int a, std::vector<std::vector<int> > graph);
bool verify_cycle(std::vector<std::vector<int> > graph);

int main(int argc, char* argv[]) {
    int n, m, i, read_temp, x, y;
    char command;
    std::ifstream dataset;

    std::vector<std::vector<int> > graph;

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
    dataset >> m;
    dataset >> i;
    position_to_age.resize(n);
    graph.resize(n);

    // Verifica se a equipe possui integrantes e inicializa o grafo.
    if (n > 0) {
        // Cria lista para correlação entre posição e idade dos membros.
        for (int i = 0; i < n; i++) {
            dataset >> read_temp;
            position_to_age[i] = read_temp;

            graph[i].resize(0);
        }

        // Inicializa grafo de acordo com a hierarquia do grupo
        for (int i = 0; i < m; i++) {
            dataset >> x;
            dataset >> y;

            graph[y-1].push_back(x);
        }

    } else {
        return 0;
    }

    // Print lista de adjacência para referência visual
    for (int i = 0; i < n; i++) {
        std::cout << i << " - ";
        for (int j = 0; j < graph[i].size(); j++) {
            std::cout << std::setfill('0') << std::setw(2) << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Gerencia os comandos recebidos e chama a função correspondente.
    while (dataset >> command) {
        // Variáveis de controle para execução dos comandos
        int a = 0, b = 0;
        int menor_idade = -1;

        switch (command)
        {
            // Realiza a ação COMMANDER
            case 'C':
                dataset >> a;
                std::cout << "C ";

                menor_idade = commander(a, graph);

                // Caso a idade seja -1, o usuário não tem superior. Caso contrário exibe a idade encontrada.
                if (menor_idade == -1)
                    std::cout << "*" << std::endl;
                else
                    std::cout << menor_idade << std::endl;

                break;
            case 'S':
                // Troca de comando entre A e B
                dataset >> a;
                dataset >> b;

                std::cout << "A - ";
                std::cout << a << " " << b << std::endl;

                if (swap(a, b, graph))
                    std::cout << "S T" << std::endl;
                else
                    std::cout << "S N" << std::endl;
                
                break;
            case 'M':
                // Ordem de fala na reunião.
                std::cout << "Meeting" << std::endl;
                break;

        default:
            std::cout << "Comando inválido!" << std::endl;
            break;
        }
    }


    dataset.close();

    return 0;
}

int search_younger_age(int a, std::vector<std::vector<int> > graph) {
    // std::cout << "[DFS - Start] - Depth search for " << a << std::endl;

    visited[a-1] = true;

    // std::cout << "[DFS - Visited] - ";
    // for (int i = 0; i < visited.size(); i++) {
    //     std::cout << visited[i] << " ";
    // }
    // std::cout << std::endl;

    if (position_to_age[a-1] < younger || younger == -1) {
        younger = position_to_age[a-1];
    }

    // if (graph[a-1].empty()) {
    //     std::cout << "[DFS - Empty]" << std::endl;
    // }

    // for (int i = 0; i < graph[a-1].size(); i++) {
    //     std::cout << graph[a-1][i] << " ";
    // }
    // std::cout << std::endl;

    for (int i = 0; i < graph[a-1].size(); i++) {
        if (!visited[graph[a-1][i] - 1]) {
            int result_search = search_younger_age(graph[a-1][i], graph);

            // std::cout << "[DFS - " << a << "] - Retorno: " << result_search << std::endl;
            if (result_search < younger || younger == -1) {
                younger = result_search;
            }
        }
        // else
            // std::cout << graph[a-1][i] << " visited already" << std::endl;
    }

    // std::cout << "[DFS - End] - " << a << " " << younger << std::endl;

    return younger;
}

int commander(int a, std::vector<std::vector<int> > graph) {
    // std::cout << std::endl;
    // std::cout << "-----------------------------------" << std::endl;
    // std::cout << "[COMMANDER] - START" << std::endl;

    // Destroy current values and resize vector
    visited.resize(0);
    visited.resize(graph.size());

    // Initialize younger age
    younger = -1;
    int result = search_younger_age(a, graph);
    if (result == position_to_age[a-1])
        return -1;
    else
        return result;

    // std::cout << "[COMMANDER] - END" << std::endl;
    // std::cout << "-----------------------------------" << std::endl;
}

bool swap(int a, int b, std::vector<std::vector<int> > graph) {
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "[SWAP] - START" << std::endl;

    bool has_edge = false;

    for (int i = 0; i < graph[b-1].size(); i++) {
        if (graph[b-1][i] == a)
            has_edge = true;
    }

    if (has_edge) {
        // TODO: creates new graph as a copy of the original
        // TODO: remove item from graph[b-1]
        // TODO: add edge to graph[a-1]

        verify_cycle(graph);
    } else {
        return false;
    }


    std::cout << "[SWAP] - END" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

bool verify_cycle(std::vector<std::vector<int> > graph) {
    return false;
}
