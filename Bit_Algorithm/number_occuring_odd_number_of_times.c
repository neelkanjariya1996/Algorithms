#include <stdio.h>
#include <stdlib.h>

int
number_occuring_odd_time (int arr[], int n)
{

    int xor = 0;
    int i   = 0;

    xor = arr[0];
    for (i = 1; i < n; i++) {
    
        xor = xor ^ arr[i];
    }

    return xor;

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

    int arr[]   = {1, 2, 4, 5, 6, 1, 3, 2, 4, 5, 6, 3, 3 ,1, 2, 2, 1};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    printf ("The number repeating odd number of times is %d\n",
            number_occuring_odd_time (arr, n));

    return 0;

}
