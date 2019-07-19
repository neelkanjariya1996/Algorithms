#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RANGE   10

void
counting_sort (int arr[], int n)
{

    int output[n];
    int count[RANGE];
    int i   = 0;

    memset (count, 0, sizeof (count));

    for (i = 0; i < n; i++) {
    
        count[arr[i]]++;
    }

    for (i = 1; i < RANGE; i++) {
    
        count[i] = count[i] + count[i - 1];
    }

    for (i = 0; i < n; i++) {
    
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (i = 0; i < n; i++) {
    
        arr[i] = output [i];
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

    int arr[]   = {4, 1, 9, 0, 2, 5, 8, 1, 3, 2, 3, 6, 7, 3, 5, 4, 9};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before sorting: ");
    print_array (arr, n);

    counting_sort (arr, n);

    printf ("Array after  sorting: ");
    print_array (arr, n);

    return 0;

}
