#include <stdio.h>

int main(){
	double a, b, c;
	float pi = 3.14159;

	scanf("%lf %lf %lf", &a, &b, &c);

	double rect = a*c/2.0;
	double radius = c * c * pi;
	double trap = (a+b)*c/2.0;
	double square = b*b;
	double rect2 = a*b;

	printf("TRIANGULO: %.3lf\nCIRCULO: %.3lf\nTRAPEZIO: %.3lf\nQUADRADO: %.3lf\nRETANGULO: %.3lf\n", rect, radius, trap, square, rect2);

	return 0;
}