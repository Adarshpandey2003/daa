#include <iostream>
#include <vector>
using namespace std;

// Struct to represent an item
struct Item {
    int weight;
    int value;

    Item(int weight, int value) {
        this->weight = weight;
        this->value = value;
    }
};

// Dynamic programming algorithm to solve the 0-1 knapsack problem
int knapsack(int W, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));

    // Fill in the dynamic programming table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Return the maximum value that can be obtained
    return dp[n][W];
}

int main() {
    //first is weight and then value
    vector<Item> items = {
        {10, 60},
        {20, 100},
        {30, 120}
    };
    int W = 50;

    int maxValue = knapsack(W, items);
    cout << "Maximum Value: " << maxValue << endl;

    return 0;
}
