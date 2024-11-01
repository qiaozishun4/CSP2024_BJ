#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <ctime>

typedef long long ll;
typedef double lf;

namespace FastIO
{
    const int MAXSIZE = 1 << 20;
    char buf[MAXSIZE], *p1, *p2;
    #define gc (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? EOF : *p1++)
    template <typename T>
    void Read(T &x)
    {
        x = 0; char ch = gc; bool f = 0;
        while (ch < '0' || ch > '9') { if (ch == '-') f = 1; ch = gc; }
        while (ch >= '0' && ch <= '9') x = x * 10 + (ch ^ 48), ch = gc;
        if (f) x = -x;
    }
    void Read(char &ch)
    {
        ch = gc;
        while (ch < '0' || ch > '9') ch = gc;
    }
}

using namespace std;
using FastIO::Read;

const int MAXN = 4e5 + 10;

// #include <cassert>

int n, m, A[MAXN], c[MAXN];
bool TP[30][MAXN]; int TOP[50];

int pos[MAXN];
int N, K, _a[MAXN], dep[MAXN];
bool tp[MAXN]; ll sum[MAXN];
int ta;
void Build(int cur, int l, int r, int d)
{
    dep[cur] = d;
    if (l == r - 1) _a[cur] = A[++ta], pos[ta] = cur, sum[cur] = ta;
    else
    {
        int mid = l + r >> 1;
        Build(cur << 1, l, mid, d - 1), Build(cur << 1 | 1, mid, r, d - 1);
        // if (cur << 1 >= MAXN) cerr << cur << '\n';
        // assert((cur << 1) < MAXN);
        tp[cur] = TP[d][TOP[d]++], sum[cur] = sum[cur << 1] + sum[cur << 1 | 1];
    }
}

int a[MAXN], id[MAXN];
int vec[MAXN][20], tot[MAXN];

int vt[50], ch[50][2]; bool vis[MAXN], on[MAXN];
int mn[MAXN];

