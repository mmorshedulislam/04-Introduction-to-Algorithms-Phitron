#include <bits/stdc++.h>
using namespace std;

// Bottom up approach

int main()
{
    int n;
    cin >> n; // 9
    int a[n];

    a[0] = 0;
    a[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }

    cout << a[n] << endl; // 34

    return 0;
}