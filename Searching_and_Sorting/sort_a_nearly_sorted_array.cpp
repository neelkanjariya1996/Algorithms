#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

void
sort_array (int arr[], int n, int k)
{

    priority_queue <int, vector <int>, greater <int>> pq (arr, arr + k + 1);

    int index   = 0;
    int i       = 0;

    for (i = (k + 1); i < n; i++) {
    
        arr[index++] = pq.top();
        //index++;
        pq.pop();
        pq.push(arr[i]);
    }

    while (pq.empty() == false) {
    
        arr[index++] = pq.top();
        //index++;
        pq.pop();
    }

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

    int arr[]   = {10, 9, 8, 7, 4, 70, 60, 50};
    int n       = 0;
    int k       = 0;

    n = sizeof (arr) / sizeof (int);

    cout << "Array before sorting: ";
    print_array (arr, n);

    k = 4;
    sort_array (arr, n, k);

    cout << "Array after  sorting: ";
    print_array (arr, n);
    
    return 0;

}
