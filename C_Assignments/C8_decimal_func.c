#include <stdio.h>

//func to convert dec to any base
void convert(int n, int base){
    char res[50];
    int i = 0, rem;

    //convert decimal to base
    if (n == 0){
        printf("Converted Number = 0\n");
        return;

    }
    while(n > 0){
        rem = n % base;

        if(rem < 10){
            res[i] = rem +'0';
        }
        else{
            res[i] = rem - 10 +'A';

        }

        //n and i update
        n = n / base;
        i++;
        }

        //o/p the converted number
        printf("Converted number = ");

        for(int j = i - 1; j>=0; j--){
            printf("%c", res[j]);

        }
        printf("\n");
    }
    int main(){
        
        int n, base;

        //input from user
        printf("Enter a decimal num: ");
        scanf("%d",&n);

        //negative numbers
        printf("Enter the base to convert to (2-16):");
        scanf("%d", &base);


        //check for valid base
        if(base < 2 || base > 16){
            printf("Invalid base\n");
        }
        else 
        {
            if(n < 0)
            {
                n = -n;
            }
            convert(n, base);
        }
    
            return 0;

        }

    