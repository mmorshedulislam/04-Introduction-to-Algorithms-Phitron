#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    // int a[n];
    vector<int> mat[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a); // if undirected graph
    }

    for (int x : mat[0])
    {
        cout << x << " "; // 1 4 3
    }

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