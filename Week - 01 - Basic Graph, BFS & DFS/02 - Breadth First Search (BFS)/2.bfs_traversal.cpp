#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool vis[1005];

int cnt = 0;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << endl;
        for (int child : adj[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int src;
    cin >> src;
    memset(vis, false, sizeof(vis));
    bfs(src);

    cout << endl
         << cnt;

    return 0;
}

// INPUT
// 7 8
// 0 1
// 1 2
// 1 4
// 1 3
// 2 0
// 3 4
// 1 5
// 3 6
// 0

// OUTPUT
// 0
// 1
// 2
// 4
// 3
// 5
// 6
