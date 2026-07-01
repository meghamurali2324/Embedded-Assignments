#include <stdio.h>

int main()
{
    int arr1[100], arr2[100], arr3[200];
    int n1, n2, i, j, k;

    //input size of 1st array
    printf("Enter size of 1st array: ");
    scanf("%d", &n1);

    //input elements of 1st array  
    printf("Enter elements of 1st sorted array: \n");
    for(i=0; i<n1; i++)
    {
        scanf("%d", &arr1[i]);

    }

    //input size of 2nd array
    printf("Enter size of 2nd array: ");
    scanf("%d", &n2);

    //input elements of 2nd array
    printf("Enter elements of 2nd array: \n");
    for(i=0; i<n2; i++){

        scanf("%d", &arr2[i]);  
        }
        i=0;
        j=0;
        k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i] < arr2[j])
        {
            arr3[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr3[k] = arr2[j];
            j++;
            k++;
    }
   
    }
    while (i<n1)
    {
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    printf("Merged array: \n");
    for(i=0; i<k; i++)
{
    printf("%d ", arr3[i]);
}
return 0;    
    

    }


