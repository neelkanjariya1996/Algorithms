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
heapify (int arr[], int n, int i)
{

    int largest = 0;
    int l       = 0;
    int r       = 0;

    largest = i;
    l       = 2 * i + 1;
    r       = 2 *i + 2;

    if ((l < n) && (arr[l] > arr[largest])) {
    
        largest = l;
    }

    if ((r < n) && (arr[r] > arr[largest])) {
    
        largest = r;
    }

    if (i != largest) {
    
        swap (&arr[i], &arr[largest]);
        heapify (arr, n, largest);
    }

}

void
heap_sort (int arr[], int n)
{

    int i = 0;

    for (i = (n/2 - 1); i >= 0; i--) {
    
        heapify (arr, n, i);
    }

    for (i = (n -1); i >= 0; i--) {
    
        swap (&arr[0], &arr[i]);
        heapify (arr, i, 0);
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

    int arr[]   = {2, 10, -2, -7, 90, 7, 32, 6};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before Sorting: ");
    print_array (arr, n);

    heap_sort (arr, n);

    printf ("Array after  Sorting: ");
    print_array (arr, n);

    return 0;

}
