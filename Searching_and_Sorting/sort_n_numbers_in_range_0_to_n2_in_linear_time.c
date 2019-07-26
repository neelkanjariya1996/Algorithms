#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
count_sort (int arr[], int n, int exp)
{

    int output[n];
    int count[n];
    int i = 0;

    memset (count, 0, sizeof (count));

    for (i = 0; i < n; i++) {
    
        count[(arr[i]/exp) % n]++;
    }

    for (i = 1; i < n; i++) {
    
        count[i] = count[i] + count[i - 1];
    }

    for (i = (n - 1); i >= 0; i--) {
    
        output[count[(arr[i]/exp) % n] - 1] = arr[i];
        count[(arr[i]/exp) % n]--;
    }

    for (i = 0; i < n; i++) {
    
        arr[i] = output[i];
    }

}

void
sort (int arr[], int n)
{

    count_sort (arr, n, 1);
    count_sort (arr, n, n);

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

    int arr[]   = {3, 19, 0, 7, 24};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before Sorting: ");
    print_array (arr, n);

    sort (arr, n);

    printf ("Array after  Sorting: ");
    print_array (arr, n);

    return 0;

}
