#include <stdio.h>

int main(){
    int num, i;
    long long factorial = 1;

    //enter a postitive number
    printf("Enter a positive integer: ");
    scanf("%d", &num);


    //check if the number is negative
    if (num < 0) {
        printf("Factorial of a negative number doesn't exist\n");
    } else {
        for (i = 1; i <= num; ++i) {
            factorial *= i;
        }

        //display the factorial
        printf("Factorial of %d = %lld\n", num, factorial);
    }
    return 0;   
}