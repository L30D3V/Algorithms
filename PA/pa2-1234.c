#include<stdio.h>
#include<string.h>
int main()
{
    char sentence[50];
    int i, j, l;

    while(gets(sentence) != NULL){
        j = 0;
        l = strlen(sentence);

        for(i = 0; i < strlen(sentence); i++){
            if(sentence[i]!=' '){
               j++;
            
            if(sentence[i]>96 && j%2==1)
           		sentence[i]-=32;
            else if(sentence[i]<96 && j%2==0)
            	sentence[i]+=32;
            }
        }
        sentence[l]='\0';
        printf("%s\n", sentence);
    }
    return 0;
}