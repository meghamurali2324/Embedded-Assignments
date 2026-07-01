#include <stdio.h>

int main()
{
    char str[100];
    int i=0;
    int n =0;

    //input from user
    printf("Enter a number:");
    scanf("%s", str);

    //convert string to integer
    while (str[i] != '\0'){
        n = n*10 + (str[i] - '0');
        i++;
    }

    //output the integer value
    printf("Integer value = %d\n", n);
    return 0;

}