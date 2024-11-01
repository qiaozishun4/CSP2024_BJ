#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, a[2020], r[2020], b[2020], ans;
int idxr, idxb;
void dfs(int x, int sum)
{
    if(x == n + 1)
    {
        ans = max(ans, sum);
        return ;
    }
    if(r[idxr] == a[x])
    {
        r[++idxr] = a[x];
        dfs(x + 1, sum + a[x]);
        idxr--;
    }
    else if(b[idxb] == a[x])
    {
        b[++idxb] = a[x];
        dfs(x + 1, sum + a[x]);
        idxb--;
    }
    else
    {
        r[++idxr] = a[x];
        dfs(x + 1, sum);
        idxr--;
        b[++idxb] = a[x];
        dfs(x + 1, sum);
        idxb--;
    }
    return;
}

signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        idxr = 0, idxb = 0, ans = 0;
        r[++idxr] = a[1];
        dfs(2, 0);
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
