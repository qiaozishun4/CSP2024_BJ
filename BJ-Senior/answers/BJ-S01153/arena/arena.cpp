#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 3e5 + 5;

char str[maxn];
ll ans[maxn];
int n, m, k, len, a[maxn], b[maxn], q[maxn];
int ls[maxn], rs[maxn], fa[maxn], dep[maxn], win[maxn], L[maxn], R[maxn], mxdep[maxn], X[4], cnt;
bool can[maxn], pt[maxn];

void updmxdep(int x, int dp)
{
    mxdep[x] = max(mxdep[x], dp);
    if (!ls[x]) return;
    if (!pt[x]) updmxdep(ls[x], dp ? dp : dep[x]), updmxdep(rs[x], dp);
    else updmxdep(ls[x], dp), updmxdep(rs[x], dp ? dp : dep[x]);
}

void work()
{
    cin >> X[0] >> X[1] >> X[2] >> X[3];
    for (int i = 1; i <= n; i++) a[i] = b[i] ^ X[i & 3];
    for (int i = 1; i <= len; i++) win[i] = i;
    for (int i = 1; i <= cnt; i++) mxdep[i] = 0;
    for (int i = len + 1; i <= cnt; i++) win[i] = -1;
    for (int i = 1; i <= len; i++) can[i] = 0;
    ll sum = 1; int t = 0; can[1] = 1, ans[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i == (1 << t) + 1)
        {
            t++; int x = 1;
            for (int j = 1; j <= t; j++) x = fa[x];
            updmxdep(x, 0);
            if (!pt[x])
            {
                if (a[win[ls[x]]] < dep[x])
                {
                    if (can[win[ls[x]]]) can[win[ls[x]]] = 0, sum -= win[ls[x]];
                    for (int j = i; j <= (1 << t); j++) can[j] = 1, sum += j;
                }
                else win[x] = win[ls[x]];
            }
            else for (int j = i; j <= (1 << t); j++) can[j] = 1, sum += j;
        }
        if (!can[i])
        {
            ans[i] = sum;
            continue;
        }

        int x = i, nv = i;
        for (int j = 1; j <= t; j++)
        {
            int lst = x; x = fa[x];
            if (lst == ls[x])
            {
                if (!pt[x])
                {
                    if (a[nv] < dep[x])
                    {
                        if (can[nv]) can[nv] = 0, sum -= nv;
                        break;
                    }
                    else
                    {
                        win[x] = nv;
                        for (int d = L[rs[x]]; d <= R[rs[x]]; d++) can[d] = 0, sum -= d;
                    }
                }
                else
                {
                    if (a[nv] < mxdep[nv] && can[nv]) can[nv] = 0, sum -= nv;
                    break;
                }
            }
            else if (pt[x])
            {
                if (a[nv] < dep[x])
                {
                    win[x] = win[ls[x]];
                    if (can[nv]) can[nv] = 0, sum -= nv;
                    nv = win[x];
                }
                else
                {
                    win[x] = nv;
                    if (can[win[ls[x]]]) can[win[ls[x]]] = 0, sum -= win[ls[x]];
                }
            }
            else win[x] = nv;
        }
        ans[i] = sum;
    }

    ll res = 0;
    for (int i = 1; i <= m; i++) res ^= (1ll * ans[q[i]] * i);
    cout << res << "\n";
}

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= m; i++) cin >> q[i];
    while ((1 << k) < n) k++; cnt = len = (1 << k);
    for (int i = 1; i <= len; i++) L[i] = R[i] = i;

    int pos = 1;
    for (int i = 1; i <= k; i++)
    {
        cin >> str; int nw = cnt;
        for (int j = pos; j <= nw; j += 2)
        {
            fa[j] = fa[j + 1] = ++cnt;
            ls[cnt] = j, rs[cnt] = j + 1, dep[cnt] = i, L[cnt] = L[j], R[cnt] = R[j + 1];
            pt[cnt] = (str[(j - pos) >> 1] == '1');
        }
        pos = nw + 1;
    }

    int T; cin >> T;
    while (T--) work();
    return 0;
}