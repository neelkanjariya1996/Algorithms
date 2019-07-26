#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void
pair (int arr1[], int n, int arr2[], int m, int x)
{

    int res_l   = 0;
    int res_r   = 0;
    int l       = 0;
    int r       = 0;
    int diff    = 0;

    l       = 0;
    r       = (m -1);
    diff    = INT_MAX;

    while ((l < n) && (r >= 0)) {
    
        if (abs(arr1[l] + arr2[r] - x) < diff) {
        
            res_l   = l;
            res_r   = r;
            diff    = abs (arr1[l] + arr2[r] - x);
        }

        if (arr1[l] + arr2[2] < x) {
        
            l++;
        } else {
        
            r--;
        }
    }

    printf ("The closest pair is [%d, %d]\n", arr1[res_l], arr2[res_r]);

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

    int arr1[]  = {-4, 0, 9, 13, 18, 23};
    int arr2[]  = {-2, 4, 7, 19, 30, 45};
    int n       = 0;
    int m       = 0;
    int x       = 0;

    n = sizeof (arr1) / sizeof (int);
    m = sizeof (arr2) / sizeof (int);

    printf ("Array1: ");
    print_array (arr1, n);

    printf ("Array2: ");
    print_array (arr2, m);

    x = 55;
    pair (arr1, n, arr2, m, x);

    return 0;

}
