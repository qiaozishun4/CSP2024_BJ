#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lson (i << 1)
#define rson (i << 1 | 1)
#define SZ(x) ((int)(x).size())
const int maxn = 2e5 + 10;
const int L = 20;
int n, m, a[maxn], c[maxn], d[L][maxn], K, T, Y[4], X[4];
struct Node {
    vector<int> ids;
    int st;
} f[L][maxn];
ll solve() {
    ll ans = 0, rnd, tot;
    //printf("Hello\n");
    //return 0;
    for (ll g = 1; g <= m; g++) {
        for (rnd = 0; (1 << rnd) < c[g]; rnd++);
        tot = (1 << rnd);
        //printf("%d %lld %lld\n", c[g], rnd, tot);
        //return 0;
        for (int i = 0; i < tot; i++) {
            if (i < c[g]) f[0][i].ids = vector<int>(1, i), f[0][i].st = -1;
            else f[0][i].ids = vector<int>(), f[0][i].st = i;
        }
        for (int r = 1; r <= rnd; r++) {
            for (int i = 0; i < (1 << (rnd - r)); i++) {
                f[r][i].ids.clear();
                f[r][i].st = -1;
                if (d[r][i]) {
                    for (int x : f[r - 1][rson].ids) if (a[x] >= r) f[r][i].ids.push_back(x);
                    f[r][i].st = f[r - 1][rson].st;
                    if (f[r][i].st != -1 || SZ(f[r][i].ids) != SZ(f[r - 1][rson].ids)) {
                        for (int x : f[r - 1][lson].ids) f[r][i].ids.push_back(x);
                        if (f[r - 1][lson].st != -1) f[r][i].st = f[r - 1][lson].st;
                    }
                } else {
                    for (int x : f[r - 1][lson].ids) if (a[x] >= r) f[r][i].ids.push_back(x);
                    f[r][i].st = f[r - 1][lson].st;
                    if (f[r][i].st != -1 || SZ(f[r][i].ids) != SZ(f[r - 1][lson].ids)) {
                        for (int x : f[r - 1][rson].ids) f[r][i].ids.push_back(x);
                        if (f[r][i].st == -1) f[r][i].st = f[r - 1][rson].st;
                    }
                }
            }
        }
        ll sum = 0;
        for (int x : f[rnd][0].ids) sum += x + 1;
        if (f[rnd][0].st != -1) sum += ((ll)f[rnd][0].st + 1 + tot) * ((ll)tot - f[rnd][0].st) / 2;
        ans ^= sum * g;
    }
    return ans;
}
int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie();
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> c[i];
    for (K = 0; ; K++) if ((1 << K) >= n) break;
    for (int i = 1; i <= K; i++) {
        string s; cin >> s;
        for (int j = 0; j < 1 << (K - i); j++) d[i][j] = s[j] == '1';
    }
    cin >> T;
    memset(Y, 0, sizeof(Y));
    //cout << "here\n";
    //cout << "T:" << T << "\n";
    while (T--) {
        for (int i = 0; i < 4; i++) cin >> X[(i + 3) & 3];
        for (int i = 0; i < n; i++) a[i] = (a[i] ^ X[i & 3] ^ Y[i & 3]);
        cout << solve() << "\n";
        memcpy(Y, X, sizeof(X));
    }
    return 0;
}
