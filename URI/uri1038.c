#include<stdio.h>

int main(){
    int x, y;
    double total;
    scanf("%d %d", &x, &y);

    switch (x){
        case 1:
        {
            total = y*(4.00);
            break;
        }
        case 2:
        {
            total = y*(4.50);
            break;
        }
        case 3:
        {
            total = y*(5.00);
            break;
        }
        case 4:
        {
            total = y*(2.00);
            break;
        }
        case 5:
        {
            total = y*(1.50);
            break;
        }
    }

    printf("Total: R$ %.2lf\n", total);

    return 0;
}