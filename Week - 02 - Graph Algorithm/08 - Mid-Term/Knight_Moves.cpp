#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

int minStepsToQueen(int n, int m, int ki, int kj, int qi, int qj)
{
    if (ki == qi && kj == qj)
    {
        return 0;
    }
    bool vis[n][m];
    memset(vis, false, sizeof(vis));

    queue<pair<pair<int, int>, int>> q;
    q.push({{ki, kj}, 0});
    vis[ki][kj] = true;

    while (!q.empty())
    {
        pair<pair<int, int>, int> par = q.front();
        q.pop();
        int x, y, steps;
        x = par.first.first;
        y = par.first.second;
        steps = par.second;

        for (int i = 0; i < 8; i++)
        {
            int ci = x + moves[i].first;
            int cj = y + moves[i].second;

            if (ci >= 0 && cj >= 0 && ci < n && cj < m && !vis[ci][cj])
            {
                if (ci == qi && cj == qj)
                {
                    return steps + 1;
                }

                vis[ci][cj] = true;
                q.push({{ci, cj}, steps + 1});
            }
        }
    }

    return -1;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ki, kj, qi, qj;
        cin >> n >> m >> ki >> kj >> qi >> qj;

        cout << minStepsToQueen(n, m, ki, kj, qi, qj) << endl;
    }
    return 0;
}