#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RANGE   10

int
get_max (int arr[], int n)
{

    int i = 0;
    int m = 0;

    m = arr[0];
    for (i = 1; i < n; i++) {
    
        if (arr[i] > m) {
        
            m = arr[i];
        }
    }

    return m;

}

void
count_sort (int arr[], int n, int exp)
{

    int count[RANGE];
    int output[n];
    int i = 0;

    memset (count, 0, sizeof (count));

    for (i = 0; i < n; i++) {
    
        count[((arr[i]/exp) % 10)]++;
    }

    for (i = 1; i < RANGE; i++) {
    
        count[i] = count[i] +  count[i - 1];
    }

    for (i = (n - 1); i >= 0; i--) {
    
        output[count[((arr[i]/exp) % 10)] - 1] = arr[i];
        count[((arr[i]/exp) % 10)]--;
    }

    for (i = 0; i < n; i++) {
    
        arr[i] = output[i];
    }

}

void
radix_sort (int arr[], int n)
{

    int m   = 0;
    int exp = 0;

    m = get_max (arr, n);

    for (exp = 1; m/exp > 0; exp = exp * 10) {
    
        count_sort (arr, n, exp);
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

    int arr[]   = {90, 2, 89, 987, 45, 27, 5673};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before sorting: ");
    print_array (arr, n);

    radix_sort (arr, n);

    printf ("Array after  sorting: ");
    print_array (arr, n);

    return 0;

}
