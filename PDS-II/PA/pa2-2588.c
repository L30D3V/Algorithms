#include <stdio.h>
#include <string.h>

int main(){
        char word[1000];
        int i;
        int flag_impar = 0;
        int resto = 0;
        int add = 0;
        int alpha[26];

        while (scanf("%s", word) != EOF) {
                flag_impar = 0;
                add = 0;
                for (i = 0; i < 26; i++){
                        alpha[i] = 0;
                }

                for (i = 0; i < strlen(word); i++){
                        switch (word[i]){
                                case 'a':
                                {
                                        alpha[0] += 1;
                                        break;
                                }
                                case 'b':
                                {
                                        alpha[1] += 1;
                                        break;
                                }
                                case 'c':
                                {
                                        alpha[2] += 1;
                                        break;
                                }
                                case 'd':
                                {
                                        alpha[3] += 1;
                                        break;
                                }
                                case 'e':
                                {
                                        alpha[4] += 1;
                                        break;
                                }
                                case 'f':
                                {
                                        alpha[5] += 1;
                                        break;
                                }
                                case 'g':
                                {
                                        alpha[6] += 1;
                                        break;
                                }
                                case 'h':
                                {
                                        alpha[7] += 1;
                                        break;
                                }
                                case 'i':
                                {
                                        alpha[8] += 1;
                                        break;
                                }
                                case 'j':
                                {
                                        alpha[9] += 1;
                                        break;
                                }
                                case 'k':
                                {
                                        alpha[10] += 1;
                                        break;
                                }
                                case 'l':
                                {
                                        alpha[11] += 1;
                                        break;
                                }
                                case 'm':
                                {
                                        alpha[12] += 1;
                                        break;
                                }
                                case 'n':
                                {
                                        alpha[13] += 1;
                                        break;
                                }
                                case 'o':
                                {
                                        alpha[14] += 1;
                                        break;
                                }
                                case 'p':
                                {
                                        alpha[15] += 1;
                                        break;
                                }
                                case 'q':
                                {
                                        alpha[16] += 1;
                                        break;
                                }
                                case 'r':
                                {
                                        alpha[17] += 1;
                                        break;
                                }
                                case 's':
                                {
                                        alpha[18] += 1;
                                        break;
                                }
                                case 't':
                                {
                                        alpha[19] += 1;
                                        break;
                                }
                                case 'u':
                                {
                                        alpha[20] += 1;
                                        break;
                                }
                                case 'v':
                                {
                                        alpha[21] += 1;
                                        break;
                                }
                                case 'x':
                                {
                                        alpha[22] += 1;
                                        break;
                                }
                                case 'w':
                                {
                                        alpha[23] += 1;
                                        break;
                                }
                                case 'y':
                                {
                                        alpha[24] += 1;
                                        break;
                                }
                                case 'z':
                                {
                                        alpha[25] += 1;
                                        break;
                                }
                                default :
                                {
                                        break;
                                }
                        }
                }

                for (i = 0; i < 26; i++){
                        resto = alpha[i] % 2;
                        if (resto == 1){
                                if (flag_impar == 0){
                                        flag_impar = 1;
                                }
                                else {
                                        add++;
                                }
                        }
                }
                printf("%d\n", add);
        }

        return 0;
}