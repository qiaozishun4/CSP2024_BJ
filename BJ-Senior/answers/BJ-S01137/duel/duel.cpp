#include <bits/stdc++.h>
const int MAXN = 100005;
int n, a[MAXN];

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        int t;
        scanf("%d", &t);
        a[t]++;
    }
    int w = 100000;
    for(int i = 1; i <= w; ++i)
        a[i] += std::max(a[i - 1] - a[i], 0);
    printf("%d", a[w]);
    return 0;
}