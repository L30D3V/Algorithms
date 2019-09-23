#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <iomanip>

void commander() {

}

int main(int argc, char* argv[]) {
    int n, m, i, read_temp, x, y;
    char command;
    std::ifstream dataset;
    std::vector<int> position_to_age;

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
        }

        // Inicializa grafo de acordo com a hierarquia do grupo
        for (int i = 0; i < m; i++) {
            dataset >> x;
            dataset >> y;

            graph[x-1].push_back(y);
        }

    } else {
        return 0;
    }

    // Print matriz de adjacência para referência visual
    for (int i = 0; i < n; i++) {
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

                for (int i = 0; i < n; i++) {
                    if (i+1 != a) {
                        for (int j = 0; j < graph[i].size(); j++) {
                            if (graph[i][j] == a) {
                                if (menor_idade == -1 || position_to_age[i] < menor_idade) {
                                    menor_idade = position_to_age[i];
                                }

                                break;
                            }
                        }
                    }
                }

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

                // Verifica se A é hierarquicamente superior a B
                if (graph[a-1][b-1] != 0) {
                    // Verificar se a troca cria um ciclo
                    // Tomar B como ponto de partida

                } else {
                    std::cout << "S N" << std::endl;
                }
                
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