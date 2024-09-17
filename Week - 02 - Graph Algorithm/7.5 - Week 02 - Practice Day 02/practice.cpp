#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
bool pathVis[N];
bool isCycle;

void dfs(int parent)
{
    vis[parent] = true;
    pathVis[parent] = true;
    for (int child : adj[parent])
    {
        if (pathVis[child])
        {
            isCycle = true;
        }
        if (!vis[child])
        {
            dfs(child);
        }
    }
    // kaj sesh
    pathVis[parent] = false;
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
    }

    memset(vis, false, sizeof(vis));
    memset(pathVis, false, sizeof(pathVis));
    isCycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    if (isCycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "Cycle Not Detected" << endl;

    return 0;
}

// INPUT
// 7 8
// 5 6
// 4 5
// 0 4
// 0 6
// 1 0
// 1 2
// 2 3
// 3 1

// OUTPUT
// Cycle Detected

// INPUT
// 7 7
// 5 6
// 4 5
// 0 4
// 0 6
// 1 0
// 1 2
// 2 3

// OUTPUT
// Cycle Not Detected