#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
bool pathVis[N];
int parArr[N];
bool isCycle;

// DFS DIRECTED
void dfs_dir(int src)
{
    vis[src] = true;
    pathVis[src] = true;
    for (int child : adj[src])
    {

        if (pathVis[child])
        {
            isCycle = true;
        }

        if (!vis[child])
        {
            dfs_dir(child);
        }
    }

    pathVis[src] = false;
};

// DFS UNDIRECTED
void dfs(int src)
{
    vis[src] = true;
    for (int child : adj[src])
    {
        if (vis[child] && child != parArr[src])
        {
            isCycle = true;
        }
        if (!vis[child])
        {
            parArr[child] = src;
            dfs(child);
        }
    }
}

// BFS UNDIRECTED
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj[par])
        {
            if (vis[child] && child != parArr[child])
            {
                isCycle = true;
            };

            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parArr[child] = true;
            };
        };
    };
};

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        // adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs_dir(i);
        }
    }

    if (isCycle)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}