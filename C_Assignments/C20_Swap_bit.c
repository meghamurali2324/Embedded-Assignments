#include <stdio.h>

int main()
{
    int num1, num2, pos, n, mask, bit1, bit2;

    //input from first number
    printf("Enter first integer: ");
    scanf("%d", &num1);
    
    //input from sec number
    printf("Enter second integer: ");
    scanf("%d", &num2);

    //input starting position
    printf("Enter starting position: ");
    scanf("%d", &pos);

    //input no.of bits to swap
    printf("Enter no.of bits to swap: ");
    scanf("%d", &n);

    //create mask for n bits
    mask = (1 << n) - 1;

    //get n bits from num1 and num2 at pos
    bit1 = (num1 >> pos) & mask;
    bit2 = (num2 >> pos ) & mask; 

    //clear n bits in num1 and num2 from pos
    num1 = num1 & ~(mask << pos);   
    num2 = num2 & ~(mask << pos);

    //swap bits
    num1 = num1 | (bit2 << pos);
    num2 = num2 | (bit1 << pos);

    //display result
    printf("After swapping bits: \n");
    printf("First number = %d\n", num1);
    printf("Second number = %d\n", num2);

    return 0;


}