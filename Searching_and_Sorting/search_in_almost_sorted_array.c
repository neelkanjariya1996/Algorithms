#include <stdio.h>
#include <stdlib.h>

int
search (int arr[], int l, int h, int x)
{

    if (h >= l) {
    
        int mid = 0;

        mid = l + ((h - l) / 2);

        if (arr[mid] == x) {
        
            return mid;
        } else if ((mid > l) && (arr[mid- 1] == x)) {
        
            return (mid - 1);
        } else if ((mid < h) && (arr[mid + 1] == x)) {
        
            return (mid + 1);
        }

        if (arr[mid] > x) {
        
            return search (arr, l, (mid - 2), x);
        } else {
        
            return search (arr, (mid + 2), h, x);
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

    int arr[]   = {10, 0, 12, 13, 15, 25, 23};
    int n       = 0;
    int x       = 0;
    int pos     = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    x = 25;
    pos = search (arr, 0, (n - 1), x);

    if (pos != -1) {
    
        printf ("%d is at position %d in the array\n", x, pos);
    } else {
    
        printf ("%d not found in the array\n", x);
    }

    return 0;

}
