#include <stdio.h>

int main() {
    int num;

    //user to enter an integer  
    printf("Enter an Integer: ");
    scanf("%d", &num);

    //Check if the number is even or odd using the modulus operator
    if (num % 2 == 0) {
        printf("%d is even.\n", num);
    } else 
    {
        printf("%d is odd.\n", num);
    }

    return 0;
}