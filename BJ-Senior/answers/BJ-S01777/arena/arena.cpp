// 28pts
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
int n, m, a[N], _a[N], c[N], X[4], sim[19][N];
bitset<N> d[19];
namespace sub1 {
    bool chk(int x) {return (1 << __lg(x)) == x;}
    int Main(int len) {
        for (int i = 1; i <= len; i++) {
            sim[0][i] = i;
        }
        int i = 1;
        for (; len > 1; i++, len >>= 1) {
            for (int j = 1; j <= len / 2; j++) {
                if (d[i][j]) {
                    if (a[sim[i - 1][j << 1]] >= i) sim[i][j] = sim[i - 1][j << 1];
                    else sim[i][j] = sim[i - 1][(j << 1) - 1];
                } else {
                    if (a[sim[i - 1][(j << 1) - 1]] >= i) sim[i][j] = sim[i - 1][(j << 1) - 1];
                    else sim[i][j] = sim[i - 1][j << 1];
                }
            }
        }
        return sim[i - 1][1];
    }
}
namespace sub2 { // c <= 8
    int _l, ans;
    bool ok[11];
    void dfs(int u) {
        if (u > _l) {
            ok[sub1::Main(_l)] = 1;
            return;
        }
        for (int i = 0; i <= 3; i++) {
            a[u] = i; dfs(u + 1);
        }
    }
    int Main(int l) {
        _l = 1, ans = 0;
        while (_l < l) _l <<= 1;
        memset(ok, 0, sizeof(ok));
        dfs(l + 1);
        for (int i = 1; i <= _l; i++) {
            if (ok[i]) ans += i;
        }
        return ans;
    }
}
void slv() {
    for (int i = 0; i <= 3; i++) scanf("%d", &X[i]);
    for (int i = 1; i <= n; i++) {
        a[i] = _a[i] ^ X[i % 4];
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if (sub1::chk(c[i])) ans ^= (1ll * i * sub1::Main(c[i]));
        else if (c[i] <= 8) ans ^= (1ll * i * sub2::Main(c[i]));
    }
    printf("%lld\n", ans);
}
signed main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &_a[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
    }
    int K = __lg(n - 1) + 1;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= (1 << (K - i)); j++) {
            int x; scanf("%1d", &x);
            d[i][j] = (bool)x;
        }
    }
    int T; scanf("%d", &T);
    while (T--) slv();
    fclose(stdin), fclose(stdout);
    return 0;
}
/*
Hope the glorious CW/HoFr/SS can bless me!
No guafen and CW/HoFr/SS AK!
*/