#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int dis[N];

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

int main()
{
    int n, t;
    long long int e;
    cin >> n >> e;
    vector<Edge> EdgeList;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--, b--;
        EdgeList.push_back(Edge(a, b, w));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    int s;
    cin >> s;
    s--;
    dis[s] = 0;

    for (int i = 1; i <= n - 1; i++)
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
    bool isCycle = false;
    for (Edge ed : EdgeList)
    {
        int a = ed.a, b = ed.b, w = ed.w;

        if (dis[a] < INT_MAX && dis[a] + w < dis[b])
        {
            isCycle = true;
        }
    }

    if (isCycle)
        cout << "Negative Cycle Detected" << endl;
    else
    {
        cin >> t;
        while (t--)
        {
            int d;
            cin >> d;
            d--;
            if (dis[d] == INT_MAX)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[d] << endl;
            }
        }
    }

    return 0;
}
