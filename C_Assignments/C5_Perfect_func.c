#include <stdio.h>

//function to check if a number is perfect or not
int perfect (int num){
    int i;
    int sum =0;
     for (i=1; i <= num / 2; i++){
        if(num % i == 0){
            sum += i;
    
        }
     }
        return sum;
}
int main(){
    int num;

    //enter a number to check if it is perfect or not
    printf("Enter a number:");
    scanf("%d", &num);

    //check if the number is perfect or not and display the result
    if(perfect(num)){
        printf("%d is a perfect number\n",num);
            }else
            {
                printf("%d is not a perfect number\n", num);

            }
            return 0;

    }
