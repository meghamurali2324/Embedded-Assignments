#include <stdio.h>

int main()
{
    int arr[100], temp[100];
    int size, i, j = 0;


    //input array size
    printf("Enter size of array: ");
    scanf("%d", &size);

    //input array elements
    printf("Enter array elements: \n");

    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    //store negative numbers
    for(i=0; i<size; i++)
    {
        if(arr[i] < 0)
        {
            temp[j] = arr[i];
            j++;        
    }
}

//store positive numbers
    for(i=0; i<size; i++)
    {
        if(arr[i] >= 0)
        {
            temp[j] = arr[i];
            j++;        
    }
}


//copy temp array back to original array
    for(i=0; i<size; i++)
    {
        arr[i] = temp[i];
    }

    //display rearranged array
    printf("Rearranged array: \n");

    for(i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;

}