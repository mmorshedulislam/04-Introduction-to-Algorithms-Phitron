#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int a, b, w;
    Edge(int a, int b, int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

const int N = 1e6 + 5;
int dis[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, t;
    long long int e;
    cin >> n >> e;
    vector<Edge> EdgeList;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a - 1, b - 1, w)); // Convert to zero-based index
    }

    for (int i = 0; i < N; i++)
    {
        dis[i] = INT_MAX;
    }
    cin >> s;
    s--; // Convert to zero-based index
    dis[s] = 0;

    // Bellman-Ford algorithm to calculate shortest distances
    for (int i = 1; i <= n - 1; i++) // Do this n-1 times
    {
        for (Edge ed : EdgeList)
        {
            int a = ed.a, b = ed.b, w = ed.w;

            if (dis[a] < INT_MAX && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    cin >> t;
    while (t--)
    {
        long long int d, dw;
        cin >> d >> dw;
        d--; // Convert to zero-based index

        if (dis[d] == INT_MAX) // No path found
        {
            cout << "Not Possible" << endl;
        }
        else if (dis[d] <= dw) // If distance is within the allowed threshold
        {
            cout << dis[d] << endl; // Print the shortest distance
        }
        else
        {
            cout << "Not Possible" << endl; // If no valid path or distance is too high
        }
    }

    return 0;
}
