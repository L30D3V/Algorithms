#include <stdio.h>

int main(){
	int n, i;
	int pico = 0;

	scanf("%d", &n);

	int h[100000];
	
	while (n != 0){
		for (i = 0; i < n; i++){
			scanf("%d", &h[i]);
		}
	
		for (i = 0; i < n; i++){
			if(i == 0){
				if((h[i]>h[n-1] && h[i]>h[i+1]) || (h[i]<h[n-1] && h[i]<h[i+1])){
					pico++;
				}
			} else if (i == n-1){
				if((h[i]>h[0] && h[i]>h[i-1]) || (h[i]<h[0] && h[i]<h[i-1])){
					pico++;
				}
			} else{
				if((h[i]>h[i-1] && h[i]>h[i+1]) || (h[i]<h[i-1] && h[i]<h[i+1])){
					pico++;
				}
			}
		}
		printf("%d\n", pico);
		
		scanf("%d", &n);
		pico = 0;
	}
	
	return 0;
}
