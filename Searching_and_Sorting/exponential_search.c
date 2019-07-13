#include <stdio.h>
#include <stdlib.h>

int
binary_search (int arr[], int l, int r, int x)
{

    if (r >= l) {
    
        int mid = l + ((r - l) / 2);

        if (arr[mid] == x) {
        
            return mid;
        }

        if (arr[mid] < x) {
        
            return binary_search (arr, (mid + 1), r, x);
        } else {
        
            return binary_search (arr, l, (mid - 1), x);
        }
    }

    return -1;

}

int
min (int a, int b)
{

    if (a >= b) {
    
        return a;
    }

    return b;

}

int
exponential_search (int arr[], int n, int x)
{

    if (arr[0] == x) {
    
        return 0;
    }

    int i = 0;

    i = 1;
    while (i < n && (arr[i] <= x)) {
    
        i = i * 2;
    }

    return binary_search (arr, (i/2), min (i, n), x);

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

    int arr[]   = {2, 4, 5, 7, 9, 10, 12, 14, 15, 17 ,19};
    int n       = 0;
    int x       = 0;
    int index   = 0;

    n = sizeof (arr) / sizeof (int);

    x = 2;
    index = exponential_search (arr, n, x);

    printf ("Array: ");
    print_array (arr, n);

    if (index != -1) {
    
        printf ("%d is at location %d in the array\n", x, index);
    } else {
    
        printf ("%d is not present in the array\n", x);
    }

    return 0;

}
