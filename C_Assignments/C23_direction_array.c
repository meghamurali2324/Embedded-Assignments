#include <stdio.h>

int main()
{
    int arr[100], num[100];
    int size, n, i;
    char dir;

    //input array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    //input array elements
    printf("Enter array elements: \n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }


    //input no.of rotations 
    printf("Enter no.of  rotations : ");
    scanf("%d", &n);

    //input direction of rotation
    printf("Enter direction of rotation (L for left, R for right): ");
    scanf(" %c", &dir);

    //handle cases where n is greater than size of array
    n = n % size;

    //left rotation
    if(dir == 'L' || dir == 'l')
    {
        for(i=0; i<size; i++)
        {
            num[i] = arr[(i + n) % size];
        }
    }

    //right rotation
    else if(dir == 'R' || dir == 'r')
    {
        for(i=0; i<size; i++)
        {
            num[i] = arr[(i - n + size) % size];
        }
    }
    else
    {
        printf("Invalid direction!\n");
        return 0;
    }

    for(i=0; i<size; i++)
    {
        arr[i] = num[i];
    }

    //display rotated array
    printf("Rotated array: \n");

    for(i=0; i<size; i++)
    {
        printf("%d", arr[i]);

    }
    return 0;



}