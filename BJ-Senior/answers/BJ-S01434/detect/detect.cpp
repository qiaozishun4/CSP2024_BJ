#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int t, n, m, l, V, d[100005], v[100005], a[100005], p[100005], s[1000005], cnt, ans2;
bool f[1000005], c[100];

double getv(int v, int a, int s)
{
    return sqrt(1.0 * v * v + 2.0 * a * s);
}

double getp(int v, int a, int tv)
{
    return 1.0 * (tv * tv - v * v) / 2.0 / a;
}

bool chk(int mx)
{
    int cnt2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] >= 0)
        {
            if (d[i] > p[mx]) continue;
            if (getv(v[i], a[i], p[mx] - d[i]) > V) ++cnt2;
        }
        else
        {
            if (v[i] < V) continue;
            double pos = getp(v[i], a[i], V);
            int pp = int(pos);
            for (int j = d[i]; j <= d[i] + pp; ++j)
                if (f[j])
                {
                    ++cnt2;
                    break;
                }
        }
    }
    return cnt2 == cnt;
}

void dfs(int k, int sum, int mx)
{
    if (k > m)
    {
        if (sum <= ans2) return;
        if (chk(mx)) ans2 = max(ans2, sum);
        return;
    }
    c[k] = 0;
    f[p[k]] = false;
    dfs(k+1, sum + 1, mx);
    c[k] = 1;
    f[p[k]] = true;
    dfs(k+1, sum, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        memset(f, false, sizeof f);
        memset(s, 0, sizeof s);
        cin >> n >> m >> l >> V;
        bool f1 = true, f2 = true, f3 = true;
        for (int i = 1; i <= n; ++i)
        {
            cin >> d[i] >> v[i] >> a[i];
            if (a[i]) f1 = false;
            if (a[i] <= 0) f2 = false;
            if (a[i] >= 0) f3 = false;
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> p[i];
            f[p[i]] = 1;
        }
        for (int i = 1; i <= l; ++i) s[i] = f[i] + s[i-1];
        if (f1)
        {
            int ans = 0;
            for (int i = 1; i <= n; ++i)
                if (d[i] <= p[m] && v[i] > V) ++ans;
            cout << ans << ' ';
            if (ans) cout << m - 1 << '\n';
            else cout << m << '\n';
        }
        if (f2)
        {
            int ans = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (d[i] > p[m]) continue;
                if (getv(v[i], a[i], p[m] - d[i]) > V) ++ans;
            }
            cout << ans << ' ';
            if (ans) cout << m-1 << '\n';
            else cout << m << '\n';
        }
        else
        {
            cnt = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] >= 0)
                {
                    if (d[i] > p[m]) continue;
                    if (getv(v[i], a[i], p[m] - d[i]) > V) ++cnt;
                }
                else
                {
                    if (v[i] < V) continue;
                    double p = getp(v[i], a[i], V);
                    int pp = int(p);
                    for (int j = d[i]; j <= d[i] + pp; ++j)
                        if (f[j])
                        {
                            ++cnt;
                            break;
                        }
                }
            }
            cout << cnt << ' ';
            ans2 = 0;
            dfs(1, 0, 0);
            cout << ans2 << '\n';
        }
    }
    return 0;
}
