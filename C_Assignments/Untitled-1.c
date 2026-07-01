#include <stdio.h>

int main()
{
    int a=5, b=4;

    a=a;
    a=b;
    b=a;

    printf("after swapping a = %d, and b = %d", a, b);
    return 0;
}