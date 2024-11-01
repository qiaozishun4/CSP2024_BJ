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
//#define int long long
#define endl '\n'
long long solve(int * a, int l, int r, int lred, int lblue, int * remain)
{
    long long ans = 0;
    for (int i = l; i <= r; i++)
    {
        remain[a[i]]--;
        if (a[i] == lred || a[i] == lblue)
        {
            ans += a[i];
        }
        else
        {
            if (remain[lred] == 0)
            {
                lred = a[i];
            }
            else if (remain[lblue] == 0)
            {
                lblue = a[i];
            }
            else
            {
                ans += max(solve(a, i + 1, r, lred, a[i], remain), solve(a, i + 1, r, a[i], lblue, remain));
                break;
            }
        }
    }
    return ans;
}
signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = read();
    while (t--)
    {
        int n = read();
        int a[n];
        int remain[1000001] = {0};
        for (int i = 0; i < n; i++)
        {
            a[i] = read();
            remain[a[i]]++;
        }
        cout << solve(a, 0, n - 1, 0, 0, remain) << endl;
    }
    return 0;
}
