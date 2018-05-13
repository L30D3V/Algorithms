// =----------------------------------------------------------=
// =                           AVISO:                         =
// =                   MODIFIQUE ESTE ARQUIVO!                =
// = Aqui, você deve implementar, obrigatoriamente, essas     =
// = duas funções:                                            =
// =     - `a_menor_que_b`: deve retornar quando uma string   =
// =        é menor que a outra (ambos com o mesmo tamanho);  =
// =     - `external_sort`: aqui, você deverá implementar o   =
// =        seu trabalho. Ordene os registros em `input_file` =
// =        e escreva-os em `output_file`, usando somente     =
// =        `memory` KB de memória.                           =
// =                                                          =
// = Instruções:                                              =
// =     - use a função `mathias_malloc` ao invés de          =
// =       `malloc`;                                          =
// =     - use a função `mathias_free` ao invés de `free`;    =
// =     - lembre-se que você tem somente `memory` KB de      =
// =       memória;                                           =
// =     - note que a sua implementação de `a_menor_que_b`    =
// =       afetará o resultado da verificação da resposta.    =
// =                                                          =
// = Dicas:                                                   =
// =     - você pode usar a sua função `a_menor_que_b` em     =
// =       sua implementação da função `external_sort`;       =
// =                                                          =
// =                      BOM TRABALHO!                       =
// =----------------------------------------------------------=

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mem.h"

// Parâmetros:
//     - a: uma cadeia de caracteres de tamanho `len`;
//     - b: uma cadeia de caracteres de tamanho `len`;
//     - len: o tamanho (quantidade de bytes) de `a` e `b`.
// Essa função deve retornar 1, se `a` é menor que `b` (`a` deve vir antes de `b` no
// arquivo), e 0 caso contrário.
// Ela também é usada para verificação da ordenação! Então, se você implementá-la
// erroneamente, a verificação também estará errada! 
int a_menor_que_b(char* a, char* b, int len) {
	int i;
	for (i = 0; i < len; i++){
		if (a[i] < b[i])
			return 1;
		else if (a[i] > b[i])
			return 0;
	}
	return 1;
}

void ordena_vetor(int size, int depth, char vetor[depth][size]){
	int i, j, menor_index = 0, result;
	char menor[size];

	for (i = 0; i < depth; i++){
		strcpy(menor, vetor[i]);
		menor_index = i;

		for (j = i+1; j < depth; j++){
			result = a_menor_que_b(vetor[j], menor, size);
			if (result == 1){
				strcpy(menor, vetor[j]);
				menor_index = j;
			}
		}
		strcpy(vetor[menor_index], vetor[i]);
		strcpy(vetor[i], menor);
	}
	return;
}

