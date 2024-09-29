#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;
bool vis[N][N];
char mat[N][N];
pair<int, int> parent[N][N]; // To store the parent for path reconstruction

// Direction order: right, left, down, up
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// Check if a cell is valid to visit
bool isValid(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && (mat[i][j] == '.' || mat[i][j] == 'D');
}

// Perform BFS to find the path from Rezia's position to the exit
bool bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    vis[startX][startY] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first, y = curr.second;

        // If we reach the exit 'D', we stop
        if (mat[x][y] == 'D') {
            return true;
        }

        // Explore the neighbors in the specified direction order
        for (auto dir : directions) {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (isValid(newX, newY)) {
                vis[newX][newY] = true;
                q.push({newX, newY});
                parent[newX][newY] = {x, y}; // Keep track of the path
            }
        }
    }

    return false;
}

// Backtrack the path from the exit to Rezia's start and mark it with 'X'
void markPath(int endX, int endY, int startX, int startY) {
    int x = endX, y = endY;

    // Keep marking the path until we reach the start point 'R'
    while (!(x == startX && y == startY)) {
        if (mat[x][y] != 'D') { // Ensure we don't overwrite the exit 'D'
            mat[x][y] = 'X';
        }
        tie(x, y) = parent[x][y]; // Move to the parent
    }

    // Mark the start position
    mat[startX][startY] = 'R';
}

int main() {
    cin >> n >> m;

    int startX = -1, startY = -1, endX = -1, endY = -1;

    // Input maze matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'R') {
                startX = i;
                startY = j;
            }
            if (mat[i][j] == 'D') {
                endX = i;
                endY = j;
            }
        }
    }

    // Initialize visited array and parent tracking
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    // Perform BFS to find if there is a path from 'R' to 'D'
    bool foundPath = bfs(startX, startY);

    // If a path is found, backtrack and mark the path with 'X'
    if (foundPath) {
        markPath(endX, endY, startX, startY);
    }

    // Output the maze, with 'X' marking the path if found
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}
