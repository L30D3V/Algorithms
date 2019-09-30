#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

std::vector<bool> visited;
std::vector<int> position_to_age;
int younger;
std::vector<int> speaking_order;

int commander(int a, std::vector<std::vector<int> > graph);
bool swap(int a, int b, std::vector<std::vector<int> > graph);
void meeting(std::vector<std::vector<int> > graph, int a);

int search_younger_age(int a, std::vector<std::vector<int> > graph);
bool verify_cycle(std::vector<std::vector<int> > graph, int a, std::vector<bool> rec_stack);

int main(int argc, char* argv[]) {
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    int n, m, i, read_temp, x, y;
    char command;
    std::ifstream dataset;

    std::vector<std::vector<int> > graph;

    // Verifica se o dataset foi informado como parâmetro para execução do programa.
    if (argc < 2) {
        std::cout << "Dataset não informado na execução do programa.";
        std::cout << std::endl;

        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        // std::cout << std::endl;
        // std::cout << "[TIME] - " << cpu_time_used << std::endl;
        return 1;
    }

    // Recupera nome do dataset e inicializa o arquivo para leitura.
    dataset.open(argv[1]);
    if (!dataset) {
        std::cout << "Dataset não encontrado." << std::endl;

        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        // std::cout << std::endl;
        // std::cout << "[TIME] - " << cpu_time_used << std::endl;
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
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        // std::cout << std::endl;
        // std::cout << "[TIME] - " << cpu_time_used << std::endl;

        return 0;
    }

    // Gerencia os comandos recebidos e chama a função correspondente.
    while (dataset >> command) {
        // Variáveis de controle para execução dos comandos
        int a = 0, b = 0, k = 0;
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

                if (swap(a, b, graph))
                    std::cout << "S T" << std::endl;
                else
                    std::cout << "S N" << std::endl;
                
                break;
            case 'M':
                // Ordem de fala na reunião.
                visited.resize(0);
                visited.resize(n);

                std::cout << "M";
                
                k = n - 1;
                while (!visited[k] && k >= 0) {
                    visited[k] = true;
                    meeting(graph, k);

                    k--;
                }
            
                std::cout << std::endl;
                
                break;

        default:
            std::cout << "Comando inválido!" << std::endl;
            break;
        }
    }


    dataset.close();
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // std::cout << std::endl;
    // std::cout << "[TIME] - " << cpu_time_used << std::endl;

    return 0;
}

int search_younger_age(int a, std::vector<std::vector<int> > graph) {
    visited[a-1] = true;

    if (position_to_age[a-1] < younger || younger == -1) {
        younger = position_to_age[a-1];
    }

    for (int i = 0; i < graph[a-1].size(); i++) {
        if (!visited[graph[a-1][i] - 1]) {
            int result_search = search_younger_age(graph[a-1][i], graph);

            if (result_search < younger || younger == -1) {
                younger = result_search;
            }
        }
    }

    return younger;
}

int commander(int a, std::vector<std::vector<int> > graph) {
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
}

bool swap(int a, int b, std::vector<std::vector<int> > graph) {
    bool has_edge = false;
    int edge = -1;
    std::vector<bool> rec_stack;
    
    rec_stack.resize(graph.size());
    visited.resize(0);
    visited.resize(graph.size());

    for (int i = 0; i < graph[b-1].size(); i++) {
        if (graph[b-1][i] == a) {
            has_edge = true;
            edge = i;

            break;
        }
    }

    if (has_edge) {
        graph[b-1].erase(graph[b-1].begin() + edge);
        graph[a-1].push_back(b);

        if (verify_cycle(graph, a, rec_stack)) {
            return true;
        }
        else {
            graph[a-1].pop_back();
            graph[b-1].push_back(a);

            return false;
        }
    } else {
        return false;
    }
}

bool verify_cycle(std::vector<std::vector<int> > graph, int a, std::vector<bool> rec_stack) {
    visited[a-1] = true;
    rec_stack[a-1] = true;

    bool result = true;
    
    for (int i = 0; i < graph[a-1].size(); i++) {
        if (rec_stack[graph[a-1][i] - 1]) {
            result = false;
        }
        if (!visited[graph[a-1][i] - 1]) {
            result = verify_cycle(graph, graph[a-1][i], rec_stack);
        }
    }
    
    rec_stack[a-1] = false;
    
    return result;
}

void meeting(std::vector<std::vector<int> > graph, int a) {
    for (int i = 0; i < graph[a].size(); i++) {
        if(!visited[graph[a][i] - 1]) {
            visited[graph[a][i] - 1] = true;
            meeting(graph, graph[a][i] - 1);
        }
    }

    std::cout << " " << a+1;
}
