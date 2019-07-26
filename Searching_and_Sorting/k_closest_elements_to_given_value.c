#include <stdio.h>
#include <stdlib.h>

int
find_crossover (int arr[], int l, int h, int x)
{

    if (arr[l] > x) {
    
        return l;
    }

    if (arr[h] < x) {
    
        return h;
    }

    int mid = 0;

    mid = (l + h) / 2;

    if (arr[mid] <= x && arr[mid + 1] > x) {
    
        return mid;
    }

    if (arr[mid] > x) {
    
        return find_crossover (arr, l, (mid - 1), x);
    } else {
    
        return find_crossover (arr, (mid + 1), h, x);
    }

}

void
k_elements (int arr[], int n, int x, int k)
{

    int l       = 0;
    int r       = 0;
    int count   = 0;

    l = find_crossover (arr, 0, (n - 1), x);
    r = l + 1;

    if (arr[l] == x) {
    
        l--;
    }

    while ((l >= 0) && (r < n) && (count < k)) {
    
        if ((x - arr[l]) <= (arr[r] - x)) {
        
            printf ("%d ", arr[l]);
            l--;
        } else {
        
            printf ("%d ", arr[r]);
            r++;
        }

        count++;
    }

    while ((l >= 0) && (count < k)) {
    
        printf ("%d ", arr[l]);
        l--;
        count++;
    }

    while ((r < n) && (count < k)) {
    
        printf ("%d ", arr[r]);
        r++;
        count++;
    }

    printf ("\n");

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

    int arr[]   = {9, 45, 78, 90, 100, 105, 120 ,456, 763};
    int n       = 0;
    int x       = 0;
    int k       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    x = 120;
    k = 4;

    k_elements (arr, n, x, k);

    return 0;

}
