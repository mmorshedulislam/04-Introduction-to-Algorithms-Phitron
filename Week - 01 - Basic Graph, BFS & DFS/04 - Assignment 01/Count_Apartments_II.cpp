#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int n, m;
char a[N][N];
bool vis[N][N];

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != '#' && !vis[i][j]);
}

int bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    int roomCount = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int x = par.first, y = par.second;

        roomCount++;

        for (int i = 0; i < 4; i++)
        {
            int ci = x + d[i].first;
            int cj = y + d[i].second;

            if (isValid(ci, cj))
            {
                vis[ci][cj] = true;
                q.push({ci, cj});
            }
        }
    }

    return roomCount;
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
        }
    }

    vector<int> apartmentSizes;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != '#' && !vis[i][j])
            {
                int size = bfs(i, j);
                apartmentSizes.push_back(size);
            }
        }
    }

    sort(apartmentSizes.begin(), apartmentSizes.end());

    for (int size : apartmentSizes)
    {
        cout << size << " ";
    }
    cout << endl;

    return 0;
}