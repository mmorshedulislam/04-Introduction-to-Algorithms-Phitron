#include <bits/stdc++.h>
using namespace std;

void findMaxWaterContainer(vector<long long> &H) {
    int left = 0;                    // Start pointer
    int right = H.size() - 1;        // End pointer
    long long maxWater = 0;          // Store maximum water capacity
    int bestLeft = 0, bestRight = 0; // Best indices that store maximum water

    // Two-pointer approach to find the max water container
    while (left < right) {
        long long height = min(H[left], H[right]); // Min height between the two lines
        int width = right - left;                  // Distance between the two lines
        long long currentWater = height * width;   // Current water capacity

        // Update the maximum water and best indices
        if (currentWater > maxWater) {
            maxWater = currentWater;
            bestLeft = left;
            bestRight = right;
        }

        // Move the pointer pointing to the shorter line
        if (H[left] < H[right]) {
            left++;
        } else {
            right--;
        }
    }

    // Output the result: Indices of the lines with max water (0-based index)
    cout << bestLeft << " " << bestRight << endl;
}

int main() {
    int T; // Number of test cases
    cin >> T;

    while (T--) {
        int N; // Number of lines
        cin >> N;

        vector<long long> H(N); // Heights of the lines
        for (int i = 0; i < N; i++) {
            cin >> H[i];
        }

        // Find and print the two lines that can hold the maximum water
        findMaxWaterContainer(H);
    }

    return 0;
}
