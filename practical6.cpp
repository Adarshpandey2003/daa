#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    // Choose a pivot element at random
    int pivotIndex = left + rand() % (right - left + 1);
    int pivotValue = arr[pivotIndex];

    // Move the pivot element to the end of the array
    swap(arr[pivotIndex], arr[right]);

    // Partition the array around the pivot element
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i] < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]); // Move the pivot element back to its final position
    return storeIndex;
}

int randomizedSelect(vector<int>& arr, int left, int right, int k, int& comparisons) {
    // Base case: the subarray has only one element
    if (left == right) {
        return arr[left];
    }

    // Partition the subarray around a random pivot element
    int pivotIndex = partition(arr, left, right);

    // Determine the rank of the pivot element in the sorted array
    int pivotRank = pivotIndex - left + 1;

    // Recurse on the left or right subarray, depending on the pivot rank
    if (k == pivotRank) {
        return arr[pivotIndex];
    } else if (k < pivotRank) {
        return randomizedSelect(arr, left, pivotIndex - 1, k, comparisons);
    } else {
        comparisons++;
        return randomizedSelect(arr, pivotIndex + 1, right, k - pivotRank, comparisons);
    }
}

int main() {
    srand(time(0)); // Seed the random number generator with the current time

    vector<int> arr = { 9, 5, 7, 2, 8, 4, 0, 3, 1, 6 };
    int k = 5;
    int comparisons = 0;
    int kthSmallest = randomizedSelect(arr, 0, arr.size() - 1, k, comparisons);

    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The " << k << "th smallest element is " << kthSmallest << endl;
    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
