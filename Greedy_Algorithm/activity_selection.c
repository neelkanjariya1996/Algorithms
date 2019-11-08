#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct activity_t_ {

    int start;
    int finish;

} activity_t;

void
merge (activity_t *arr, int low, int mid, int high)
{

    activity_t *L;
    activity_t *R;
    int n1  = 0;
    int n2  = 0;
    int i   = 0;
    int j   = 0;
    int k   = 0;

    n1  = mid - low + 1;
    n2  = high - mid;

    L   = malloc (n1 * sizeof (activity_t));
    R   = malloc (n2 * sizeof (activity_t));

    memset (L, 0, n1 * sizeof (activity_t));
    memset (R, 0, n2 * sizeof (activity_t));

    for (i = 0; i < n1; i++) {
    
        L[i]    = arr[low + i];
    }

    for (j  = 0; j < n2; j++) {
    
        R[j]    = arr[mid + 1 + j];
    }

    i   = 0;
    j   = 0;
    k   = low;
    while (i < n1 && j < n2) {
    
        if (L[i].finish < R[j].finish) {
        
            arr[k]  = L[i];
            i++;
        } else {

            arr[k]  = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
    
        arr[k]  = L[i];
        i++;
        k++;
    }

    while (j < n2) {
    
        arr[k]  = R[j];
        j++;
        k++;
    }

}

void
merge_sort (activity_t *arr, int low, int high)
{

    if (low < high) {
    
        int mid = 0;

        mid = low + ((high - low) / 2);
        merge_sort (arr, low, mid);
        merge_sort (arr, (mid + 1), high);

        merge (arr, low, mid, high);
    }

}

void
print_activities (activity_t *arr, int n)
{

    int i   = 0;
    for (i = 0; i < n; i++) {
    
        printf ("{%d, %d}\n", arr[i].start, arr[i].finish);
    }

}

void
print_max_activity (activity_t *arr, int n)
{

    int i   = 0;
    int j   = 0;

    if (!arr) {
    
        return;
    }

    merge_sort (arr, 0, (n - 1));
    printf ("\nSorted activities:\n");
    print_activities (arr, n);

    printf ("\nFollowing activities are selected:\n");
    printf ("{%d, %d}\n", arr[i].start, arr[i].finish);

    for (j = 1; j < n; j++) {
    
        if (arr[j].start > arr[i].finish) {
        
            printf ("{%d, %d}\n", arr[j].start, arr[j].finish);
            i   = j;
        }
    }

}

int
main ()
{

    activity_t arr[]    = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    int n               = 0;

    n   = sizeof (arr) / sizeof (activity_t);

    printf ("n: %d\n", n);
    printf ("\nUnsorted activities:\n");
    print_activities (arr, n);

    print_max_activity (arr, n);

    return 0;

}
