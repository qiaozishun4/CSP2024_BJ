#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#define int long long
#define maxn 1000005

#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

#ifdef int
#define inf 0x3f3f3f3f3f3f3f3fll
#else
#define inf 0x3f3f3f3f
#endif

using namespace std;

int n, m, k, _a[maxn], a[maxn], c[maxn], N, l2[maxn], f[maxn], mk[maxn], sum[maxn], x[5], ans[maxn], fid[maxn], l2k[maxn], gp;

string s, t;

void find(int i = 1, int j = 1, int L = 1, int R = N) {
    // cout << "find " << x << ' ' << i << ' ' << L << ' ' << R << '\n';
    if(L == R) {
        fid[L] = j; return ;
    }
    int mid = (L + R) >> 1;
    find(i << 1, (j << 1) | (s[i] == '1'), L, mid);
    find((i << 1) + 1, (j << 1) | (s[i] == '0'), mid + 1, R);
}

inline void flush(int i) {
    int lch = (i << 1), rch = lch + 1;
    f[i] = (f[lch] & ~l2k[i]); sum[i] = sum[lch];
    if(f[lch] & l2k[i]) f[i] |= f[rch], sum[i] += sum[rch];
}

void remark(int i, int dep = 0) {
    int l = i, r = i + 1;
    while(l < N) l <<= 1, r <<= 1;
    int k = 1, lk = 0;
    for(int l0 = r - 1, r0 = r; l0 >= l; r0 = l0, l0 -= k, k <<= 1, lk++) {
        for(int i = l0; i < r0; i++) mk[i] = lk;
    }
}

void modify(int i, int a) {
    int id = i;
    i = fid[i];
    if(a == -1) {
        f[i] = (1 << 20) - 1;
        sum[i] = id;
    }
    else {
        f[i] = (1 << a);
        if(a >= mk[i]) sum[i] = id;
        else sum[i] = 0;
    }
    for(int j = i / 2; j >= gp; j >>= 1) {
        flush(j);
    }
}
void soft_modify(int i, int a) {
    int id = i;
    i = fid[i];
    if(a == -1) {
        f[i] = (1 << 20) - 1;
        sum[i] = id;
    }
    else {
        f[i] = (1 << a);
        if(a >= mk[i]) sum[i] = id;
        else sum[i] = 0;
    }
}

void dfs_flush(int x) {
    if((x << 1) < N) dfs_flush(x << 1), dfs_flush((x << 1) | 1);
    flush(x);
}

void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> _a[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    k = 0, N = 1;
    while(N < n) N <<= 1, k++;
    s = "";
    for(int i = 1; i <= k; i++) cin >> t, s = t + s;
    s = " " + s;
    find(1);
    for(int i = 1; i <= N; i++) l2k[i] = (1 << (k - l2[i])) - 1;
    int _; cin >> _; while(_--) {
        for(int i = 1; i <= N; i++) {
            f[fid[i]] = (1 << 20) - 1;
            sum[fid[i]] = i;
        }
        dfs_flush(1);
        cin >> x[0] >> x[1] >> x[2] >> x[3];
        int p = fid[1], k2 = 1;
        gp = p;
        remark(p);
        for(int i = 1; i <= n; i++) {
            if(i > k2) {
                k2 <<= 1, p >>= 1;
                gp = p;
                remark(p);
                for(int j = 1; j < i; j++) {
                    f[fid[j]] = (1 << a[j]);
                    if(a[j] >= mk[fid[j]]) sum[fid[j]] = j;
                    else sum[fid[j]] = 0;
                }
                dfs_flush(p);
            }
            a[i] = min(_a[i] ^ x[i & 3], 20ll);
            modify(i, a[i]);
            // cout << i << "gt" << p << '\n';
            ans[i] = sum[p];
        }
        int xum = 0;
        for(int i = 1; i <= m; i++) {
            xum ^= (i * ans[c[i]]);
            // cout << ans[i] << ' ';
        }
        cout << xum << '\n';
    }
}

signed main() {
    // int st = clock();
    fopen("arena");
    l2[0] = -1;
    for(int i = 1; i <= 1000000; i++) l2[i] = l2[i >> 1] + 1;
    ios::sync_with_stdio(false); cin.tie(0);
    int _; _ = 1; while(_--) work();
    // cout << 1.0 * (clock() - st) / CLOCKS_PER_SEC << '\n';
}