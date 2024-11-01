#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
        cout << max(abs(t%(t-5)*3), 1) << endl;
    return 0;
}

