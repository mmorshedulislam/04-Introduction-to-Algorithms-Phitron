#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
char a[N][N];
bool vis[N][N];
int startI, startJ, endI, endJ;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#' && !vis[i][j]);
}

bool can_go(int startI, int startJ, int endI, int endJ)
{
    queue<pair<int, int>> q;
    q.push({startI, startJ});
    vis[startI][startJ] = true;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int a = par.first, b = par.second;

        if (a == endI && b == endJ)
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
}

int main()
{
    cin >> n >> m;
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                startI = i;
                startJ = j;
            }
            if (a[i][j] == 'B')
            {
                endI = i;
                endJ = j;
            }
        }
    }

    if (can_go(startI, startJ, endI, endJ))
        cout << "YES" << endl;

    else
        cout << "NO" << endl;

    return 0;
}