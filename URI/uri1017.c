#include <stdio.h>

int main(){
	int x, u;

	scanf("%d %d", &x, &u);
	
	double total = x*u/12.0;
	
	printf("%.3lf\n", total);

	return 0;
}