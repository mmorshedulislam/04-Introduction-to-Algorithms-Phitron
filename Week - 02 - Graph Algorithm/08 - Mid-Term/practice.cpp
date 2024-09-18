#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
long long int dis[N];

class Edge
{
public:
    int a, b;
    long long int w;
    Edge(int a, int b, long long int w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int main()
{
    int n, s, t;
    long long int e;
    cin >> n >> e;
    vector<Edge> EdgeList;

    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        EdgeList.push_back(Edge(a - 1, b - 1, w));
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    cin >> s;
    dis[s - 1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge ed : EdgeList)
        {
            int a, b;
            long long int w;
            a = ed.a, b = ed.b, w = ed.w;

            if (dis[a] < LLONG_MAX && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    cin >> t;
    while (t--)
    {
        int d;
        long long int dw;
        cin >> d >> dw;
        if (dis[d - 1] == LLONG_MAX)
            cout << "NO" << endl;
        else if (dis[d - 1] <= dw)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
