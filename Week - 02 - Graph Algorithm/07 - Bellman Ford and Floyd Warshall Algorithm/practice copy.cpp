#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < j; j++)
        {
            adj[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < j; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    return 0;
}