#include <stdio.h>
#define gc() getchar()
int rd() {
    int x = 0, f = 0;
    char c = gc();
    for (; c < '0' || c > '9'; c = gc())
        f ^= c == '-';
    for (; c >= '0' && c <= '9'; c = gc())
        x = (x << 3) + (x << 1) + (c ^ '0');
    return f ? -x : x;
}
#define pc(c) putchar(c)
void wt(int x) {
    if (x >= 10) wt(x / 10);
    pc(x % 10 ^ '0');
}
#define N 200005
int n, a[N], lst[2];
int cal1() { //n<=15
    int ans = 0;
    for (int x = 0; x < 1 << n; x++) {
        int sum = 0;
        lst[0] = lst[1] = 0;
        for (int i = 1; i <= n; i++) {
            int k = x >> i - 1 & 1;
            if (a[i] == lst[k]) sum += a[i];
            lst[k] = a[i];
        }
        if (sum > ans) ans = sum;
    }
    return ans;
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T = rd();
    while (T--) {
        n = rd();
        for (int i = 1; i <= n; i++)
            a[i] = rd();
        if (n <= 15) wt(cal1()), pc('\n');
        else wt(0), pc('\n');
    }
    return 0;
}