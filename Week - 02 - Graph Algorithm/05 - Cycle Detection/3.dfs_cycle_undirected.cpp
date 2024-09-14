#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
int parentArr[N];
bool isCycle;

void dfs(int parent)
{
    vis[parent] = true;
    for (int child : adj[parent])
    {
        if (vis[child] && child != parentArr[parent])
        {
            isCycle = true;
        }

        if (!vis[child])
        {
            parentArr[child] = parent;
            dfs(child);
        }
    }
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
        adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parentArr, -1, sizeof(parentArr));
    isCycle = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    if (isCycle)
        cout << "Cycle Found" << endl;
    else
        cout << "Cycle NOT Found" << endl;

    return 0;
}

// INPUT
// 2 1
// 0 1

// OUTPUT
// Cycle NOT Found
// ------------------------

// INPUT
// 7 6
// 0 1
// 1 2
// 3 4
// 4 5
// 5 6
// 6 3

// OUTPUT
// Cycle Found
