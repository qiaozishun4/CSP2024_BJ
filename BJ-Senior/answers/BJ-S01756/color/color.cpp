#include <bits/stdc++.h>
using namespace std;
#define int long long

int T;
int n, ans;
int a[200010];
int s[200010];

void dfs(int step, int lr, int lb, int sum)
{
    if(s[n]-s[step-1]+sum <= ans) return ;
    if(step > n)
    {
        ans = max(ans, sum);
        return ;
    }
    //red
    dfs(step+1, step, lb, sum+(a[lr]==a[step]?a[lr]:0));
    dfs(step+1, lr, step, sum+(a[lb]==a[step]?a[lb]:0));
}

signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> T;
    while(T--)
    {
        cin >> n;
        ans = 0;
        for(int i = 1; i <= n; i ++)
        {
            cin >> a[i];
            s[i] = s[i-1]+a[i];
        }
        dfs(1, 0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
