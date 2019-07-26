#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void
print_pair (int arr[], int n, int x)
{

    int diff    = 0;
    int l       = 0;
    int r       = 0;
    int res_l   = 0;
    int res_r   = 0;

    l       = 0;
    r       = n - 1;
    diff    = INT_MAX;

    while (r > l) {
    
        if (abs(arr[l] + arr[r] - x) < diff) {
        
            res_l   = l;
            res_r   = r;
            diff    = abs (arr[l] + arr[r] - x);
        }

        if ((arr[l] + arr[r]) < x) {
        
            l++;
        } else {
        
            r--;
        }
    }

    printf ("The pair in the array whose sum is closest to %d is [%d, %d]\n", x, arr[res_l], arr[res_r]);

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

    int arr[]   = {5, 9, 10, 14, 56, 78, 89 ,90};
    int n       = 0;
    int x       = 70;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    print_pair (arr, n, x);

    return 0;

}
