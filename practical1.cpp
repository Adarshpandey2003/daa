#include <iostream>
using namespace std;

int noOfComparisions=0;

// Merge two sorted subarrays into a single sorted array
void merge(int arr[], int left, int middle, int right) {
    // Find the sizes of the two subarrays
    int sizeLeft = middle - left + 1;
    int sizeRight = right - middle;

    // Create temporary arrays to hold the subarrays
    int tempLeft[sizeLeft], tempRight[sizeRight];

    // Copy the subarrays into the temporary arrays
    for (int i = 0; i < sizeLeft; i++) {
        tempLeft[i] = arr[left + i];
    }
    for (int i = 0; i < sizeRight; i++) {
        tempRight[i] = arr[middle + 1 + i];
    }

    // Merge the two subarrays into a single sorted array
    int i = 0; // index of the first subarray
    int j = 0; // index of the second subarray
    int k = left; // index of the merged array
    while (i < sizeLeft && j < sizeRight) {
		noOfComparisions++;
        if (tempLeft[i] <= tempRight[j]) {
            arr[k] = tempLeft[i];
            i++;
        } else {
            arr[k] = tempRight[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from the left subarray
    while (i < sizeLeft) {
        arr[k] = tempLeft[i];
        i++;
        k++;
    }

    // Copy any remaining elements from the right subarray
    while (j < sizeRight) {
        arr[k] = tempRight[j];
        j++;
        k++;
    }
}

// Merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find the middle point
        int middle = left + (right - left) / 2;

        // Sort the left subarray
        mergeSort(arr, left, middle);

        // Sort the right subarray
        mergeSort(arr, middle + 1, right);

        // Merge the two sorted subarrays
        merge(arr, left, middle, right);
    }
}

// Driver program to test the mergeSort function
int main() {
    int arr[] = {10, 7, 8, 9, 1011, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
	cout<<"No. of comparisons made :"<<noOfComparisions;

    return 0;
}
