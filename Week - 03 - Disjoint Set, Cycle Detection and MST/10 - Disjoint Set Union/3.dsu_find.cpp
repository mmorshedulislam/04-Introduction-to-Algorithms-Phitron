#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];

void dsu_initialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
    }
    par[1] = 3;
    par[2] = 1;
}

int dsu_find(int node) // find leader
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = dsu_find(par[node]);
    return leader;
}

int main()
{
    dsu_initialize(4);
    cout << dsu_find(0) << endl;
    cout << dsu_find(1) << endl;
    cout << dsu_find(2) << endl;
    cout << dsu_find(3) << endl;

    return 0;
}

// OUTPUT
// 0
// 3
// 3
// 3