class Solution
{
public:
    int n, m;
    bool vis[55][55];
    int ans;

    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool isValid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; };
    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;
        ans++;

        for (int i = 0; i < d.size(); i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1)
            {
                dfs(ci, cj, grid);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int mx = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    ans = 0;
                    dfs(i, j, grid);
                    mx = max(mx, ans);
                }
            }
        }
        return mx;
    }
};