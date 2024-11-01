#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define r register
using namespace std;

typedef long long l;
char c[200005];
l ans(0), a[200005], n;

inline l read() {
    r l x(0);
    r char ch;
    for (; !isdigit(ch); ch = getchar()) ;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    return x;
}

inline void print(r l x) {
    if (!x) putchar(48);
    r char out[21];
    r l len(0);
    while (x > 0) {
        out[++len] = x % 10 | 48;
        x /= 10;
    }
    while (len) putchar(out[len--]);
}

void work() {
    r l rl(0), bl(0), sum(0);
    for (r l i(1); i <= n; ++i) {
        if (c[i] == 'r') {
            if (a[i] == rl) {
                sum += a[i];
            }
            rl = a[i];
        } else {
            if (a[i] == bl) {
                sum += a[i];
            }
            bl = a[i];
        }
    }
    ans = max(ans, sum);
}

void choose(r l x) {
    if (x == n + 1) {
        work();
        return ;
    }
    c[x] = 'b';
    choose(x + 1);
    c[x] = 'r';
    choose(x + 1);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    r l t(read());
    while (--t > -1) {
        n = read();
        ans = 0;
        for (r l i(1); i <= n; ++i) {
            a[i] = read();
        }
        choose(1);
        print(ans);
        putchar(10);
    }
    return 0;
}
