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

int calcula_fitas(int memory, int size){
	int fitas;

    fitas = memory * 1024;
    fitas /= size;
    
    return fitas;
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
	FILE *bloco_um, *bloco_dois, *bloco_tres;

	int size, fitas = 3, total = 0;
	int i, j, result, intercala;

	input = fopen(input_file, "r");
	bloco_um = fopen("resultados/bloco_um.txt", "w");
	bloco_dois = fopen("resultados/bloco_dois.txt", "w");
	
	if (input == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO!\n");
		return;
	}

	//Ler tamanho da string e inicializar vetor
	fscanf(input, "%d", &size);
	size += 2;

	char (*vetor)[size] = mathias_malloc(fitas * sizeof(*vetor));
	fgets(vetor[0], size, input);

	//Calcula quantidade possível de linhas
	//fitas = calcula_fitas(memory, size);

	while (fgets(vetor[0], size, input) != 0){
		for (i = 1; i < fitas; i++){
			if (fgets(vetor[i], size, input) == 0)
				break;
		}
		
		ordena_vetor(size, i, vetor);

		//Escreve bloco ordenado
		if (total == 0 || total%2 == 0){
			for (j = 0; j < i; j++){
				fprintf(bloco_um, "%s", vetor[j]);
			}
		} else {
			for (j = 0; j < i; j++){
				fprintf(bloco_dois, "%s", vetor[j]);
			}
		}
		total++;
	}
	
	fclose(bloco_um);
	fclose(bloco_dois);

	for (i = 0; i < total; i++){
		char *bloco1, *bloco2;
		bloco1 = (char*)mathias_malloc(size*sizeof(char));
		bloco2 = (char*)mathias_malloc(size*sizeof(char));

		int eof1, eof2;
		int k;
		
		printf("%d\n", total);

		if (total % 2 == 0 || total == 0){
			// Abrir arquivos
			bloco_um = fopen("resultados/bloco_um.txt", "r");
			bloco_dois = fopen("resultados/bloco_dois.txt", "r");
			bloco_tres = fopen("resultados/bloco_tres.txt", "w");

			// Inicializa controles
			j = 0; k = 0; result = -1;
			do {
				//Ler strings para comparação
				if (result == 1){
					if (fgets(bloco1, size, bloco_um) == 0)
						eof1 = 1;
				} else if (result == 0){
					if (fgets(bloco2, size, bloco_dois) == 0)
						eof2 = 1;
				} else {
					if (fgets(bloco1, size, bloco_um) == 0)
						eof1 = 1;
					if (fgets(bloco2, size, bloco_dois) == 0)
						eof2 = 1;
				}

				//verifica_bloco_vazio();
				//verifica_eof1();
				if (eof1 == 1){
					if (eof2 != 1){
						do {
							if (fgets(bloco2, size, bloco_dois) != 0){
								fprintf(bloco_tres, "%s", bloco2);
							}
							else {
								eof2 = 1;
							} 
						} while (eof2 != 1);
					}
				}
				//verifica_eof2();
				if (eof2 == 1){
					if (eof1 != 1){
						do{
							if (fgets(bloco1, size, bloco_um) != 0){
								fprintf(bloco_tres, "%s", bloco2);
							}
							else {
								eof2 = 1;
							} 
						} while (eof2 != 1);
					}
				}

				//compara();
				result = a_menor_que_b(bloco1, bloco2, size);
				//escreve_menor();
				if (result == 1){
					fprintf(bloco_tres, "%s", bloco1);
					j++;
				} else if (result == 0){
					fprintf(bloco_tres, "%s", bloco2);
					k++;
				}

				//verifica_final_bloco_um();
				if (j == i*fitas){
					//escreve_bloco_dois();
					if (eof2 != 1){
						do {
							if (fgets(bloco2, size, bloco_dois) != 0){
								fprintf(bloco_tres, "%s", bloco2);
								k++;
							}
							else {
								eof2 = 1;
								k = i*fitas;
							}
						} while (k != (i*fitas));
					}
				}

				//verifica_final_bloco_dois();
				if (k == i*fitas){
					//escreve_bloco_um();
					if (eof1 != 1){
						do {
							if (fgets(bloco1, size, bloco_um) != 0){
								fprintf(bloco_tres, "%s", bloco1);
								j++;
							}
							else {
								eof1 = 1;
								j = i*fitas;
							}
						} while (j != (i*fitas));
					}
				}

				//verifica_eof1();
				if (eof1 == 1){
					if (eof2 != 1){
						do{
							if (fgets(bloco2, size, bloco_dois) != 0){
								fprintf(bloco_tres, "%s", bloco2);
							}
							else {
								eof2 = 1;
							} 
						} while (eof2 != 1);
					}
				}
				//verifica_eof2();
				if (eof2 == 1){
					if (eof1 != 1){
						do{
							if (fgets(bloco1, size, bloco_um) != 0){
								fprintf(bloco_tres, "%s", bloco2);
							}
							else {
								eof2 = 1;
							} 
						} while (eof2 != 1);
					}
				}

				intercala = 1;
			} while (intercala == 1);
		}
	}

	fclose(bloco_um);
	fclose(bloco_dois);
	fclose(bloco_tres);

	return;
}