#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void
swap (int *a, int *b)
{

    int temp    = 0;

    temp    = *a;
    *a      = *b;
    *b      = temp;

}

int
partition (int arr[], int l, int r)
{

    int x = 0;
    int i = 0;
    int j = 0;

    x = arr[r];
    i = l;

    for (j = l; j < r; j++) {
    
        if (arr[j] <= x) {
        
            swap (&arr[i], &arr[j]);
            i++;
        }
    }

    swap (&arr[i], &arr[r]);

    return i;

}

int
random_partition (int arr[], int l, int r)
{

    int n       = 0;
    int pivot   = 0;

    n = r - l + 1;

    pivot = rand() % n;

    swap (&arr[pivot + l], &arr[r]);

    return partition (arr, l, r);

}

int
kth_smallest_element (int arr[], int l, int r, int k)
{

    if ((k > 0) && (k <= (r - l + 1))) {
    
        int pos = 0;

        pos = random_partition (arr, l, r);

        if ((pos - l) == (k - 1)) {
        
            return arr[pos];
        }

        if ((pos - l) > (k - 1)) {
        
            return kth_smallest_element (arr, l, (pos - 1), k);
        }

        return kth_smallest_element (arr, (pos + 1), r, (k - pos + l -1));
    }

    return INT_MAX;

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

    int arr[]       = {3, 10, -3, 9, 6, 12, 15, 8, 0, 2};
    int n           = 0;
    int k           = 0;
    int smallest    = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    k = 3;
    
    smallest = kth_smallest_element (arr, 0, (n - 1), k);

    printf ("%d smallest element in the array is %d\n", k, smallest);

    return 0;

}
