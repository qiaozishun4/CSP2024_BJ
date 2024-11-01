#include<bits/stdc++.h>
using namespace std;

const int nr = 2e5 + 10;
int n, a[nr], f[nr][2], s[nr], col[nr], res;

void dfs(int step, int b, int r, int ans)
{
    if (step > n)
    {
        res = max(res, ans);
        return;
    }
    dfs(step + 1, step, r, ans + (a[b] == a[step]) * a[step]);
    dfs(step + 1, b, step, ans + (a[r] == a[step]) * a[step]);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
        res = 0;
        dfs(1, 0, 0, 0);
        cout << res << '\n';
    }
    return 0;
}
