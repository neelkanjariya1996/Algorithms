#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void
swap (int *a, int *b)
{

    int temp = 0;

    temp    = *a;
    *a      = *b;
    *b      = temp;

}

void
bubble_sort (int arr[], int n)
{

    int i           = 0;
    int j           = 0;
    bool swapped    = false;

    for (i = 0; i < (n - 1); i++) {
    
        swapped = false;

        for (j = 0; j < (n - i - 1); j++) {
        
            if (arr[j] > arr[j+1]) {
            
                swap (&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false) {
        
            break;
        }
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

    int arr[]   = {10, 0, 2, 113, -2, 90};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before Sorting: ");
    print_array (arr, n);

    bubble_sort (arr, n);

    printf ("Array after  Sorting: ");
    print_array (arr, n);

    return 0;

}
