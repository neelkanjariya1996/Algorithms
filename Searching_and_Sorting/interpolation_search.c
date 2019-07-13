#include <stdio.h>
#include <stdlib.h>

int
interpolation_search (int arr[], int n, int x)
{

    int lo  = 0;
    int hi  = 0;
    int pos = 0;

    lo  = 0;
    hi  = (n - 1);

    while ((lo <= hi) && (x >= arr[lo]) && (x <= arr[hi])) {
    
        if (lo == hi) {
        
            if (arr[lo] == x) {
            
                return lo;
            } else {
            
                return -1;
            }
        }

        pos = (lo) + ((double) ((hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        if (arr[pos] == x) {
        
            return pos;
        }

        if (arr[pos] < x) {
        
            lo = pos + 1;
        } else {
        
            hi = pos - 1;
        }
    }

    return -1;

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

    int arr[]   = {0, 1, 2, 4, 5, 6, 8, 9, 10, 12, 15, 18, 120, 340, 543, 760};
    int n       = 0;
    int x       = 0;
    int index   = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    x       = 3;
    index   = interpolation_search (arr, n, x);

    if (index != -1) {
    
        printf ("%d is at position %d in the array\n",x, index);
    } else {
    
        printf ("%d is not present in the array\n", x);
    }

    return 0;

}
