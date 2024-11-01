#include <iostream>
using namespace std;

int t, n, a[200005], c[200005], ans;

int get()
{
    int lr = 0, lb = 0, s = 0;
    for (int i = 1; i <= n; ++i)
        if (c[i] == 0)
        {
            if (a[lr] == a[i] && lr) s += a[i];
            lr = i;
        }
        else
        {
            if (a[lb] == a[i] && lb) s += a[i];
            lb = i;
        }
    return s;
}

void dfs(int k)
{
    if (k > n)
    {
        ans = max(ans, get());
        return;
    }
    c[k] = 0;
    dfs(k+1);
    c[k] = 1;
    dfs(k+1);
}

int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        ans = 0;
        dfs(1);
        cout << ans;
    }
    return 0;
}
