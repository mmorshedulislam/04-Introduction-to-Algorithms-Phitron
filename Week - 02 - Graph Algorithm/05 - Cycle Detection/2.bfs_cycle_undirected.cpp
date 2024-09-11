#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
int parentArr[N];
vector<int> adj[N];
bool isCycle;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj[par])
        {
            if (vis[child] && parentArr[par] != child)
            {
                isCycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                parentArr[child] = par;
                vis[child] = true;
            }
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
            bfs(i);
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
