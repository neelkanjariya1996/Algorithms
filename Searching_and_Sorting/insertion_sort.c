#include <stdio.h>
#include <stdlib.h>

void
insertion_sort (int arr[], int n)
{

    int i   = 0;
    int j   = 0;
    int key = 0;

    for (i = 1; i < n; i++) {
    
        key = arr[i];
        j   = i - 1;

        while ((j >= 0) && (arr[j] > key)) {
        
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
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

    int arr[]   = {20, -1, 67, 9, 3, -8};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before sorting: ");
    print_array (arr, n);

    insertion_sort (arr, n);

    printf ("Array after  sorting: ");
    print_array (arr, n);

    return 0;

}
