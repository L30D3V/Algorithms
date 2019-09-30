#include <stdio.h>
#include <string.h>

int main() {
    unsigned int n, l, c, lines, characters;
    char word[200];

    while (scanf("%d %d %d", &n, &l, &c) != EOF) {
        lines = 1;
        characters = 0;
        int an=1;
        while (n--) {
            scanf("%s", word);
            if (characters + (characters != 0) + strlen(word) <=c) {
                characters += strlen(word) +  (characters != 0);

            } else {
                characters = strlen(word);
                lines++;
                if(lines > l){
                	an++;
                	lines=1;
                }
            }
        }

		printf("%d\n", an);
    }
    return 0;
}
