#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> mat[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }

    int q;
    cin >> q;
    queue<int> qv;
    while (q--)
    {
        int x;
        cin >> x;
        qv.push(x);
    }

    while (!qv.empty())
    {
        int f = qv.front();
        qv.pop();
        if (mat[f].size() == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            sort(mat[f].begin(), mat[f].end());
            reverse(mat[f].begin(), mat[f].end());

            for (int x : mat[f])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}