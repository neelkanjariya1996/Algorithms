#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int
lbs (int *arr, int n)
{

    int *lis;
    int *lds;
    int max = 0;
    int i   = 0;
    int j   = 0;

    if (!arr) {
    
        return 0;
    }

    if (n == 0) {
    
        return 0;
    }

    lis = malloc (n * sizeof (int));
    lds = malloc (n * sizeof (int));

    
    for (i = 0; i < n; i++) {
   
        lis[i]  = 1;
    }

    for (i = 0; i < n; i++) {
    
        lds[i]  = 1;
    }

    for (i = 1; i < n; i++) {
    
        for (j = 0; j < i; j++) {
        
            if ((arr[i] > arr[j]) && (lis[i] < lis[j] + 1)) {
            
                lis[i]  = lis[j] + 1;
            }
        }
    }

    for (i = (n - 2); i >= 0; i--) {
    
        for (j = (n - 1); j > i; j--) {
        
            if ((arr[i] > arr[j]) && (lds[i] < lds[j] + 1)) {
            
                lds[i]  = lds[j] + 1;
            }
        }
    }

    max = lis[0] + lds[0] - 1;
    for (i = 1; i < n; i++) {
    
        if ((lis[i] + lds[i] - 1) > max) {
        
            max = lis[i] + lds[i] - 1;
        }
    }

    free (lis);
    free (lds);

    return max;

}

int
main ()
{

    int arr[]   = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n       = 0;

    n   = sizeof (arr) / sizeof (int);

    printf ("The length of Longest Bitonic Subsequence is: %d\n", lbs (arr, n));

    return 0;

}
