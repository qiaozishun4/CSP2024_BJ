#include <bits/stdc++.h>
typedef long long LL;
const int MAXN = 100005;
int n, m, k, w, tmp[MAXN*2], c[MAXN], d[MAXN*2], a[MAXN*2];
char str[MAXN];

namespace SubA {
    std::map<int, int> M;
    int A[MAXN*2];

    int solve(int N) {
        int K = 1, W = 0;
        while(K < N)
            K <<= 1, W++;
        for(int i = 1; i <= N; ++i)
            A[N + i - 1] = i;
        for(int i = W - 1; i >= 0; --i) {
            int p = (1 << i);
            for(int j = p; j < (p << 1); ++j) {
                int t = d[(1 << (i - W + w)) + j - p];
                A[j] = (a[A[j << 1 | t]] >= (W - i) ? A[j << 1 | t] : A[j << 1 | (t ^ 1)]);
            }
        }
        return A[1];
    }

    void solve() {
        M.clear();
        LL ans = 0;
        for(int i = 1; i <= m; ++i) {
            if(M.find(c[i]) == M.end())
                M[c[i]] = solve(c[i]);
            ans ^= 1LL*M[c[i]]*i;
            //printf("%d ", M[c[i]]);
        }
        printf("%lld\n", ans);
    }
}

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    bool flagA = true, flagB = false;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &tmp[i]);
    for(int i = 1; i <= m; ++i) {
        scanf("%d", &c[i]);
        if((c[i] & (c[i] - 1)) != 0)
            flagA = false;
    }
    k = 1, w = 0;
    while(k < n)
        k <<= 1, ++w;
    //printf("%d\n", k);
    for(int i = w - 1; i >= 0; --i) {
        int lim = (1 << (i + 1));
        scanf("%s", str);
        for(int j = 1 << i; j < lim; ++j)
            d[j] = str[j - (1 << i)] - '0';
    }
    int T;
    scanf("%d", &T);
    //printf("%d\n", T);
    while(T--) {
        int X[4];
        scanf("%d%d%d%d", &X[0], &X[1], &X[2], &X[3]);
        for(int i = 1; i <= n; ++i)
            a[i] = tmp[i] ^ X[i%4];
        if(flagA == true)
            SubA::solve();
    }
    return 0;
}