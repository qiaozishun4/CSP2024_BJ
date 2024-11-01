#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const int logn = 15;

struct car
{
    int l, r;
    bool operator < (const car &a)
    {
        return l < a.l;
    }
} c[maxn];

int t, n, m, L, V, vv, ans, ans2;
int d[maxn], v[maxn], a[maxn];
int p[maxn], l[maxn], r[maxn];
int st[maxn][logn];
bool flag[maxn], f[maxn];

/*
void init ()
{
    for (int i = 1; i <= logn; i ++)
    {
        for (int j = 1; j + (1 << i) - 1 <= L; j ++)
        {
            st[j][i] = max (st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }
}


int query (int l, int r)
{
    int k = log2 (r - l + 1);
    return max (st[l][k], st[r - (1 << k) + 1][k]);
}
*/

bool query (int i, int j)
{
    if (p[m] < i) return 0;
    int l = 1, r = m, res = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (p[mid] >= i)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    //cout << res << endl;
    return p[res] <= j;
}

bool query2 (int i, int j, int mm)
{
    if (pp[mm] < i) return 0;
    int l = 1, r = mm, res = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (pp[mid] >= i)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    //cout << res << endl;
    return pp[res] <= j;
}

int find (int i)
{
    int l = 1, r = m, res = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (p[mid] <= i)
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

int div_ceil (int a, int b)
{
    if (a % b == 0) return a / b;
    return (a + b) / b;
}

int main()
{
    freopen ("detect.in", "r", stdin);
    freopen ("detect.out", "w", stdout);
    cin >> t;
    while (t --)
    {
        memset (l, 0, sizeof (l));
        memset (r, 0, sizeof (r));
        memset (c, 0, sizeof (c));
        memset (flag, 0, sizeof (flag));
        memset (f, 0, sizeof (f));
        memset (st, 0, sizeof (st));
        ans = cnt = 0;
        cin >> n >> m >> L >> V;
        vv = V * V;
        for (int i = 1; i <= n; i ++)
        {
            cin >> d[i] >> v[i] >> a[i];
            if (v[i] <= V && a[i] <= 0);
            else if (v[i] * v[i] + a[i] * (L - d[i]) * 2 < V * V && a[i] > 0);
            else if (v[i] > V && a[i] >= 0)
            {
                l[i] = d[i];
                r[i] = L;
            }
            else if (a[i] < 0)
            {
                l[i] = d[i];
                r[i] = d[i] + (V * V - v[i] * v[i]) / (a[i] * 2);
                if (v[i] * v[i] + a[i] * (r[i] - d[i]) * 2 == V * V) r[i] --;
            }
            else
            {
                l[i] = d[i] + div_ceil (V * V - v[i] * v[i], a[i] * 2);
                if (v[i] * v[i] + a[i] * (l[i] - d[i]) * 2 == V * V) l[i] ++;
                r[i] = L;
            }
        }

        for (int i = 1; i <= m; i ++)
        {
            cin >> p[i];
            //st[p[i]][0] = 1;
        }

        //init ();

        for (int i = 1; i <= n; i ++)
        {
            //cout << l[i] << " " << r[i] << endl;
            if (r[i] != 0 && query (l[i], r[i]))
            {
                ans ++;
                flag[i] = 1;
                f[i] = 1;
            }
        }
        cout << ans << " ";

        if (m > 20)
        {
            cout << m - 1 << endl;
            break;
        }
        for (int i = 0; i <= (1 << m) - 1; i ++)
        {
            int a = 0, cnt = 0;
            for (int j = 0; j < m; j ++)
            {
                if (i & (1 << j)) cnt ++, pp[cnt] = p[j + 1];
            }
            for (int i = 1; i <= )
            for (int j = 1; j <= n; j ++)
            {
                if (r[j] != 0 && query2 (l[j], r[j]))
                {
                    ans ++;
                }
            }
            if (a == ans) ans2 = min (ans2, cnt);
        }
        cout << ans2 << endl;
        /*
        for (int i = 1; i <= n; i ++)
        {
            for (int j = i + 1; j <= n; j ++)
            {
                if (flag[i] && flag[j] && l[i] <= l[j] && r[j] <= r[i]) f[i] = 0;
            }
        }
        for (int i = 1; i <= n; i ++)
        {
            if (f[i])
            {
                c[++ cnt].l = l[i];
                c[cnt].r = r[i];
            }
        }
        //cout << cnt << endl;
        sort (c + 1, c + cnt + 1);
        ans = 0;
        for (int i = 1; i <= cnt; i ++)
        {
            int now = p[find (c[i].r)];
            cout << now << endl;
            while (c[i].l <= now && i <= cnt) i ++;
            ans ++;
        }
        cout << m - ans << endl;
        */
    }
    return 0;
}
