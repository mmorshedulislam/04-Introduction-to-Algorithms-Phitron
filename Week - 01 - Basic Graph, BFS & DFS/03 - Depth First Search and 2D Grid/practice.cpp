#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[20][20];
bool vis[20][20];
int des[20][20];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    else
        return true;
}

void bfs_2d(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    des[si][sj] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first, b = par.second;
        cout << a << " " << b << endl;

        for (int i = 0; i < d.size(); i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if (isValid(ci, cj) && !vis[ci][cj])
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                des[ci][cj] = des[a][b] + 1;
            }
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
    memset(vis, false, sizeof(vis));
    memset(des, -1, sizeof(des));

    int si, sj;
    cin >> si >> sj;
    bfs_2d(si, sj);

    return 0;
}