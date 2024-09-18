#include <bits/stdc++.h>
using namespace std;

// weight wise shortest distance ber kore without negative value or cycle

int const N = 100;
vector<pair<int, int>> edgeList[N];
int dis[N];

// possibility of edge update in worse case (n-1)

void dijkstra(int src) // O(V * E)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;

    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        q.pop();
        int node = parent.first;
        int cost = parent.second;

        for (pair<int, int> child : edgeList[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                // path relax
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
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
        int a, b, c;
        cin >> a >> b >> c;
        edgeList[a].push_back({b, c});
        edgeList[b].push_back({a, c});
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++)
    {
        cout << "N " << i << " -> " << "W " << dis[i] << endl;
    }

    return 0;
}
// INPUT
// 5 8
// 0 1 10
// 0 2 7
// 0 3 4
// 1 4 3
// 2 4 5
// 2 1 1
// 3 4 5
// 3 2 1

// OUTPUT
// N 0 -> W 0
// N 1 -> W 6
// N 2 -> W 5
// N 3 -> W 4
// N 4 -> W 9