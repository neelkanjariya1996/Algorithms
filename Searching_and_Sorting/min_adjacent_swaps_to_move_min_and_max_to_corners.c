#include <stdio.h>
#include <stdlib.h>

void
min_swaps (int arr[], int n)
{

    int min = 0;
    int max = 0;
    int l   = 0;
    int r   = 0;
    int i   = 0;

    min = arr[0];
    max = arr[0];

    for (i = 1; i < n; i++) {
    
        if (arr[i] <= min) {
        
            min = arr[i];
            r   = i;
        }

        if (arr[i] > max) {
        
            max = arr[i];
            l   = i;
        }
    }

    if (l > r) {
    
        printf ("Minimum number of swaps to move min and max to corners is %d\n", (l + (n - r - 2)));
    } else {
    
        printf ("Minimum number of swaps to move min and max to corners is %d\n", (l + (n - r - 1)));
    }

}

void
print_array (int arr[], int n)
{

    int i   = 0;
    for (i = 0; i < n; i++) {
    
        printf ("%d ", arr[i]);
    }
    printf ("\n");

}

int
main ()
{

    int arr[]   = {3, 1, 5, 3, 5, 5, 2};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    min_swaps (arr, n);

    return 0;

}
