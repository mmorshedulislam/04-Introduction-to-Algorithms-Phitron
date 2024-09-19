class Solution {
public:
    int n, m;
    bool vis[305][305];
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool isValid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
    void dfs(int si, int sj, vector<vector<char>>& grid) {
        vis[si][sj] = true;
        for (int i = 0; i < d.size(); i++) {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '1') {
                dfs(ci, cj, grid);
            }
        }
    };

    int numIslands(vector<vector<char>>& grid) {
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};