// Parâmetros:
//     - input_file: o nome do arquivo com os registros de entrada;
//     - output_file: o nome do arquivo com os registros de entrada ordenados;
//     - memory: o limite de memória a ser usado.
// Essa função deverá ler todos registros do arquivo `input_file`, ordená-los e
// escrevê-los em `output_file`, usando memória menor ou igual a `memory`. Lembre-se
// de fechar todos os arquivos que você usar por aqui!!
void external_sort(const char* input_file, const char* output_file, unsigned int memory) {
	FILE *input;
	FILE *output;
	FILE *bloco_um;
	FILE *bloco_dois;

	int size, i, j, k, total = 0;
	int fitas = 3, result = 0;
	int intercala = 0;

	input = fopen(input_file, "r");
	output = fopen(output_file, "w");
	bloco_um = fopen("resultados/bloco_um.txt", "w");
	bloco_dois = fopen("resultados/bloco_dois.txt", "w");

	if (input == NULL || output == NULL){
		printf("Erro na abertura do arquivo!\n");
		return;
	}

	// Leitura do tamanho da string e escrita em output 
	fscanf(input, "%d", &size);
	//fprintf(output, "%d\n", size);
	fprintf(output, "%d\n", size);

	size += 2;
	//Inicializa vetor de strings
	char (*vetor)[size] = mathias_malloc(fitas * sizeof(*vetor));
	fgets(vetor[0], size, input);
	
	while (fgets(vetor[0], size, input) != 0){
		for (i = 1; i < fitas; i++){
			if (fgets(vetor[i], size, input) == 0)
				break;
		}
		
		ordena_vetor(size, i, vetor);

		//Escreve bloco ordenado
		if (total == 0 || total%2 == 0){
			for (j = 0; j < i; j++){
				fprintf(output, "%s", vetor[j]);
			}
		} else {
			for (j = 0; j < i; j++){
				fprintf(bloco_um, "%s", vetor[j]);
			}
		}
		
		total++;
	}

	fclose(input);
	fclose(output);
	fclose(bloco_um);
	fclose(bloco_dois);

	// Clear-up
	mathias_free(vetor);

	for (i = 0; i < total-1; i++){
		char *bloco1, *bloco2;
		bloco1 = (char*)mathias_malloc(size*sizeof(char));
		bloco2 = (char*)mathias_malloc(size*sizeof(char));


		if (i == 0 || i%2 == 0) {
			//Abrir files
			output = fopen(output_file, "r");
			bloco_um = fopen("resultados/bloco_um.txt", "r");
			bloco_dois = fopen("resultados/bloco_dois.txt", "w");

			//Inicializa result
			result = -1;
			j = 0;
			k = 0;
			intercala = 0;		

			//Ler tamanho das strings
			fscanf(output, "%d", &size);
			size += 2;
			fgets(bloco1, size, output);

			do{
				//Ler strings para comparação
				if (result == 1 && intercala != 1){
					if (fgets(bloco1, size, output) == 0){
						if (intercala == 2){
							intercala = -1;
						} else {
							intercala = 1;
						}
					}
				} else if (result == 0 && intercala != 2 && k != fitas){
					if (fgets(bloco2, size, bloco_um) == 0){
						if (intercala == 1){
							intercala = -1;
						} else {
							intercala = 2;
						}
					}
				} else {
					if (fgets(bloco1, size, output) == 0)
						intercala++;
					if (fgets(bloco2, size, bloco_um) == 0)
						intercala++;
				}

				if (intercala == 1){
					fprintf(bloco_dois, "%s", bloco2);
					result = 0;
					k++;

				} else if (intercala == 2) {
					fprintf(bloco_dois, "%s", bloco1);
					result = 1;
					j++;
				} else {
					result = a_menor_que_b(bloco1, bloco2, size);
				}
				
				if (result == 1 && intercala == 0){
					fprintf(bloco_dois, "%s", bloco1);
					j++;
				} else if (result == 0 && intercala == 0){
					fprintf(bloco_dois, "%s", bloco2);
					k++;
				}

				if (j == fitas){
					if (intercala == 2){
						intercala = -1;
					} else {
						intercala = 1;
					}
				}
				if (k == fitas){
					if (intercala == 1){
						intercala = -1;
					} else {
						intercala = 2;
					}
				}
				if (k == fitas && j == fitas)
					intercala = -1;

				printf("j >>>> %d\tk >>>> %d\n", j, k);
				printf("%d\n", intercala);
			} while (intercala >= 0);
		} else {
			//Abrir files
			output = fopen(output_file, "r");
			bloco_um = fopen("resultados/bloco_um.txt", "w");
			bloco_dois = fopen("resultados/bloco_dois.txt", "r");

			//Inicializa result
			result = -1;
			j = 0;
			k = 0;
			intercala = 0;
			
			//Ler tamanho das strings
			fscanf(output, "%d", &size);
			size += 2;
			fgets(bloco1, size, output);

			do{
				//Ler strings para comparação
				if (result == 1 && intercala != 1){
					if (fgets(bloco1, size, output) == 0){
						if (intercala == 2){
							intercala = -1;
						} else {
							intercala = 1;
						}
					}
				} else if (result == 0 && intercala != 2 && k != fitas){
					if (fgets(bloco2, size, bloco_dois) == 0){
						if (intercala == 1){
							intercala = -1;
						} else {
							intercala = 2;
						}
					}
				} else {
					if (fgets(bloco1, size, output) == 0)
						intercala++;
					if (fgets(bloco2, size, bloco_dois) == 0)
						intercala++;
				}

				if (intercala == 1){
					fprintf(bloco_um, "%s", bloco2);
					result = 0;
					k++;

				} else if (intercala == 2) {
					fprintf(bloco_um, "%s", bloco1);
					result = 1;
					j++;
				} else {
					result = a_menor_que_b(bloco1, bloco2, size);
				}
				
				if (result == 1 && intercala == 0){
					fprintf(bloco_um, "%s", bloco1);
					j++;
				} else if (result == 0 && intercala == 0){
					fprintf(bloco_um, "%s", bloco2);
					k++;
				}

				if (j == fitas){
					printf("CHEGUEI AQUI UM\n");
					if (intercala == 2){
						intercala = -1;
						printf("CHEGUEI AQUI\n");
					} else {
						intercala = 1;
					}
				}
				if (k == fitas){
					if (intercala == 1){
						intercala = -1;
					} else {
						intercala = 2;
					}
				}
				if (k == fitas && j == fitas)
					intercala = -1;

				printf("j >>>> %d\tk >>>> %d\n", j, k);
				printf("%d\n", intercala);
			} while (intercala >= 0);
		}

		fclose(output);
		fclose(bloco_um);
		fclose(bloco_dois);

		mathias_free(bloco1);
		mathias_free(bloco2);
	}
	return;
}
