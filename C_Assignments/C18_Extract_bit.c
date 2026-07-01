#include <stdio.h>

int main(){
    int num, pos, n, ans;

    //Enter an integer
    printf("Enter an integer:");
    scanf("%d", &num);

    //Enter starting position
    printf("Enter starting position:");
    scanf("%d", &pos);

    //Enter number of bits to be extracted
    printf("Enter no.of bits to be extracted:");
    scanf("%d", &n);

    //Extract bits
    ans = (num >> pos) & ((1 << n) - 1);

    //Print the result
    printf("Extracted bits: %d\n", ans);
   
    return 0;


}