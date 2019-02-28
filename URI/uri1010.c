#include <stdio.h>

int main(){
	int id, unit1, unit2;
	float value1, value2, total;
	scanf("%d %d %f", &id, &unit1, &value1);
	scanf("%d %d %f", &id, &unit2, &value2);

	total = value1*unit1 + value2*unit2;

	printf("VALOR A PAGAR: R$ %.2f\n", total);
	return 0;
}