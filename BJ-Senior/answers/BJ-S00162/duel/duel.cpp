#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0;
    char c = getchar();
    bool f = 0;
    while (c < '0' || c > '9') f |= (c == '-'), c = getchar();
    while ('0' <= c && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
}
template <typename T> inline void write(const T &x) {
    if (x < 0) return write(-x);
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
const int N = 1e5 + 5;
int n, x, a[N], b[N];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    read(n);
    for (int i = 1; i <= n; i++) {
        read(x);
        a[x]++, b[x]++;
    }
    int j = 1;
    for (int i = 1; i <= 100000; i++) {
        while (j < i && a[i] >= b[j]) {
            a[i] -= b[j];
            b[j] = 0;
            j++;
        }
        if (j < i) b[j] -= a[i];
    }
    int ans = 0;
    for (int i = 1; i <= 100000; i++)
        ans += b[i];
    write(ans), putchar('\n');
    return 0;
}
