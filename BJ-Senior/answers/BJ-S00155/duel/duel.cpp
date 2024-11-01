#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100010];
int b[100010];
signed main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, sz = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    int ans = 0;
    for(int i = 1; i <= 1e5; i++)
    {
        ans = max(0ll, ans - b[i]);
        ans += b[i];
    }
    cout << ans << endl;
    return 0;
}
