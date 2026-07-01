#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], res[200];
    int i, j = 0;

    printf("Enter a sentance: ");
    fgets(str, sizeof(str), stdin);

    for(i=0; str[i] != '\0'; i++)
    {
        if(i == 0 || str[i] != ' ' || str[i - 1] != ' ')
        {
            res[j] = str[i];
            j++;
        }
    }
    res[j] = '\0';

    printf("Cleaned string: %s", res);

    return 0;


}