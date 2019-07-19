#include <stdio.h>
#include <stdlib.h>

void
merge (int arr[], int l, int mid, int r)
{

    int i = 0;
    int j = 0;
    int k = 0;

    int n1 = 0;
    int n2 = 0;

    n1 = mid - l + 1;
    n2 = r - mid;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++) {
    
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {
    
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;
    while ((i < n1) && (j < n2)) {
    
        if (L[i] <= R[j]) {
        
            arr[k] = L[i];
            i++;
        } else {
        
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
    
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
    
        arr[k] = R[j];
        j++;
        k++;
    }

}

void
merge_sort (int arr[], int l, int r)
{

    if (l < r) {
    
        int mid = l + ((r - l) / 2);

        merge_sort (arr, l, mid);
        merge_sort (arr, (mid + 1), r);

        merge (arr, l, mid, r);
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

    int arr[]   = {2, 1, 0, 10, 8, -2, 89};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before Sorting: ");
    print_array (arr, n);

    merge_sort (arr, 0, (n - 1));

    printf ("Array after  Sorting: ");
    print_array (arr, n);
    
    return 0;

}
