#include <stdio.h>
#include <string.h>

int main() {
    int n, l, c, linhas, letras, paginas;
    char palavra[200];

    while (scanf("%d %d %d", &n, &l, &c) != EOF) {
        linhas = 1;
        letras = 0;

        paginas = 1;
        
        for (n; n>0; n--)
        {
            scanf("%s", palavra);
            if (letras + (letras != 0) + strlen(palavra) <=c) {
                letras += strlen(palavra) +  (letras != 0);

            } else {
                letras = strlen(palavra);
                linhas++;
                if(linhas > l){
                    paginas++;
                    linhas=1;
                }
            }
        }

        printf("%d\n", paginas);
    }
    return 0;
}