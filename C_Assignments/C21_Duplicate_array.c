#include <stdio.h>

int main() {
    int arr[100], size, i, j, k;

    // enter size and elements of array
    printf("Enter size of array: ");
    scanf("%d", &size);

    //input array elements
    printf("Enter array elements:\n");

    //read array elements
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    //remove duplicates
    for (i = 0; i < size; i++)
     {
        for (j = i + 1; j < size; )
         {
            if (arr[i] == arr[j]) 
            {
                for (k = j; k < size - 1; k++) 
                {
                    arr[k] = arr[k + 1];
                }
                size--;
            } else {
                j++;
            }
        }
    }

    // Output section
    printf("Array after removing duplicates: \n");

    for (i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}