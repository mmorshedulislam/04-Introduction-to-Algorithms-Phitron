#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; // Number of test cases
    cin >> T;
    
    while (T--) {
        int n;  // Number of boxes
        cin >> n;
        
        vector<int> a(n);  // Array to store the number of chocolates in each box
        int s = 0;         // Sum of all chocolates
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }

        // If the total sum is odd, it's impossible to divide equally
        if (s % 2 != 0) {
            cout << "NO" << endl;
        } else {
            int sum = s / 2;
            // DP array to store possible sums
            vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

            // Base case: Sum 0 is always possible
            dp[0][0] = true;

            // Fill the DP table
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= sum; j++) {
                    if (a[i - 1] <= j) {
                        dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }

            // If dp[n][sum] is true, it means we can split the chocolates equally
            if (dp[n][sum]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
