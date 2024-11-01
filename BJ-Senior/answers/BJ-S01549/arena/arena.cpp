#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005, NN = N * 4;
int lg[N];
int n, nn, m, T;
int a[N], aa[N], ask[N], qp[N];
ll ans[N];
int cq[20][N];

bool cmp(int x, int y)
{
    return ask[x] < ask[y];
}

int l[NN], r[NN], d[NN], dep[NN], win[NN][20];
ll sum[NN];
inline void build(int now, int l, int r, int qd)
{
    dep[now] = qd;
    d[now] = cq[qd][r / (1 << qd)];
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(now << 1, l, mid, qd - 1);
    build(now << 1 | 1, mid + 1, r, qd - 1);
}
inline void build2(int now, int l, int r, int qd)
{
    win[now][0] = 0;
    sum[now] = 1ll * (r + l) * (r - l + 1) / 2;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build2(now << 1, l, mid, qd - 1);
    build2(now << 1 | 1, mid + 1, r, qd - 1);
}

int rua;
inline void up(int now, int l, int r)
{
    int ls = now << 1, rs = now << 1 | 1;
    int mid = (l + r) >> 1;
    if (rua < mid)
    {
        if (d[now])
        {
            win[now][0] = win[ls][0];
            for (int i = 1; i <= win[now][0]; i++)
                win[now][i] = win[ls][i];
            sum[now] = sum[ls] + sum[rs];
        }
        else
        {
            sum[now] = sum[ls];
            win[now][0] = 0;
            bool ok = false;
            for (int i = 1; i <= win[ls][0]; i++)
                if (a[win[ls][i]] >= dep[now])
                    win[now][++win[now][0]] = win[ls][i];
                else
                    ok = true;
            if (ok || sum[ls]) sum[now] += sum[rs];
        }
    }
    else
    {
        if (d[now])
        {
            bool t = false;
            win[now][0] = 0;
            for (int i = 1; i <= win[rs][0]; i++)
                if (a[win[rs][i]] >= dep[now])
                    win[now][++win[now][0]] = win[rs][i];
                else
                    t = true;
            sum[now] = sum[rs];
            if (sum[rs] || t) win[now][++win[now][0]] = win[ls][1];
        }
        else
        {
            if (a[win[ls][1]] >= dep[now])
            {
                sum[now] = 0;
                win[now][win[now][0] = 1] = win[ls][1];
            }
            else
            {
                sum[now] = sum[rs];
                win[now][0] = win[rs][0];
                for (int i = 1; i <= win[now][0]; i++)
                    win[now][i] = win[rs][i];
            }
        }
    }
}
inline void chg(int now, int l, int r, int p)
{
    if (l == r)
    {
        sum[now] = 0;
        win[now][0] = 1;
        win[now][1] = l;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) chg(now << 1, l, mid, p);
    else chg(now << 1 | 1, mid + 1, r, p);
    up(now, l, r);
}

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    //16:29 begin
    //17:11 finish
    //18:03 sample1
    //18:05 sample complete

    lg[1] = 0;
    for (int i = 2; i < N; i++)
    {
        lg[i] = lg[i - 1];
        if (i - 1 == (1 << (lg[i - 1]))) lg[i]++;
    }

    scanf("%d%d", &n, &m);
    nn = (1 << lg[n]);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &aa[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &ask[i]);
        qp[i] = i;
    }
    sort(qp + 1, qp + 1 + m, cmp);
    for (int i = 1; i <= lg[n]; i++)
    {
        for (int j = 1; j <= (1 << (lg[n] - i)); j++)
            scanf("%1d", &cq[i][j]);
    }
    scanf("%d", &T);
    build(1, 1, nn, lg[n]);
    while (T--)
    {
        int x[4];
        for (int i = 0; i < 4; i++) scanf("%d", &x[i]);
        for (int i = 1; i <= n; i++) a[i] = aa[i] ^ x[i % 4];

        build2(1, 1, nn, lg[n]);
        rua = 0;
        for (int i = 1; i <= m; i++)
        {
            int tp = ask[qp[i]];
            while (rua < tp)
            {
                rua++;
                int now = 1 << (lg[n] - lg[rua]);
                chg(now, 1, nn / now, rua);
            }
            ll t = 0, now = 1 << (lg[n] - lg[rua]);
            for (int i = 1; i <= win[now][0]; i++)
                t += win[now][i];
            t += sum[now];
            ans[qp[i]] = t;
            //printf("%d %lld\n", ask[qp[i]], ans[qp[i]]);
        }
        ll ans1 = 0;
        for (int i = 1; i <= m; i++)
            ans1 ^= i * ans[i];
        printf("%lld\n", ans1);
    }
    return 0;
}
