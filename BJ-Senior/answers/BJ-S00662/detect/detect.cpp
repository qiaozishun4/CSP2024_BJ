#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 10;
int n, m, l, x;
long long d[MAXN], v[MAXN], a[MAXN], p[MAXN];
int t[MAXN];
int ans, num;
vector<int> fast[MAXN];
bool check()
{
    for (int i = 1; i <= n; i++)
    {
        bool f = false;
        for (auto j : fast[i])
            if (t[j] == 1)
            {
                f = true;
                break;
            }
        if (!f && fast[i].size() > 0)
            return false;
    }
    return true;
}
void dfs(int x)
{
    if (x == m + 1)
    {
        if (check())
        {
            ans = max(ans, num);
        }
        return;
    }
    t[x] = 0;
    num++;
    dfs(x + 1);
    num--;
    t[x] = 1;
    dfs(x + 1);
}
int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= n; i++)
            fast[i].clear();
        cin >> n >> m >> l >> x;
        for (int i = 1; i <= n; i++)
            cin >> d[i] >> v[i] >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> p[i];
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            bool f = false;
            for (int j = 1; j <= m; j++)
            {
                if (p[j] >= d[i])
                {
                    long long now = v[i] * v[i] + 2 * a[i] * (p[j] - d[i]);
                    if (x * x < now)
                    {
                        f = true;
                        fast[i].push_back(j);
                    }
                }
            }
            if (f)
                cnt++;
        }
        cout << cnt << ' ';
        ans = 0;
        num = 0;
        dfs(1);
        cout << ans << '\n';
    }
    return 0;
}
