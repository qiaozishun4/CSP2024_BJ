#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int n;
int a[MAXN], f[MAXN], g[MAXN];

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i - 1; j++) {
            g[i] = max(g[i], f[j] + a[i + 1] * (a[i + 1] == a[j]));
            g[j] = max(g[j], f[j] + a[i + 1] * (a[i + 1] == a[i]));
        }
        for (int j = 0; j <= n; j++) {
            f[j] = g[j];
            g[j] = 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
    for (int i = 0; i <= n; i++) {
        f[i] = g[i] = 0;
    }
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T = 1;
    scanf("%d", &T);
    while (T--) solve();
}

// g++ color.cpp -o color -std=c++14 -static -O2 && ./color