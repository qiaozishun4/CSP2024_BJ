#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 1e5;
int T, ans = 0;
int n, a[NR + 7];

void dfs(int x, int fir, int sec, int sum)
{
    if(x == n + 1)
    {
        ans = max(ans, sum);
        return;
    }
    int val = 0;
    if(a[x] == fir) val += fir;
    dfs(x + 1, a[x], sec, sum + val);
    if(a[x] == fir) val -= fir;
    if(a[x] == sec) val += sec;
    dfs(x + 1, fir, a[x], sum + val);
}

signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        dfs(1, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
