#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void bucketSort(vector<float>& arr) {
    if (arr.empty()) {
        return;
    }

    // Find the minimum and maximum values in the array
    float minVal = *min_element(arr.begin(), arr.end());
    float maxVal = *max_element(arr.begin(), arr.end());

    // Calculate the bucket size and the number of buckets
    int bucketSize = ceil((maxVal - minVal) / arr.size());
    int numBuckets = ceil((maxVal - minVal) / bucketSize);

    // Initialize the buckets
    vector<vector<float>> buckets(numBuckets);

    // Distribute the elements into the buckets
    for (int i = 0; i < arr.size(); i++) {
        int bucketIndex = floor((arr[i] - minVal) / bucketSize);
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort each bucket using any sorting algorithm
    for (int i = 0; i < numBuckets; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<float> arr = { 0.42, 0.32, 0.23, 0.52, 0.61, 0.67, 0.88, 0.99, 0.45, 0.73 };
    bucketSort(arr);
    cout << "Sorted array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
