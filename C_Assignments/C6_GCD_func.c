#include <stdio.h>

//function to calculate GCD using Euclidean algorithm
int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
    }
    int main(){
        int num1,num2,result;

        //input from user
        printf("Enter two numbers:");
        scanf("%d %d", &num1,&num2);

        //calculate GCD
        result=gcd(num1,num2);
        printf("GCD of %d and %d = %d\n", num1,num2,result);
        return 0;


    }