int main()
{
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    Read(n), Read(m);
    for (int i = 1; i <= n; i++) Read(A[i]);
    for (int i = 1; i <= m; i++) Read(c[i]);
    N = 1, K = 0;
    while (n > N) N <<= 1, K++;
    // cerr << N << '\n';
    char cht;
    for (int i = 1; i <= K; i++)
        for (int j = 0; j < (1 << K - i); j++) Read(cht), TP[i][j] = cht - '0';
    Build(1, 0, N, K);
    // cerr << N << '\n';
    // for (int i = 1; i < (N << 1); i++) cerr << _a[i] << ' '; cerr << '\n';
    // for (int i = 1; i <= n; i++) cout << pos[i] << ' '; cout << '\n';
    for (int i = 1; i <= m; i++)
    {
        if (pos[c[i]] == (N << 1) - 1) { vec[i][++tot[i]] = 1; continue; }
        int cur = pos[c[i] + 1];
        // cout << cur << '\n';
        while (cur > 1)
        {
            if (cur & 1) vec[i][++tot[i]] = cur ^ 1;
            cur >>= 1;
            // cout << cur << "\n";
        }
        // cout << "------\n";
    }
    // for (int i = 1; i <= m; i++)
    // {
    //     cout << "Q " << c[i] << '\n';
    //     for (int j = tot[i]; j >= 1; j--) cout << vec[i][j] << ' '; cout << '\n';
    // }
    // return 0;
    int T, X[4];
    Read(T);
    while (T--)
    {
        // cerr << T << '\n';
        Read(X[0]), Read(X[1]), Read(X[2]), Read(X[3]);
        // cerr << "$\n";
        for (int i = N; i < (N << 1) && i - N + 1 <= n; i++)
        {
            // cerr << "#\n";
            // cerr << i - N + 1 << '\n';
            // cerr << i << '\n';
            a[i] = _a[i] ^ X[(i - N + 1) % 4], id[i] = i - N + 1;
        }
        // cerr << "$\n";
        for (int i = N - 1; i; i--)
        {
            if (!tp[i])
            {
                if (a[i << 1] >= dep[i]) id[i] = id[i << 1], a[i] = a[i << 1];
                else id[i] = id[i << 1 | 1], a[i] = a[i << 1 | 1];
            }
            else
            {
                if (a[i << 1 | 1] >= dep[i]) id[i] = id[i << 1 | 1], a[i] = a[i << 1 | 1];
                else id[i] = id[i << 1], a[i] = a[i << 1];
            }
        }
        // cerr << "So " << T << '\n';
        ll ans = 0;
        for (int i = 1; i <= m; i++)
        {
            if (tot[i] == 1) { //cout << id[vec[i][1]] << ' ', 
            ans ^= ((ll)id[vec[i][1]] * i); continue; }
            // cout << "Solve " << i << ' ' << tot[i] << "\n";
            ll res = 0;
            for (int j = 1; j <= tot[i]; j++) vis[vec[i][j]] = 1, mn[vec[i][j]] = a[vec[i][j]];
            int cur = vec[i][1] >> 1, L = dep[cur], R = dep[vec[i][tot[i]]] + 1;
            // cerr << cur << ' ' << L << ' ' << R << '\n';
            while (cur && dep[cur] <= R)
            {
                vt[dep[cur]] = cur;
                ch[dep[cur]][0] = cur << 1, ch[dep[cur]][1] = cur << 1 | 1;
                cur >>= 1;
            }
            // for (int j = 1; j < N << 1; j++) cout << mn[j] << ' '; cout << '\n';
            // cerr << "Get\n";
            for (int j = L; j <= R; j++) on[vt[j]] = 1;
            for (int j = L; j <= R; j++)
            {
                if (!vis[ch[j][0]] && !on[ch[j][0]]) mn[ch[j][0]] = -1;
                if (!vis[ch[j][1]] && !on[ch[j][1]]) mn[ch[j][1]] = -1;
                // cout << vt[j] << ' ' << ch[j][0] << ' ' << ch[j][1] << '\n';
                if (!tp[vt[j]]) mn[vt[j]] = (mn[ch[j][0]] >= j || mn[ch[j][0]] == -1 ? mn[ch[j][0]] : mn[ch[j][1]]);
                else mn[vt[j]] = (mn[ch[j][1]] >= j || mn[ch[j][1]] == -1 ? mn[ch[j][1]] : mn[ch[j][0]]);
                // cout << mn[ch[j][0]] << ' ' << mn[ch[j][1]] << ' ' << mn[vt[j]] << '\n';
                // cout << '\n';
            }
            // cout << "#\n";
            // for (int j = L; j <= R; j++) cout << mn[vt[j]] << ' '; cout << '\n';
            int mx = 0;
            for (int j = R; j >= L; j--)
            {
                if (vis[ch[j][0]] && mn[ch[j][0]] >= mx)
                {
                    if (!tp[vt[j]] && mn[ch[j][0]] >= j) res += id[ch[j][0]];
                    if (tp[vt[j]] && mn[ch[j][1]] < j) res += id[ch[j][0]];
                }
                if (vis[ch[j][0]] && mn[ch[j][0]] >= j && !tp[vt[j]]) break;
                if (!on[ch[j][1]])
                {
                    if (!tp[vt[j]] && mn[ch[j][0]] < j) res += sum[ch[j][1]];
                    if (tp[vt[j]]) res += sum[ch[j][1]];
                }
                if (!tp[vt[j]] && on[ch[j][0]]) mx = max(mx, j);
                if (tp[vt[j]] && on[ch[j][1]]) mx = max(mx, j);
            }
            // cout << res << ' ';
            ans ^= res * i;
            for (int j = L; j <= R; j++) on[vt[j]] = 0;
            for (int j = 1; j <= tot[i]; j++) vis[vec[i][j]] = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}