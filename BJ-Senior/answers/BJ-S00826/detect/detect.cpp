#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define int long long
using namespace std;
int d[100010], v[100010], a[100010], p[100010], expp[100010], mnn;
bool cs[100010], o[100010];
int check(int n, int m, int vv)
{
    memset(cs, 0, sizeof(cs));
    for(int i = 1; i <= m; i++)
    {
        if(o[i]) continue;
        for(int j = 1; j <= n; j++)
        {
            if(d[j] > p[i]) continue;
            int t;
            if(a[j] < 0)
            {
                t = (0 - v[j] * v[j]) / 2 * a[j];
                if(v[j] * v[j] % (-2 * a[j]) != 0) t++;
                if(t <= p[i]) continue;
            }
            t = v[j] * v[j] + 2 * a[j] * (p[i] - d[j]);
            if(t > vv * vv) cs[j] = 1;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) cnt += cs[i];
    return cnt;
}
void dfs(int n, int m, int vv, int stp, int cnt)
{
    if(stp > m)
    {
        int t = check(n, m, vv);
        if(t == cnt)
        {
            int tt = 0;
            for(int i = 1; i <= m; i++) tt += o[i];
            tt = m - tt;
            mnn = min(mnn, tt);
        }
        return;
    }
    o[stp] = 0;
    dfs(n, m, vv, stp + 1, cnt);
    o[stp] = 1;
    dfs(n, m, vv, stp + 1, cnt);
}
void solve1(int n, int m, int l, int vv)
{
    for(int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
    for(int i = 1; i <= m; i++) cin >> p[i];
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        if(d[i] > p[m]) continue;
        int t;
        if(a[i] < 0)
        {
            t = (0 - v[i] * v[i]) / 2 * a[i];
            if(v[i] * v[i] % (-2 * a[i]) != 0) t++;
            if(t <= p[m]) continue;
        }
        t = v[i] * v[i] + 2 * a[i] * (p[m] - d[i]);
        if(t > vv * vv) cnt++;
    }
    cout << cnt << " ";
    if(cnt == 0) cout << m;
    else cout << m - 1;
    cout << "\n";
}
void solve2(int n, int m, int l, int vv)
{
    mnn = 1145141919810;
    for(int i = 1; i <= n; i++) cin >> d[i] >> v[i] >> a[i];
    for(int i = 1; i <= m; i++) cin >> p[i];
    int cnt = check(n, m, vv);
    cout << cnt << " ";
    dfs(n, m, vv, 1, cnt);
    cout << m - mnn << "\n";
}
signed main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        int n, m, l, vv;
        cin >> n >> m >> l >> vv;
        //memset(d, 0, sizeof(d));
        //memset(p, 0, sizeof(p));
        //memset(a, 0, sizeof(a));
        //memset(v, 0, sizeof(v));
        //memset(expp, 0, sizeof(expp));
        memset(o, 0, sizeof(o));
        //memset(cs, 0, sizeof(cs));
        if(n <= 20 && m <= 20) solve2(n, m, l, vv);
        else solve1(n, m, l, vv);
    }
    return 0;
}