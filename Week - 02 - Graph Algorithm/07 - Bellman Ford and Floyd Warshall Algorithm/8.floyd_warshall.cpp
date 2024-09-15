#include <bits/stdc++.h>
#define ll long long int;
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    long long int adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = INT_MAX;
            if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a][b] = c;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (adj[i][j] == INT_MAX)
    //         {
    //             cout << "INF" << " ";
    //         }
    //         else
    //             cout << adj[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    bool isCycle = false;

    // CYCLE DETECTED
    for (int i = 0; i < n; i++)
    {
        if (adj[i][i] < 0)
        {
            isCycle = true;
            break;
        }
    }

    if (isCycle)
    {
        cout << "Cycle Detected" << endl;
    }
    else
    {
        // COSTS
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] == INT_MAX)
                {
                    cout << "INF" << " ";
                }
                else
                    cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

// INPUT
// 4 6
// 3 2 8
// 2 1 5
// 1 0 2
// 3 0 20
// 0 1 3
// 1 2 2

// OUTPUT
// 0 3 5 INF
// 2 0 2 INF
// 7 5 0 INF
// 15 13 8 0

// INPUT
// 3 3
// 0 1 -5
// 1 2 3
// 2 0 -1

// OUTPUT
// Cycle Detected