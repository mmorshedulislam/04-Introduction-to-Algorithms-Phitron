#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    int prevFact = fact(n - 1);
    return prevFact * n;
}

int main()
{
    int n;
    cin >> n;                // 4
    cout << fact(n) << endl; // 24
    return 0;
}