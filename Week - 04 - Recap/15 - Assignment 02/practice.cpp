#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int n, m;
bool vis[N][N];
char mat[N][N];
pair<int, int> parent[N][N];

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && (mat[i][j] == '.' || mat[i][j] == 'D');
}

bool bfs(int startX, int startY)
{
    queue<pair<int, int>> q;
    q.push({startX, startY});
    vis[startX][startY] = true;

    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first, y = curr.second;

        if (mat[x][y] == 'D')
        {
            return true;
        }

        for (auto dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;

            if (isValid(newX, newY))
            {
                vis[newX][newY] = true;
                q.push({newX, newY});
                parent[newX][newY] = {x, y};
            }
        }
    }

    return false;
}

void markPath(int endX, int endY, int startX, int startY)
{
    int x = endX, y = endY;

    while (!(x == startX && y == startY))
    {
        if (mat[x][y] != 'D')
        {
            mat[x][y] = 'X';
        }
        tie(x, y) = parent[x][y];
    }

    mat[startX][startY] = 'R';
}

int main()
{
    cin >> n >> m;

    int startX = -1, startY = -1, endX = -1, endY = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 'R')
            {
                startX = i;
                startY = j;
            }
            if (mat[i][j] == 'D')
            {
                endX = i;
                endY = j;
            }
        }
    }

    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));

    bool foundPath = bfs(startX, startY);

    if (foundPath)
    {
        markPath(endX, endY, startX, startY);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}
