#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];

void dfs(int src)
{
    cout << src << endl;
    vis[src] = true;
    
    for (int child : adj[src])
    {
        if (vis[child] == false)
        {
            dfs(child);
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

    memset(vis, false, sizeof(vis));
    dfs(0);

    return 0;
}

// input 
// 6 6
// 0 1
// 0 2
// 0 3
// 1 4
// 3 5
// 3 2


// output
// 0
// 1
// 4
// 2
// 3
// 5