#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight[], int value[], int W)
{
    if (n == 0 || W == 0)
        return 0;
        
    if (weight[n] <= W)
    {
        // duita option
        // niye dekbo, na niye dekbo
        int opt1 = knapsack(n - 1, weight, value, W - weight[n - 1]) + value[n - 1];

        int opt2 = knapsack(n - 1, weight, value, W);

        return max(opt1, opt2);
    }
    else
    {
        // ekta option
        // na niyei dekte hobe
        int opt2 = knapsack(n - 1, weight, value, W);
        return opt2;
    }
};

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
    cout << knapsack(n, weight, value, W) << endl;

    return 0;
}