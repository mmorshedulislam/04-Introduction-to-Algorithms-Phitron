class Solution
{
public:
    int n, m;
    bool vis[105][105];
    bool isValid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    bool flag = false;

    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        vis[si][sj] = true;

        if (si == 0 || si == n - 1 || sj == 0 || sj == m - 1)
            flag = false;

        for (int i = 0; i < 4; i++)
        {
            int ci = si + d[i].first;
            int cj = sj + d[i].second;

            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 0)
            {
                dfs(ci, cj, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        memset(vis, false, sizeof(vis));
        n = grid.size();
        m = grid[0].size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 0)
                {
                    flag = true;
                    dfs(i, j, grid);
                    if (flag)
                        ans++;
                }
            }
        }

        return ans;
    }
};