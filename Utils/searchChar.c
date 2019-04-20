#include <stdio.h>
#include <string.h>

int main(){
	char t[1000];
	char p[10] = "ARARA AZUL";
	int flg = 0, i, j;

	scanf("%s", t);
	int total = strlen(t) - 9;

	for (i = 0; i < total; i++){

		for (j = 0; j < 10; j++){
			if (!(p[j] == t[j+i])){
				flg = 1;
				break;
			}
		}
		if (flg == 0)
			printf("Encontrado em %d", i);
		flg = 0;
	}
	return 0;
}