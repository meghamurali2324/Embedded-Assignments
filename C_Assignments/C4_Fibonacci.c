#include <stdio.h>

int main(){
    int n, i;
    int first=0, sec=1, next;

    //enter the number of terms to display in the Fibonacci series
    printf("Enter the number of terms:");
    scanf("%d", &n);

    //display the Fibonacci series
    printf("Fibonacci Series:");


    //calculate and display the Fibonacci series up to n terms

    for(i = 0; i <= n; i++){
        printf("%d", first);
        next = first + sec;
        first = sec;
        sec = next;

    }
    return 0;   
}