#include <bits/stdc++.h>
using namespace std;
long long read()
{
    long long x = 0, f = 1;
    char ch = cin.get();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = cin.get();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = cin.get();
    }
    return x * f;
}
#define int long long
#define endl '\n'
signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n = read();
    int a[n];
    int vis[n];
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        a[i] = read();
        vis[i] = 0;
    }
    sort(a, a + n);
    int ptr = 1;
    for (int i = 0; i < n; i++)
    {
        while (ptr < n && (a[ptr] <= a[i] || vis[ptr]))
        {
            ptr++;
        }
        if (ptr < n)
        {
            vis[ptr] = 1;
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}
