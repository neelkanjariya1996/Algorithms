#include <stdio.h>
#include <stdlib.h>

int
non_repeating_elements (int arr[], int n, int *x, int *y)
{

    int xor         = 0;
    int set_bit_no  = 0;
    int i           = 0;

    *x  = 0;
    *y  = 0;

    xor = arr[0];

    for (i = 1; i < n; i++) {
    
        xor = xor ^ arr[i];
    }

    set_bit_no = xor & (~(xor - 1));

    for (i = 0; i < n; i++) {
    
        if (arr[i] & set_bit_no) {
        
            *x = *x ^ arr[i];
        } else {
        
            *y = *y ^ arr[i];
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

    int arr[]   = {1, 9};
    int n       = 0;
    int x       = 0;
    int y       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    non_repeating_elements (arr, n, &x, &y);

    printf ("The two non repeating elements in the array are %d and %d\n", x, y);

    return 0;

}
