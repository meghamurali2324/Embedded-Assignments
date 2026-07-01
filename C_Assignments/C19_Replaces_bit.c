#include <stdio.h>

int main()
{
    int num1, num2, pos, n, mask, res;

    // input from first number
    printf("Enter first integer: ");
    scanf("%d", &num1);

    //input from second number
    printf("Enter second integer: ");
    scanf("%d", &num2);

    //input starting position
    printf("Enter starting position : ");
    scanf("%d", &pos);

    //input number of bits to be replaced
    printf("Enter no.of bits to be replaced: ");
    scanf("%d", &n);

    //create mask for n bits
    mask = (1 << n) - 1;

    //clear n bits in num1 from pos
    num1 = num1 & ~(mask << pos);

    //set n bits in num1 from pos with n bits of num2
    res = num1 | ((num2 & mask) << pos);

    //display result
    printf("Result after replacing bits: %d\n", res);

    return 0;

}




 