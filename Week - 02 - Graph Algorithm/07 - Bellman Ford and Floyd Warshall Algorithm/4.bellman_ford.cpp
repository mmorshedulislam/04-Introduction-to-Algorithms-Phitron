#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1005;
int dis[N];

int main()
{
    vector<Edge> EdgeList;
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    // set max value
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    // set first value 0
    dis[0] = 0;

    // O(V * E)
    for (int i = 1; i <= n - 1; i++) // O(V)
    {
        for (Edge ed : EdgeList) // O(E)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}

// INPUT
// 4 4
// 0 2 5
// 0 3 12
// 2 1 2
// 1 3 3

// OUTPUT
// 0 -> 0
// 1 -> 7
// 2 -> 5
// 3 -> 10

// INPUT
// 4 4
// 1 3 -3
// 0 3 5
// 2 1 1
// 0 2 -2

// OUTPUT
// 0 -> 0
// 1 -> -1
// 2 -> -2
// 3 -> -4