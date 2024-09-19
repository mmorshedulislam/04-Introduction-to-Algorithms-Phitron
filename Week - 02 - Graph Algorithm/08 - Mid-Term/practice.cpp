#include <bits/stdc++.h>
using namespace std;

// Knight's possible moves
int knightMoves[8][2] = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

// BFS to find the minimum steps for knight to reach queen
int minStepsToQueen(int n, int m, int ki, int kj, int qi, int qj) {
    // If the knight is already at the queen's position
    if (ki == qi && kj == qj) return 0;

    // Queue for BFS: stores {x, y, steps}
    queue<pair<pair<int, int>, int>> q;
    q.push({{ki, kj}, 0});

    // Visited array to keep track of visited cells
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[ki][kj] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        // Try all 8 possible knight moves
        for (int i = 0; i < 8; i++) {
            int nx = x + knightMoves[i][0];
            int ny = y + knightMoves[i][1];

            // Check if the new position is within the board
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
                // If the new position is the queen's position
                if (nx == qi && ny == qj) {
                    return steps + 1;
                }
                // Mark the new position as visited and add to the queue
                visited[nx][ny] = true;
                q.push({{nx, ny}, steps + 1});
            }
        }
    }

    // If the queen is not reachable
    return -1;
}

int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        int n, m, ki, kj, qi, qj;
        cin >> n >> m >> ki >> kj >> qi >> qj;

        // Output the result for the current test case
        cout << minStepsToQueen(n, m, ki, kj, qi, qj) << endl;
    }

    return 0;
}
