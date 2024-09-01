#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n][n];
    memset(mat, 0, sizeof(mat)); // set init all matrix = 0

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
        // 0 0 0 0 0 0
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1; // if undirected graph
    }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
        // 0 1 0 1 1 0
        // 1 0 0 0 0 1
        // 0 0 0 0 1 0
        // 1 0 0 0 1 0
        // 1 0 1 1 0 0
        // 0 1 0 0 0 0
    }

    cout << endl;
    if (mat[1][5])
        cout << "YES" << endl; // true
    else
        cout << "NO" << endl;

    return 0;
}

// input
// 6 6
// 0 1
// 1 5
// 0 4
// 0 3
// 3 4
// 2 4