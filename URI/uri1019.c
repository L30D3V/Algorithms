#include <stdio.h>
int main()
{
    int sec, min, h;
    scanf("%d", &sec);

    h = sec/3600;
    sec %= 3600;
    min = sec/60;
    sec %= 60;

    printf("%d:%d:%d\n", h, min, sec);

    return 0;
}