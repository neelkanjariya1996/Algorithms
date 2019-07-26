#include <stdio.h>
#include <stdlib.h>

void
intersection (int arr1[], int n1,
              int arr2[], int n2,
              int arr3[], int n3)
{

    int i       = 0;
    int j       = 0;
    int k       = 0;
    int count   = 0;

    printf ("The common elements in the 3 arrays: ");
    while ((i < n1) && (j < n2) && (k < n3)) {
    
        if ((arr1[i] == arr2[j]) &&
            (arr2[j] == arr3[k])) {
        
            printf ("%d ", arr1[i]);
            i++;
            j++;
            k++;
            count++;
        }

        if (arr1[i] < arr2[j]) {
        
            i++;
        } else if (arr2[j] < arr3[k]){
        
            j++;
        } else {
        
            k++;
        }
    }

    if (count == 0) {
    
        printf ("No common element found in the 3 arrays\n");
    } else {
    
        printf ("\n");
    }

}

void
print_array (int arr[], int n)
{

    int i = 0;

    for (i = 0; i < n; i++) {
    
        printf ("%d ", arr[i]);
    }
    printf ("\n");

}

int
main ()
{

    int arr1[]  = {10, 18, 19, 23, 55, 67, 89, 91};
    int arr2[]  = {3, 10, 45, 111, 134, 456};
    int arr3[]  = {3, 10, 45, 123, 567, 789};
    int n1      = 0;
    int n2      = 0;
    int n3      = 0;

    n1 = sizeof (arr1) / sizeof (int);
    n2 = sizeof (arr2) / sizeof (int);
    n3 = sizeof (arr3) / sizeof (int);

    printf ("Array 1: ");
    print_array (arr1, n1);

    printf ("Array 2: ");
    print_array (arr2, n2);

    printf ("Array 3: ");
    print_array (arr3, n3);

    intersection (arr1, n1, arr2, n2, arr3, n3);

    return 0;

}
