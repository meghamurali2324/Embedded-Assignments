#include <stdio.h>
int main()
{
    char str[100];
    int i;

    //input from user
    printf("Enter a string:");
    fgets(str, sizeof(str), stdin);

    //convert to lowercase
    for(i=0; str[i] !='\0'; i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){

            str[i] = str[i] + 32;

        }
    }
    //output the lowercase string
    printf("String in lowercase: %s", str);
    return 0;   
}