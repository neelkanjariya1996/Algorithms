#include <stdio.h>
#include <stdlib.h>

int
linear_search (int arr[], int n, int x)
{

	int i = 0;

	for (i = 0; i < n; i++) {
	
		if (arr[i] == x) {
		
			return i;
		}
	}

	return -1;

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

	int arr[] 	= {10, 6, 2, 9, 11, 34, 62};
	int n		= 0;
	int index	= 0;
	int x		= 0;

	n = sizeof (arr) / sizeof (int);

	printf ("Array: ");
	print_array (arr, n);

	x = 110;
	index = linear_search (arr, n, x);

	if (index != -1) {
	
		printf ("The index of %d in the array is %d\n", x, index);
	} else {
	
		printf ("%d not present in the array\n",x);
	}

	return 0;

}
