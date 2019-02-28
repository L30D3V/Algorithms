#include <stdio.h>

int main(){
	double radius;
	double pi = 3.14159;
	
	scanf("%lf", &radius);

	double total = (radius * radius * radius) * (4.0/3.0) * pi ;

	printf("VOLUME = %.3lf\n", total);

	return 0;
}