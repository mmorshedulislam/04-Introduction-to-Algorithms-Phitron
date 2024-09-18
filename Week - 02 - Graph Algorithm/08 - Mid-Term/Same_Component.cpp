#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
bool vis[N][N];
char mat[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && mat[i][j] != '-';
}

bool isSameComp(int si, int sj, int di, int dj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a, b;
        a = par.first, b = par.second;

        if (a == di && b == dj)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;

            if (isValid(ci, cj))
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }
    return false;
};

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

    int si, sj;
    cin >> si >> sj;

    int di, dj;
    cin >> di >> dj;

    if (isSameComp(si, sj, di, dj))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}