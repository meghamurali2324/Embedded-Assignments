#include<stdio.h>

//func to count the frequency of digit in a number
void count(int n, int arr[]){
    int dig;

    if (n == 0){
        arr[0]++;

    }
    while(n != 0){
        dig = n%10;
        arr[dig]++;
        n /=10;
    }
}
int main(){
    int n,i;
    int arr[10] = {0};


    //input from user
    printf("Enter a number: ");
    scanf("%d", &n);

    //negative numbers
    if(n < 0){
        n = -n;
    }
    count(n, arr);
     

    //output the frequency of digits
    printf("Frequency of digits:\n");

    for(i=0; i<10; i++)
    {
        printf("Digit %d = %d times\n", i, arr[i]);
    }
    return 0;
}