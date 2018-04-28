#include <stdio.h>
#include <string.h>

int main(){
	char sentence[100];
	char tag[10];
	char tagN[5];
	int i, j, isTag, dif, l;

	while(scanf("%s", tag) != EOF){
		scanf("%s", tagN);
		fgets(sentence, 100, stdin);
		isTag = 0;

		for (i = 0; i < strlen(sentence); i++){
			if (sentence[i] == '<'){
				isTag = 1;
			} else if (sentence[i] == '>'){
				isTag = 0;
			}
			if (isTag == 1){
				for (j = 0; j < strlen(tag); j++){
					if(sentence[i+j] > 96){
						if (tag[j] != sentence[i+j] && tag[j] != (sentence[i+j]-32))
							break;	
					}
					if(sentence[i+j] < 96){
						if (tag[j] != sentence[i+j] && tag[j] != (sentence[i+j]+32))
							break;	
					}
				}
				if (j == strlen(tag)){
					if (strlen(tag) == strlen(tagN)){
						for (j = 0; j < strlen(tagN); j++)
							sentence[i+j] = tagN[j];
					}
					else if (strlen(tag) > strlen(tagN)){
						dif = strlen(tag) - strlen(tagN);
						for (j = 0; j < strlen(tagN); j++){
							sentence[i+j] = tagN[j];
						}
						for (j = (i+strlen(tagN)); j < (strlen(sentence)-dif); j++){
							sentence[j] = sentence[j+dif];
						}
						for (j; j < (strlen(sentence)); j++){
							sentence[j] = ' ';
						}
					}
					else if (strlen(tag) < strlen(tagN)){
						dif = strlen(tagN) - strlen(tag);
						for (l = 0; l < strlen(tag); l++){
							sentence[i+l] = tagN[l];
						}
						for (j = strlen(sentence); j >= (i + dif); j--){
							sentence[j+dif] = sentence[j];
						}
						for (l; l < strlen(tagN); l++){
							sentence[i+l] = tagN[l];
						}
					}
				}
			}
		}
		for (i = 0; i < strlen(sentence); i++)
			sentence[i] = sentence[i+1];
		
		char *pos;
		if ((pos=strchr(sentence, '\n')) != NULL)
    		*pos = '\0';

		printf("%s\n", sentence);
	}

	return 0;
}