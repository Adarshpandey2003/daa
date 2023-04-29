#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void radixSort(vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // Find the maximum element in the array
    int maxVal = *max_element(arr.begin(), arr.end());

    // Counting sort for each digit from least significant to most significant
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        vector<int> count(10, 0);
        vector<int> output(arr.size());

        // Count the number of occurrences of each digit
        for (int i = 0; i < arr.size(); i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        // Calculate the running sum of the counts
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Place the elements in their sorted order
        for (int i = arr.size() - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        // Copy the sorted array back into the original array
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }
}

int main() {
    vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    radixSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
