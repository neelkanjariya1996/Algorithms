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

int
next_gap (int gap)
{

    gap = (gap * 10) / 13;

    if (gap <= 1) {
    
        return 1;
    }

    return gap;

}

void
comb_sort (int arr[], int n)
{

    int i           = 0;
    int gap         = 0;
    bool swapped    = false;

    gap     = n;
    swapped = true;

    while ((gap != 1) || (swapped == true)) {
    
        gap     = next_gap (gap);
        swapped = false;

        for (i = 0; i < (n - gap); i++) {
        
            if (arr[i] > arr[i + gap]) {
            
                swap (&arr[i], &arr[i + gap]);
                swapped = true;
            }
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

    int arr[]   = {0, 1, 7, 89, -3, 5, 89, 12, -234, 678};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before Sorting: ");
    print_array (arr, n);

    comb_sort (arr, n);

    printf ("Array after  sorting: ");
    print_array (arr, n);

    return 0;

}
