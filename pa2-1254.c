#include <stdio.h>
#include <string.h>

int main(){
	char sentence[100];
	char tag[10];
	int tagN;

	while(scanf("%s", tag) != EOF){
		scanf("%d", &tagN);
		scanf("%s", sentence);

		printf("%s\n%d\n%s", tag, tagN, sentence);
	}

	return 0;
}