#include <bits/stdc++.h>
#define ll long long;
using namespace std;

const long long int N = 1e6 + 5;
long long int dp[N];

long long int fibo(int n) // O(N)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        long long int ans = fibo(n - 1) + fibo(n - 2);
        dp[n] = ans;
        return ans;
    }
}

int main()
{
    int n;
    cin >> n; // 100
    memset(dp, -1, sizeof(dp));
    cout << fibo(n) << endl; // 3736710778780434371
    return 0;
}
