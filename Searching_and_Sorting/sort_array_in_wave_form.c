#include <stdio.h>
#include <stdlib.h>

void
swap (int *a, int *b)
{

    int temp    = 0;

    temp    = *a;
    *a      = *b;
    *b      = temp;

}

void
sort_in_wave_form (int arr[], int n)
{

    int i = 0;
    for (i = 0; i < n; i = i + 2) {
    
        if ((i > 0) && (arr[i - 1] > arr[i])) {
        
            swap (&(arr[i - 1]), &(arr[i]));
        }

        if ((i < (n - 1)) && (arr[i] < arr[i + 1])) {
        
            swap (&(arr[i]), &(arr[i + 1]));
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

    int arr[]   = {10, 2, 4, 5, 3, 123, 7, 6, 9};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before Sorting in waveform: ");
    print_array (arr, n);

    sort_in_wave_form (arr, n);

    printf ("Array after  Sorting in waveform: ");
    print_array (arr, n);

    return 0;

}
