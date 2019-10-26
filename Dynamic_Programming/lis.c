#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
print_array (int *arr, int n)
{

    int i   = 0;
    for (i = 0; i < n; i++) {
    
        printf ("%d ", arr[i]);
    }
    printf ("\n");
}

int
lis (int *arr, int n)
{

    int *dp;
    int i   = 0;
    int j   = 0;
    int max = 0;

    if (!arr) {
    
        return 0;
    }

    if (n == 0) {
    
        return 0;
    }

    dp  = malloc (n * sizeof (int));
    memset (dp, 0, n * sizeof (int));

    dp[0]   = 1;

    for (i = 1; i < n; i++) {
    
        for (j = 0; j < i; j++) {
        
            if ((arr[i] > arr[j]) && (dp[i] < (dp[j] + 1))) {
            
                dp[i]   = dp[j] + 1;
            } else {
            
                dp[i]   = 1;
            }
        }
    }

    printf ("LIS array: ");
    print_array (dp, n);

    max = dp[0];
    for (i = 1; i < n; i++) {
    
        if (dp[i] > max) {
        
            max = dp[i];
        }
    }

    free (dp);

    return max;

}

int
main ()
{

    int arr[]   = {0,1,2,3,4,5,6};
    int n       = 0;
    int lis_len = 0;

    n   = sizeof (arr) / sizeof (int);

    printf ("Org array: ");
    print_array (arr, n);

    lis_len = lis (arr, n);

    printf ("The Lenght of Longest Increasing Subsequence" 
            "for the given array is: %d\n", lis_len);

    return 0;

}
