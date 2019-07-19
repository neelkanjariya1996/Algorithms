#include <stdio.h>
#include <stdlib.h>

void
swap (int *a, int *b)
{

    int temp = 0;

    temp    = *a;
    *a      = *b;
    *b      = temp;

}

void
selection_sort (int arr[], int n)
{

    int i       = 0;
    int j       = 0;
    int min_ind = 0;

    for (i = 0; i < (n - 1); i++) {
    
        min_ind = i;

        for (j = (i + 1); j < n; j++) {
        
            if (arr[j] < arr[min_ind]) {
            
                min_ind = j;
            }
        }

        swap (&arr[i], &arr[min_ind]);
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

    int arr[]   = {22, 90, 10, -1, 7, 0};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before Sorting: ");
    print_array (arr, n);

    selection_sort (arr, n);

    printf ("Array after  Sorting: ");
    print_array (arr, n);

    return 0;

}
