#include <bits/stdc++.h>
using namespace std;
#define int long long
#define st first
#define nd second
const int N = 1e5 + 10;
const double eps = 1e-8;

int T, n, m, L, V, d[N], v[N], a[N], p[N], cnt, cnt2;
bool can2;
pair <int, int> c[N], b[N];

void insert()
{
    can2 = 1;
    cin >> n >> m >> L >> V;
    for(int i = 1; i <= n; i++)
        cin >> d[i] >> v[i] >> a[i], can2 &= (a[i] >= 0);
    for(int i = 1; i <= m; i++)
        cin >> p[i];
}

int detect(int x)
{
    int an = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(d[i] <= p[j] && ((x >> j - 1) & 1))
                if(sqrt(v[i] * v[i] + 2 * a[i] * (p[j] - d[i])) - V > eps)
                {
                    an++;
                    break;
                }
    return an;
}

void work1()
{
    int lim = (1 << m) - 1;
    int an = detect(lim), ans = 1e18;
    for(int x = 0; x <= lim; x++)
    {
        int cnt = 0;
        for(int i = 1; i <= m; i++)
            cnt += ((x >> i - 1) & 1);
        if(detect(x) == an)
            ans = min(ans, cnt);
    }
    cout << an << " " << m - ans << '\n';
}

void work2()
{
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(d[i] <= p[m])
            if(sqrt(v[i] * v[i] + 2 * a[i] * (p[m] - d[i])) - V > eps)
                ans++;
    cout << ans << " " << m - (ans != 0) << '\n';
}

bool check(int i, int j)
{
    return sqrt(v[i] * v[i] + 2 * a[i] * (p[j] - d[i])) - V > eps;
}

void work()
{
    insert();
    cnt = 0, cnt2 = 0;
    memset(b, 0, sizeof b);
    memset(c, 0, sizeof c);
    if(n <= 20)
        work1();
    else if(can2)
        work2();
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(a[i] >= 0)
            {
                int l = lower_bound(p + 1, p + m + 1, d[i]) - p, r = m, ans = -1;
                while(l <= r)
                {
                    int mid = l + r >> 1;
                    if(check(i, mid))
                        ans = mid, r = mid - 1;
                    else
                        l = mid + 1;
                }
                if(ans == -1)
                    continue;
                c[++cnt] = {ans, m};
            }
            else
            {
                int l = lower_bound(p + 1, p + m + 1, d[i]) - p, r = m, ans = -1;
                while(l <= r)
                {
                    int mid = l + r >> 1;
                    if(check(i, mid))
                        ans = mid, l = mid + 1;
                    else
                        r = mid - 1;
                }
                if(ans == -1)
                    continue;
                c[++cnt] = {lower_bound(p + 1, p + m + 1, d[i]) - p, ans};
            }
        }
        cout << cnt << " ";
        sort(c + 1, c + cnt + 1);
        int minr = 1e18;
        for(int i = cnt; i >= 1; i--)
            if(c[i].nd < minr)
                b[++cnt2] = c[i], minr = c[i].nd;
        cnt = cnt2;
        sort(b + 1, b + cnt + 1);
        int lst = 0;
        int ans = 0;
        for(int i = 1; i <= cnt; i++)
            if(!(b[i].st <= lst && lst <= b[i].nd))
                lst = b[i].nd, ans++;
        cout << m - ans << endl;
    }
}

signed main()
{
    freopen("detect.out", "w", stdout);
    freopen("detect.in", "r", stdin);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> T;
    while(T--)
        work();
}