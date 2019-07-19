#include <iostream>
#include <vector>

using namespace std;

void
pigeonhole_sort (int arr[], int n)
{

    int index   = 0;
    int range   = 0;
    int min     = 0;
    int max     = 0;
    int i       = 0;

    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++) {
    
        if (arr[i] < min) {
        
            min = arr[i];
        }

        if (arr[i] > max) {
        
            max = arr[i];
        }
    }

    range = max - min + 1;

    vector <int> holes[range];

    for (i = 0; i < n; i++) {
    
        holes[arr[i] - min].push_back (arr[i]);
    }

    for (i = 0; i < range; i++) {
    
        vector <int> :: iterator it;

        for (it = holes[i].begin(); it != holes[i].end(); it++) {
        
            arr[index] = *it;
            index++;
        }
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

    int arr[]   = {3, 4, 21, 0, 2, 6, 2, 6, 9, 3, 19, 23, 3, 19};
    int n       = 0;

    n = sizeof (arr) / sizeof (int);

    cout << "Array before Sorting: ";
    print_array (arr, n);

    pigeonhole_sort (arr, n);

    cout << "Array after  Sorting: ";
    print_array (arr, n);

    return 0;

}
