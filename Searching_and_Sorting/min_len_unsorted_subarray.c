#include <stdio.h>
#include <stdlib.h>

void
min_len_subarray (int arr[], int n)
{

    int s   = 0;
    int e   = 0;
    int i   = 0;
    int min = 0;
    int max = 0;

    for (s = 0; s < (n - 1); s++) {
    
        if (arr[s] > arr[s + 1]) {

            break;
        }
    }

    if (s == (n - 1)) {
    
        printf ("The complete array is sorted\n");
        return;
    }

    for (e = (n - 1); e >= 0; e--) {
    
        if (arr[e] < arr[e - 1]) {
        
            break;
        }
    }

    min = arr[s];
    max = arr[s];
    for (i = (s + 1); i <= e; i++) {
   
        if (arr[i] < min) {
        
            min = arr[i];
        }

        if (arr[i] > max) {
        
            max = arr[i];
        }
    }

    for (i = 0; i < s; i++) {
    
        if (arr[i] > min) {
        
            s = i;
            break;
        }
    }

    for (i = (n - 1); i >= (e + 1); i--) {
    
        if (arr[i] < max) {
        
            e = i;
            break;
        }
    }

    printf ("The minimum lenght subaray sorting which the complete array is sorted is %d to %d\n", s, e);

    return;

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

    int arr[]   = {0, 1, 3, 4, 5, 10, 7};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    min_len_subarray (arr, n);

    return 0;

}
