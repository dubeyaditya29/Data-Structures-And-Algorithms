#include <bits/stdc++.h>
using namespace std;

/* Reverses arr[0..i] */
void flip(int arr[], int i)
{
	int temp, start = 0;
	while (start < i)
	{
		temp = arr[start];
		arr[start] = arr[i];
		arr[i] = temp;
		start++;
		i--;
	}
}

// Returns index of the
// maximum element in
// arr[0..n-1]
int findMax(int arr[], int n)
{
	int mi, i;
	for (mi = 0, i = 0; i < n; ++i)
		if (arr[i] > arr[mi])
			mi = i;
	return mi;
}

// The main function that
// sorts given array using
// flip operations
void pancakeSort(int *arr, int n)
{
	// Start from the complete
	// array and one by one
	// reduce current size
	// by one
	for (int curr_size = n; curr_size > 1;
		 --curr_size)
	{
		// Find index of the
		// maximum element in
		// arr[0..curr_size-1]
		int mi = findMax(arr, curr_size);

		// Move the maximum
		// element to end of
		// current array if
		// it's not already
		// at the end
		if (mi != curr_size - 1)
		{
			// To move at the end,
			// first move maximum
			// number to beginning
			flip(arr, mi);

			// Now move the maximum
			// number to end by
			// reversing current array
			flip(arr, curr_size - 1);
		}
	}
}

// A utility function to print
// n array of size n
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
}

// Driver program to test above function
int main()
{
	int arr[] = {23, 10, 20, 11, 12, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	pancakeSort(arr, n);

	cout << "Sorted Array " << endl;
	printArray(arr, n);

	return 0;
}
