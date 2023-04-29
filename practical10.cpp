#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Struct to represent a weighted interval
struct Interval {
    int start;
    int end;
    int weight;

    Interval(int start, int end, int weight) {
        this->start = start;
        this->end = end;
        this->weight = weight;
    }
};

// Comparison function for sorting intervals in ascending order of end time
bool compareIntervals(Interval a, Interval b) {
    return a.end < b.end;
}

// Binary search to find the latest non-overlapping interval with interval i
int findLatestNonOverlappingInterval(vector<Interval>& intervals, int i) {
    int left = 0, right = i - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (intervals[mid].end <= intervals[i].start) {
            if (intervals[mid + 1].end <= intervals[i].start) {
                left = mid + 1;
            } else {
                return mid;
            }
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// Dynamic programming algorithm to find the maximum weight subset of non-overlapping intervals
int weightedIntervalScheduling(vector<Interval>& intervals) {
    int n = intervals.size();
    vector<int> dp(n);

    // Sort intervals in ascending order of end time
    sort(intervals.begin(), intervals.end(), compareIntervals);

    // Base case
    dp[0] = intervals[0].weight;

    // Fill in the dynamic programming table
    for (int i = 1; i < n; i++) {
        int latestNonOverlappingInterval = findLatestNonOverlappingInterval(intervals, i);
        int include = intervals[i].weight;
        int exclude = dp[i - 1];

        if (latestNonOverlappingInterval != -1) {
            include += dp[latestNonOverlappingInterval];
        }

        dp[i] = max(include, exclude);
    }

    // Return the maximum weight subset of non-overlapping intervals
    return dp[n - 1];
}

int main() {
    vector<Interval> intervals = {
        {1, 3, 5},
        {2, 5, 6},
        {4, 6, 5},
        {6, 7, 4},
        {5, 8, 11},
        {7, 9, 2}
    };

    int maxWeight = weightedIntervalScheduling(intervals);
    cout << "Maximum Weight: " << maxWeight << endl;

    return 0;
}
