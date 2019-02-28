/*
In this problem your job is to read some positive and integer numbers and print how many times each number appears in the input, you must write each of the distinct values ​​that appear in the input, ordering by ascending value.

Input
The input contains only one test case. The first line of input contains one integer N, which indicates the quantity of numbers ​​that will be read to X (1 ≤ X ≤ 2000) in the sequence. Each number don't appears more than 20 times in the problem input.

Output
Print the output according to the example provided below, indicating how many times each number appears in the input file, by ascending order of value

7
8
10
8
260
4
10
10


4 aparece 1 vez(es)
8 aparece 2 vez(es)
10 aparece 3 vez(es)
260 aparece 1 vez(es)
*/




#include <stdio.h>

int main(){
	int n, i, j;
	int x[100000];
	int count = 1;

	scanf("%d", &n);


	for (i = 0; i < n; i++){
		scanf("%d", &x[i]);
		if(i != 0){
			for (j = 0; j < i; j++){
				if(x[i] < x[j]){
					int temp = x[i];
					x[i] = x[j];
					x[j] = temp;
				}
			}
		}
	}

	for (i = 0; i < n; i++){
		if(i != 0){
			if(x[i] == x[i-1]){
				count++;
			}
			else{
				printf("%d aparece %d vez(es)\n", x[i-1], count);
				count = 1;
			}
		}
	}
	printf("%d aparece %d vez(es)\n", x[i-1], count);

	return 0;
}