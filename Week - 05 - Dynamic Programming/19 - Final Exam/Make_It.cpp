#include <iostream>
#include <vector>
using namespace std;

// Function to check if we can reach N from 1 using dynamic programming
bool makeIt(int N) {
    // Set a limit for how far we need to compute, based on the max value of N
    vector<bool> dp(N + 1, false);

    // Start from 1
    dp[1] = true;

    // Iterate over all possible values that can be reached
    for (int i = 1; i <= N; i++) {
        if (dp[i]) {
            if (i + 3 <= N) {
                dp[i + 3] = true;
            }
            if (i * 2 <= N) {
                dp[i * 2] = true;
            }
        }
    }

    // Check if we can reach N
    return dp[N];
}

int main() {
    int T;
    cin >> T;  // Number of test cases

    // Process each test case
    while (T--) {
        int N;
        cin >> N;  // The target number
        
        // Output "YES" if reachable, otherwise "NO"
        if (makeIt(N)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
