#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int first, second;
    void make_pair(int a, int b)
    {
        first = a;
        second = b;
    };
};

int main()
{
    Pair p;
    p.make_pair(10, 20);
    cout << p.first << " " << p.second << endl; // 10 20

    // built in
    pair<string, int> pr;
    pr = make_pair("Morshed", 20);
    cout << pr.first << " " << pr.second << endl; // Morshed 20

    return 0;
}