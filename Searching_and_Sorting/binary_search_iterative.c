#include <stdio.h>
#include <stdlib.h>

int
binary_search (int arr[], int l, int r, int x)
{
    while (r >= l) {
    
        int mid = (l + r) / 2;

        if (arr[mid] == x) {
        
            return mid;
        }

        if (arr[mid] < x) {
        
            l = mid + 1;
        } else {
        
            r = mid - 1;
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

    int arr[]   = {2, 4, 6, 8, 10};
    int n       = 0;
    int x       = 0;
    int index   = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    x = 10;
    index = binary_search (arr, 0, (n - 1), x);
    
    if (index != -1) {
    
        printf ("%d is at position %d\n", x, index);
    } else {
    
        printf ("%d not present in the array\n", x);
    }

    return 0;

}
