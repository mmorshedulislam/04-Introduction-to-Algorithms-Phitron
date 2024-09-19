#include <bits/stdc++.h>
using namespace std;

class Step
{
    int x, y, steps;
    Step(int x, int y, int steps)
    {
        this->x = x;
        this->y = y;
        this->steps = steps;
    };
};

int minStepsToQueen(int n, int m, int ki, int kj, int qi, int qj)
{
    if (qi == ki && qj == kj)
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
        int x, y, steps;
        x = par.first.first;
        y = par.first.second;
        steps = par.second;
    }
};

int main()
{
    int t;
    cin >> t; // Number of test cases
    while (t--)
    {
        int n, m, ki, kj, qi, qj;
        cin >> n >> m >> ki >> kj >> qi >> qj;

        // Output the result for the current test case
        cout << minStepsToQueen(n, m, ki, kj, qi, qj) << endl;
    }
    return 0;
}