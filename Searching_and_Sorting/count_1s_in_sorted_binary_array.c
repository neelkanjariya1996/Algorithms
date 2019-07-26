#include <stdio.h>
#include <stdlib.h>

int
count_ones (int arr[], int l, int h)
{

    if (h >= l) {
   
        int mid = 0;

        mid = l + ((h - l) / 2);

        if (((mid == h) || (arr[mid + 1]) == 0 ) && (arr[mid] == 1)) {
        
            return (mid + 1);
        }

        if (arr[mid] == 1) {
        
            return count_ones (arr, (mid + 1), h);
        } else {
        
            return count_ones (arr, l, (mid - 1));
        }
    }

    return 0;

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

    int arr[]   = {1, 1, 1, 1, 1, 1, 1, 1, 0};
    int n       = 0;
    int count   = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    count = count_ones (arr, 0, (n - 1));

    if (count != 0) {
    
        printf ("The number of ones in the array is %d\n", count);
    } else {
    
        printf ("There are no ones present in the array\n");
    }

    return 0;

}
