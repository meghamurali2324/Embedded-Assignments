#include <stdio.h>

int main()
{
    int arr[100], size, i;
    int Lar, SecLar, Small, SecSmall;

    //input array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    //input array elements
    printf("Enter array elements: \n");

    //loop to read array elements
    for(i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    //initialize variables
    Lar = SecLar = -99999;
    Small = SecSmall = 99999;

    //loop to find second largest and second smallest elements
    for (i =0; i < size; i++)
    {
        if(arr[i] > Lar)
        {
            SecLar = Lar;
            Lar = arr[i];
        } 
        else if(arr[i] > SecLar && arr[i] != Lar)
        {
            SecLar = arr[i];
        }
        if(arr[i] < Small)
        {
            SecSmall = Small;
            Small = arr[i];
        }
        else if(arr[i] < SecSmall && arr[i] != Small)
        {
            SecSmall = arr[i];
            
        }
    }
    //check if second largest and second smallest elements exist
    if(SecLar == -99999 || SecSmall == 99999)
    {
        printf("There is no second largest or second smallest element in the array.\n");
    }
    else
    {
        printf("Second largest element: %d\n", SecLar);
        printf("Second smallest element: %d\n", SecSmall);
    }
    return 0;
    
}