#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int
jump_search (int arr[], int n, int x)
{

    int step = 0;
    int prev = 0;

    step = sqrt (n);

    while (arr[min (step, n) - 1] < x) {
    
        prev = step;
        step = step + sqrt (n);
        if (prev >= n) {
        
            return -1;
        }
    }

    while (arr[prev] < x) {
    
        prev++;
        if (prev >= min (step, n)) {
        
            return -1;
        }
    }

    if (arr[prev] == x) {
    
        return prev;
    }

    return -1;

}

void
print_array (int arr[], int n)
{

    int i = 0;
    for (i = 0; i < n; i++) {
    
        cout << arr[i] << " ";
    }
    cout << endl;

}

int
main ()
{

    int arr[]   = {0, 1, 3, 4, 5, 6, 8, 9, 10, 12, 14, 18, 20, 45, 65, 78, 98};
    int n       = 0;
    int x       = 0;
    int index   = 0;

    n = sizeof (arr) / sizeof (int);

    cout << "Array: ";
    print_array (arr, n);

    x = 1;
    index = jump_search (arr, n, x);

    if (index != -1) {
    
        cout << x << " is at position " << index << " in the array" << endl;
    } else {
    
        cout << x << " is not present in the array" <<endl;
    }

    return 0;

}
