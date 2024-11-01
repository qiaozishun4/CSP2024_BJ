#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int a[100005], b[100005];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    n = 0;
    for (int i = 1; i <= 100000; i++)
    {
        if (a[i] != 0) b[++n] = a[i];
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i] -= b[i + 1];
        tot += b[i];
        tot = max(tot, 0);
        b[i] = 0;
    }
    cout << tot;
    return 0;
}