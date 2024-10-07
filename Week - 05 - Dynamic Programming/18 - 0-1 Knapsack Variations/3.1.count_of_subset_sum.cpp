#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int subset_sum(int n, int a[], int s)
{
    if (n == 0)
    {
        if (s == 0)
            return 1;
        else
            return 0;
    }

    if (dp[n][s] != -1)
        return dp[n][s];

    if (a[n - 1] <= s)
    {
        int op1 = subset_sum(n - 1, a, s - a[n - 1]);
        int op2 = subset_sum(n - 1, a, s);
        dp[n][s] = op1 + op2;
        return dp[n][s];
    }
    else
    {
        dp[n][s] = subset_sum(n - 1, a, s);
        return dp[n][s];
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    memset(dp, -1, sizeof(dp));

    int s;
    cin >> s;

    cout << subset_sum(n, a, s) << endl;

    return 0;
}

// INPUT
// 4
// 1 2 4 6
// 7

// OUTPUT
// 2

// INPUT
// 6
// 1 2 3 4 5 6
// 7

// OUTPUT
// 4