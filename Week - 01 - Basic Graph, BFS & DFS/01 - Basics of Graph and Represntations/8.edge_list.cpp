#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> v;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (pair<int, int> p : v)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}

// INPUT
// 6 6
// 0 1
// 1 5
// 0 4
// 0 3
// 3 4
// 2 4

// OUTPUT
// 0 1
// 1 5
// 0 4
// 0 3
// 3 4
// 2 4