#include <stdio.h>

int main(){
    int num, pos, n, mask, ans;

    // input from user
    printf("Enter an integer:");
    scanf("%d",&num);

    //starting position
    printf("Enter starting position:");
    scanf("%d", &pos);

    // number of bits to toggle 
    printf("Enter no. of bits to toggle:");
    scanf("%d", &n);

    // creating mask
    mask=(( 1 << n)-1) << pos;

    //toggling bits using XOR operator
    ans=num ^ mask;

    //final result after toggling bits
    printf("Result after toggling bit = %d", ans);

    return 0;

    
}