#include <iostream>
using namespace std;
const int MAXN = 2e5 + 10;
int n;
long long a[MAXN];
int c[MAXN][2], t[MAXN];
long long ans = 0;
long long cal()
{
    for (int i = 1; i <= n; i++)
    {
        c[i][0] = max(c[i][0], c[i - 1][0]);
        if (t[i] == 0)
            c[i + 1][0] = i;
        c[i][1] = max(c[i][1], c[i - 1][1]);
        if (t[i] == 1)
            c[i + 1][1] = i;
    }
    long long ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[c[i][t[i]]] == a[i])
            ret += a[i];
        c[i][0] = c[i][1] = 0;
    }
    return ret;
}
void dfs(int x)
{
    if (x == n + 1)
    {
        ans = max(ans, cal());
        return;
    }
    t[x] = 0;
    dfs(x + 1);
    t[x] = 1;
    dfs(x + 1);
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        ans = 0;
        dfs(1);
        cout << ans << '\n';
    }
    return 0;
}
