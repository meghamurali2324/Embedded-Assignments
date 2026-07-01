#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int i,len, palindrome = 1;

    //input from user
    printf("Enter a string:");
    scanf("%s", str);

    len = strlen(str);

    //check for palindrome
    for(i=0; i<len/2; i++){

        if(str[i] != str[len - i - 1]){
            palindrome = 0;
            break;
        }   
    }
    //output results
    if(palindrome){
        printf( "%s is a palindrome.\n",str);
    }else{ 
        printf("%s is not a palindrome.\n", str);
    }
    return 0;
}
 