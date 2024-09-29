#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;
bool vis[N][N];
char mat[N][N];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && mat[i][j] == '.';
}

int bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    int area = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        area++;

        for (auto d : directions)
        {
            int ci = par.first + d.first;
            int cj = par.second + d.second;

            if (isValid(ci, cj))
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }

    return area;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int min_area = INT_MAX;
    bool found_component = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.' && !vis[i][j])
            {
                int area = bfs(i, j);
                min_area = min(min_area, area);
                found_component = true;
            }
        }
    }

    if (found_component)
    {
        cout << min_area << endl;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
