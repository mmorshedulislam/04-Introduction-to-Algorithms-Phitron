#include <bits/stdc++.h>
using namespace std;

bool examMarks(int N, int M, vector<int>& marks) {
    int target = 1000 - M;
    
    // If Zarif already has 1000 marks
    if (target == 0) return true;
    
    // If it's impossible to reach exactly 1000 marks
    if (target < 0) return false;

    // DP array to store whether we can form sum i
    vector<bool> dp(target + 1, false);
    dp[0] = true; // Base case: We can always form sum 0 with no marks

    // Process each mark and update the dp array
    for (int mark : marks) {
        for (int j = target; j >= mark; j--) {
            if (dp[j - mark]) {
                dp[j] = true;
            }
        }
    }
    
    // If we can form the sum `target`, return true
    return dp[target];
}

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int N, M; // N = number of marks, M = current marks Zarif has
        cin >> N >> M;
        
        vector<int> marks(N); // List of available marks
        for (int i = 0; i < N; i++) {
            cin >> marks[i];
        }

        // Check if Zarif can obtain exactly 1000 marks
        if (examMarks(N, M, marks)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
