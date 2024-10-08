#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to solve the knapsack problem for a single test case
int knapsack(int N, int W, const vector<int>& weights, const vector<int>& values) {
    // Create a DP table initialized to 0
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            // If the current item can fit in the knapsack
            if (weights[i - 1] <= w) {
                // Take the maximum of including or not including the current item
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                // If it cannot fit, just carry forward the value without this item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The result will be in dp[N][W] - the maximum value for N items and weight W
    return dp[N][W];
}

int main() {
    int T;
    cin >> T;  // Number of test cases

    // Process each test case
    while (T--) {
        int N, W;
        cin >> N >> W;  // Number of items and weight capacity of the backpack

        vector<int> weights(N), values(N);

        // Input weights
        for (int i = 0; i < N; i++) {
            cin >> weights[i];
        }

        // Input values
        for (int i = 0; i < N; i++) {
            cin >> values[i];
        }

        // Call the knapsack function and print the result
        cout << knapsack(N, W, weights, values) << endl;
    }

    return 0;
}
