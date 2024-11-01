#include <bits/stdc++.h>
using namespace std;

int a[200010], co[200010];
int n, ans;

void dfs(int step, int lb, int lr, int cnt)
{
    if(step == n)
    {
        ans = max(ans, cnt);
        return;
    }
    if(lb == a[step])
    {
        dfs(step + 1, a[step], lr, cnt + a[step]);
    }
    else if(lr == a[step])
    {
        dfs(step + 1, lb, a[step], cnt + a[step]);
    }
    else
    {
        dfs(step + 1, a[step], lr, cnt);
        dfs(step + 1, lb, a[step], cnt);
    }
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        dfs(0, -1, -1, 0);
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
