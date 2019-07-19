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

int
partition (int arr[], int low, int high)
{

    int pivot   = 0;
    int i       = 0;
    int j       = 0;

    pivot   = arr[high];
    i       = (low - 1);

    for (j = low; j < high; j++) {
    
        if (arr[j] <= arr[high]) {
        
            i++;
            swap (&arr[i], &arr[j]);
        }
    }

    swap (&arr[i + 1], &arr[high]);

    return (i + 1);

}

void
quick_sort (int arr[], int low, int high)
{

    if (low < high) {

        int pi  = partition (arr, low, high);

        quick_sort (arr, low, (pi - 1));
        quick_sort (arr, (pi + 1), high);

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

    int arr[]   = {10, 0, -3, 90, 78, 23, 89, 1, 190};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before Sorting: ");
    print_array (arr, n);

    quick_sort (arr, 0, (n - 1));

    printf ("Array after  Sorting: ");
    print_array (arr, n);

    return 0;

}
