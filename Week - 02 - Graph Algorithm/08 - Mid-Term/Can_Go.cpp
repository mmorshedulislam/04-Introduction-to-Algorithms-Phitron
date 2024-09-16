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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e, s, t;
    cin >> n >> e;
    int dis[n];
    vector<Edge> EdgeList;

    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a - 1, b - 1, w));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    cin >> s;
    dis[s - 1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int a, b, w;
            a = ed.a, b = ed.b, w = ed.w;

            if (dis[a] < INT_MAX && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    cin >> t;
    while (t--)
    {
        int d, dw;
        cin >> d >> dw;
        if (dis[d - 1] <= dw)
            cout << "YES" << endl;
        else if (dis[d - 1] == INT_MAX)
            cout << "NO" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
