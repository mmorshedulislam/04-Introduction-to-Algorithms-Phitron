#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int W;
    cin >> W;
    int dp[n + 1][W + 1];

    // set first row and column = 0
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (weight[i - 1] <= j)
            {
                int op1 = dp[i - 1][j - weight[i - 1]] + value[i - 1];
                int op2 = dp[i - 1][j];
                dp[i][j] = max(op1, op2);
            }
            else
            {
                int op2 = dp[i - 1][j];
                dp[i][j] = op2;
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[n][W] << endl; // 8

    return 0;
}

// input
// 4
// 2 3 4 5
// 1 3 5 3
// 8

// output
// 0 0 0 0 0 0 0 0 0
// 0 0 1 1 1 1 1 1 1
// 0 0 1 3 3 4 4 4 4
// 0 0 1 3 5 5 6 8 8
// 0 0 1 3 5 5 6 8 8
// 8