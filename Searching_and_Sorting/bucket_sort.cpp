#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void
bucket_sort (float arr[], int n)
{

    vector <float> b[n];

    int i       = 0;
    int j       = 0;
    int bi      = 0;
    int index   = 0;

    for (i = 0; i < n; i++) {
    
        bi = n * arr[i];
        b[bi].push_back (arr[i]);
    }

    for (i = 0; i < n; i++) {
    
        sort (b[i].begin (), b[i].end ());
    }

    for (i = 0; i < n; i++) {
    
        for (j = 0; j < b[i].size (); j++) {
        
            arr[index] = b[i][j];
            index++;
        }
    }

}

void
print_array (float arr[], int n)
{

    int i = 0; 

    for (i = 0; i < n; i++) {
    
        printf ("%f ", arr[i]);
    }
    printf ("\n");

}

int
main ()
{

    float arr[] = {0.6, 0.22, 0.5678, 0.28, 0.1, 0, 0.982, 0.78};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    printf ("Array before sorting: ");
    print_array (arr, n);

    bucket_sort (arr, n);

    printf ("Array after  sorting: ");
    print_array (arr, n);
    
    return 0;

}
