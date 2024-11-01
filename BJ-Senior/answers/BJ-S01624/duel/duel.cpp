#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 5;

int n, a[N], b[N], c[N], cnt;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (a[i] != a[i - 1]) {
            b[++cnt]++;
        } else b[cnt]++;
    }
    for (int i = 1; i <= cnt; ++i) {
        c[i] = c[i - 1] + b[i];
    }
    int t = 0;
    for (int i = 1; i <= cnt; ++i) {
        c[i - 1] -= t;
        if (c[i - 1] > b[i]) {
            t += b[i];
        } else {
            t += c[i - 1];
        }
    }
    printf("%d", n - t);
    return 0;
}