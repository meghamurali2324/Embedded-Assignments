#include <stdio.h>
int main(){
    int num,i, prime = 1;

    //user to enter an integer
    printf("Enter a number: ");
    scanf("%d", &num);

    //check if the number is prime or not
    if(num < 2){
        prime = 0;
    }else{
        for(i=2;i<num;i++){
            if(num % i == 0){
                prime = 0;
                break;
            }
        }
    }

    //print the result
    if(prime == 1){
        printf("%d is a prime number .\n",num);
    }   else{
        printf("%d is not a prime number .\n",num);         
        }
        return 0;
    }
