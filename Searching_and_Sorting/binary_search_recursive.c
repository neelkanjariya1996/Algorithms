#include <stdio.h>
#include <stdlib.h>

int
binary_search (int arr[], int l, int h, int x) 
{

	if (h >= l) {
	
		int mid = (l + h) / 2;

        if (arr[mid] == x) {
        
            return mid;
        }

        if (arr[mid] < x) {
        
            return binary_search (arr, (mid + 1), h, x);
        } else {
        
            return binary_search (arr, l, (mid - 1), x);
        }
    }

    return -1;

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

    int arr[]   = {1, 2, 4, 6, 10, 12, 20};
    int n       = 0;
    int x       = 0;
    int index   = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    x = 0;
    index = binary_search (arr, 0, (n - 1), x);

    if (index != -1) {

        printf ("%d is at position %d in the array\n", x, index);
    } else {
    
        printf ("%d in not present in the array\n", x);
    }

    return 0;

}
