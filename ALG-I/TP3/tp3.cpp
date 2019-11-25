#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>

bool solveSudoku();
void printSudoku(std::vector<std::vector<int> > sudoku);
bool checkValid(std::vector<std::vector<int> > sudokuGrid);
void printPrettySudoku(std::vector<std::vector<int> > sudokuGrid);

int linha, coluna, sudokuSize;
std::vector<int> possibleValues;
std::vector<std::vector<int> > sudokuGrid;

int main(int argc, char* argv[]) {
    clock_t start, end;
    double cpu_time_used;

    std::ifstream dataset;

    start = clock();

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
    dataset >> sudokuSize;
    dataset >> coluna;
    dataset >> linha;

    sudokuGrid.resize(sudokuSize);
    possibleValues.resize(sudokuSize);

    // Inicializa Sudoku
    for (int i = 0; i < sudokuSize; i++){
        sudokuGrid[i].resize(sudokuSize);

        for (int j = 0; j < sudokuSize; j++) {
            dataset >> sudokuGrid[i][j];
        }

        possibleValues[i] = (i + 1);
    }

    // Resolve Sudoku
    if (solveSudoku()) 
        std::cout << "solução" << std::endl;
    else 
        std::cout << "sem solução" << std::endl;

    printSudoku(sudokuGrid);
    
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // std::cout << cpu_time_used << std::endl;

    return 0;
}

void printPrettySudoku(std::vector<std::vector<int> > sudokuGrid) {
    for (int i = 0; i < sudokuGrid.size(); i++) {
        if (i % linha == 0) {
            for (int k = 0; k < sudokuGrid.size(); k++)
                std::cout << "----";

            std::cout << std::endl; 
        }

        for (int j = 0; j < sudokuGrid.size(); j++) {
            if (j % coluna == 0)
                std::cout << "|  ";

            std::cout << sudokuGrid[i][j] << "  ";
        }

        std::cout << std::endl;
    }
}

void printSudoku(std::vector<std::vector<int> > sudoku) {
    for (int i = 0; i < sudoku.size(); i++) {
        for (int j = 0; j < sudoku.size(); j++) {
            std::cout << sudoku[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

bool checkValid(std::vector<std::vector<int> > sudokuGrid) {
    // Recebe o grid modificado e verifica se o Sudoku é válido
    bool valid = true;
    
    for (int i = 0; i < sudokuGrid.size(); i++) {
        for (int j = 0; j < sudokuGrid.size(); j++) {
            // Desconsidera células vazias
            if (sudokuGrid[i][j] != 0) {
                // Verifica se todas as linhas são válidas
                for (int k = j + 1; k < sudokuGrid.size(); k++) {
                    if (sudokuGrid[i][j] == sudokuGrid[i][k]) {
                        valid = false;
                        break;
                    }
                }

                // Verifica se o subgrid é válido
                int x_quadrante = linha * ((i / linha));
                int y_quadrante = coluna * ((j / coluna));

                for (int l = x_quadrante; l < (x_quadrante + linha); l++) {
                    for (int c = y_quadrante; c < (y_quadrante + coluna); c++) {
                        if ((i != l && j != c) && sudokuGrid[i][j] == sudokuGrid[l][c]) {
                            valid = false;
                            break;
                        }
                    }
                }
            }
            
            // Desconsidera células vazias
            if (sudokuGrid[j][i] != 0) {
                // Verifica se todas as colunas são válidas
                for (int k = j + 1; k < sudokuGrid.size(); k++) {
                    if (sudokuGrid[j][i] == sudokuGrid[k][i]) {
                        valid = false;
                        break;
                    }
                }
            }
        }
    }

    return valid;
}

bool solveSudoku() {
    int x_pos = -1, y_pos = -1;

    // Procura por células vazias no Sudoku
    for (int i = 0; i < sudokuSize; i++) {
        if (x_pos == -1 && y_pos == -1) {
            for (int j = 0; j < sudokuSize; j++) {
                if (sudokuGrid[i][j] == 0) {
                    x_pos = i;
                    y_pos = j;

                    break;
                }
            }
        } else {
            break;
        }
    }

    // Caso não encontre células vazias, Sudoku está resolvido
    if (x_pos == -1 && y_pos == -1)
        return true;

    // Percorre array de valores possíveis e verifica se são válidos
    for (int i = 0; i < possibleValues.size(); i++) {
        sudokuGrid[x_pos][y_pos] = possibleValues[i];
        
        // Verifica se o valor testado é válido
        if (checkValid(sudokuGrid)) {
            // Tenta resolver o resto do Sudoku usando o valor selecionado
            if (solveSudoku()) {
                return true;
            }
        }

        // Caso não seja possível, remove o valor testado e tenta novamente
        sudokuGrid[x_pos][y_pos] = 0;
    }

    // Caso nenhum dos valores testados seja possível ou resolva o Sudoku
    // retorna falso e altera os valores anteriores na recursão
    return false;
}