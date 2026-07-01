#include <stdio.h>
#include <string.h>

int main(){
    char str[100],temp;
    int i,len;

    //input from user
    printf("Enter a string:");
    scanf("%s", str);

    //reverse the string
    len=strlen(str);

    for(i=0;i<len/2;i++){
        temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;

    }
    //output the reversed string
    printf("Reversed string is: %s\n",str);
    return 0;   

}