#include <stdio.h>

int main()
{
    int arr[100];
    int size, target, i, j, found =0;

    //input array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    //input array elements
    printf("Enter array elements: ");

    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    //input target sum
    printf("Enter target sum: ");
    scanf("%d", &target);

    //find pairs
    printf("Pairs with sum %d are : \n", target);

    for(i=0; i<size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            if(arr[i] + arr[j] == target)
            {
                printf("(%d, %d)\n", arr[i], arr[j]);

                found = 1;

            }
        }
    }
    if(found == 0)
    {
        printf("No pairs found. \n");

    }
    return 0;



}