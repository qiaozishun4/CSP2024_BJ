#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int T, n, m, L, V, d[N], v[N], a[N], p[N], q1[N], q2[N], g1[N], g2[N];
bool f[N];
struct D
{
    int l, r;
} td;
vector<D> u;

int fl(int x)
{
    return lower_bound(p + 1, p + m + 1, x) - p;
}

int fu(int x)
{
    return upper_bound(p + 1, p + m + 1, x) - p;
}

bool cmp(D x, D y)
{
    return x.l < y.l;
}

int main()
{
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);
    cin >> T;
    for(int t = 1; t <= T; t++)
    {
        u.clear();
        cin >> n >> m >> L >> V;
        for(int i = 0; i < N; i++)
        {
            d[i] = 0;
            v[i] = 0;
            a[i] = 0;
            p[i] = 0;
            q1[i] = 0;
            q2[i] = 0;
            g1[i] = 0;
            g2[i] = 0;
            f[i] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            cin >> d[i] >> v[i] >> a[i];
            q1[i] = V * V - v[i] * v[i];
            q2[i] = 2 * a[i];
            if(a[i] >= 0)
            {
                g1[i] = L;
                g2[i] = 1;
            }
            else
            {
                g1[i] = v[i] * v[i];
                g2[i] = -2 * a[i];
            }
            //printf("%d/%d, %d/%d\n", q1[i], q2[i], g1[i], g2[i]);
        }
        for(int i = 1; i <= m; i++)
            cin >> p[i];
        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(a[i] < 0)
            {
                int x = fl(d[i]);
                if(x > m || v[i] <= V)
                    continue;
                if(p[x] * g2[i] >= g1[i] + g2[i] * d[i])
                    continue;
                if(p[x] * q2[i] > q1[i] + q2[i] * d[i])
                {
                    cnt1++;
                    f[i] = 1;
                    int y = fu(q1[i] / q2[i] + d[i]) - 1;
                    u.push_back(td);
                    int si = u.size();
                    u[si - 1].l = d[i];
                    u[si - 1].r = p[y];
                }
            }
            else
            {
                if(a[i] == 0)
                {
                    if(v[i] > V)
                    {
                        cnt2 = 1;
                        cnt1++;
                        f[i] = 0;
                    }
                    continue;
                }
                int x = fu(int(d[i] + q1[i] / q2[i]));
                if(x > m)
                    continue;
                else
                {
                    cnt2 = 1;
                    cnt1++;
                    f[i] = 1;
                }
            }
        }
        cout << cnt1 << " ";
        if(cnt1 == 0)
        {
            cout << m << endl;
            continue;
        }
        sort(u.begin(), u.end(), cmp);
        cnt2++;
        int si = u.size(), lr = u[0].r;
        for(int i = 1; i < si; i++)
        {
            //cout << u[i].l << " " << u[i].r << endl;
            if(u[i].l > lr)
            {
                lr = u[i].r;
                cnt2++;
            }
        }
        cout << m - cnt2 << endl;
    }
    return 0;
}

