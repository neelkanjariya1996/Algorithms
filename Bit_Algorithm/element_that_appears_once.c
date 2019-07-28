#include <stdio.h>
#include <stdlib.h>

int
get_single_eleemnt (int arr[], int n)
{

    int ones            = 0;
    int twos            = 0;
    int common_bit_mask = 0;
    int i               = 0;

    for (i = 0; i < n; i++) {
    
        twos    = twos | (ones & arr[i]);
        ones    = ones ^ arr[i];

        common_bit_mask = ~ (ones & twos);

        ones = ones & common_bit_mask;
        twos = twos & common_bit_mask;
    }

    return ones;

}

void
print_array (int arr[], int n)
{

    int i   = 0;
    for (i  = 0; i < n; i++) {
    
        printf ("%d ", arr[i]);
    }
    printf ("\n");

}

int
main ()
{

    int arr[]   = {2, 2, 2, 9, 10, 9, 10, 9, 10};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array: ");
    print_array (arr, n);

    printf ("The element that appears only once in the array is : %d\n", get_single_eleemnt (arr, n));

    return 0;

}
