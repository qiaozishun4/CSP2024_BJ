#include <stdio.h>
#define gc() getchar()
int rd() {
    int x = 0;
    char c = gc();
    for (; c < '0' || c > '9'; c = gc());
    for (; c >= '0' && c <= '9'; c = gc())
        x = (x << 3) + (x << 1) + (c ^ '0');
    return x;
}
#define pc(c) putchar(c)
void wt(int x) {
    if (x >= 10) wt(x / 10);
    pc(x % 10 ^ '0');
}
#define N 100005
int n, a[N];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    n = rd();
    int V = 0;
    for (int i = 1, r; i <= n; i++) {
        r = rd();
        if (r > V) V = r;
        a[r]++;
    }
    int re = 0, mx = 0;
    for (int i = 1; i <= V; i++)
        if (a[i] > 0) {
            if (a[i] <= mx) re += a[i];
            else re += mx, mx = a[i];
        }
    wt(n - re), pc('\n');
    return 0;
}