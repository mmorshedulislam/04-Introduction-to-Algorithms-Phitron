#include <bits/stdc++.h>
using namespace std;

// O(n * m)

int n, m;
char a[20][20];
bool vis[20][20];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}

void dfs_2d(int si, int sj)
{
    cout << si << " " << sj << endl;
    vis[si][sj] = true;

    for (int i = 0; i < d.size(); i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if (isValid(ci, cj) == true && vis[ci][cj] == false)
        {
            dfs_2d(ci, cj);
        }
    }
};

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int si, sj;
    cin >> si >> sj;

    memset(vis, false, sizeof(vis));

    dfs_2d(si, sj);

    return 0;
}

// INPUT
// 3 4
// ....
// ....
// ....
// 1 1

// OUTPUT
// 1 1
// 1 2
// 1 3
// 0 3
// 0 2
// 0 1
// 0 0
// 1 0
// 2 0
// 2 1
// 2 2
// 2 3
