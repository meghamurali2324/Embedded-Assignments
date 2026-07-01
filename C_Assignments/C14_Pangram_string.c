#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    int alphabet[26] = {0};
    int i,index, pangram = 1;


    //input from user
    printf("Enter a sentance:");
    fgets(str, sizeof(str), stdin); 

    //check for pangram
    for(i=0; str[i] != '\0'; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            index = str[i] - 'a';
            alphabet[index] = 1;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            index = str[i] - 'A';
            alphabet[index] = 1;
        }
    }

    //check if all letters are present
    for(i=0; i<26; i++){
        if(alphabet[i] == 0){
            pangram = 0;
            break;
        }
    }
    if(pangram){
        printf("The sentence is a pangram.\n");
    }
    else{
        printf("The sentence is not a pangram.\n");
    }
    return 0;
}