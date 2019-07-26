#include <stdio.h>
#include <stdlib.h>

int
binary_search (int arr[], int l, int h, int item)
{

    if (h <= l) {
    
        if (arr[l] < item) {
        
            return (l + 1);
        } else {
        
            return l;
        }
    }

    int mid = 0;

    mid = l + ((h - l) / 2);

    if (arr[mid] == item) {
    
        return (mid + 1);
    }

    if (arr[mid] < item) {
    
        return binary_search (arr, (mid + 1), h, item);
    } else {
    
        return binary_search (arr, l, (mid - 1), item);
    }

}

void
insertion_sort (int arr[], int n)
{

    int i           = 0;
    int j           = 0;
    int loc         = 0;
    int selected    = 0;

    for (i = 1; i < n; i++) {
    
        selected    = arr[i];
        j           = i - 1;
        loc         = binary_search (arr, 0, j, selected);

        while (j >= loc) {
        
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = selected;
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

    int arr[]   = {8, 0, 1, 3, -2, 0, 7, 4};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before Sorting: ");
    print_array (arr, n);

    insertion_sort (arr, n);

    printf ("Array after  Sorting: ");
    print_array (arr, n);

    return 0;

}
