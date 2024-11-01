#include<bits/stdc++.h>
using namespace std;

const int nr = 1e5 + 10;
int n, a[nr], b[nr], d[nr], dn, s[nr];

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[a[i]]++;
    for (int i = 1; i <= 1e5; i++)
        if (b[i] > 0) d[++dn] = b[i];
    int res = n;
    for (int i = 1; i < dn; i++)
    {
        res -= min(d[i], d[i + 1]);
        if (d[i + 1] < d[i]) d[i + 1] = d[i];
    }
    cout << res << '\n';
    return 0;
}