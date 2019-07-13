#include <stdio.h>
#include <stdlib.h>

int
ternary_search (int arr[], int l, int r, int x)
{

    if (r >= l) {
    
        int mid1 = l + (r - l) / 3;
        int mid2 = mid1 + (r - l) / 3;

        if (arr[mid1] == x) {
        
            return mid1;
        }

        if (arr[mid2] == x) {
        
            return mid2;
        }

        if (arr[mid1] > x) {
        
            return ternary_search (arr, l, (mid1 - 1), x);
        } else if (arr[mid2] < x) {
        
            return ternary_search (arr, (mid2 + 1), r, x);
        } else {
        
            return ternary_search (arr, (mid1 + 1), (mid2 - 1), x);
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

    int arr[]   = {2, 4, 10, 20, 35, 40, 89, 98, 100, 102};
    int n       = 0;
    int x       = 0;
    int index   = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    x       = 102;
    index   = ternary_search (arr, 0, (n - 1), x);

    if (index != -1) {
    
        printf ("%d is at position %d\n", x, index);
    } else {
    
        printf ("%d is not present in the array\n", x);
    }

    return 0;

}
