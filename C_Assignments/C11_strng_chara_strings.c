#include <stdio.h>

int main()
{
int num, temp, i=0,neg=0;
char str[20], ch;


//input from user
printf("Enter an integer:");
scanf("%d", &num);


//convert string to integer
if(num < 0){
    neg = 1;
    num = -num;

}
temp=num;

if(temp == 0){
    str[i++] ='0';
}
while (temp > 0){
    str[i++] =  (temp % 10) + '0';
    temp /= 10;

}
if(neg){
    str[i++] ='-';
}
str[i] = '\0';  

int start = 0, end=i-1;

while (start < end)
{
    ch=str[start];
    str[start] = str[end];
    str[end] = ch;  

    start++;
    end--;
}
printf("String is :%s\n", str);
return 0; 
}
