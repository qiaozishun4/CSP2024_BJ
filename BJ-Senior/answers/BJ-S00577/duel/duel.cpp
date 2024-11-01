#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define r register
using namespace std;

typedef long long l;
l a[100005];

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

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    r l n(read()), ans(0);
    for (r l i(1); i <= n; ++i) {
        a[i] = read();
    }
    sort(a + 1, a + n + 1);
    for (r l i(2), j(1); i <= n; ++i) {
        if (a[i] > a[j]) {
            ++ans;
            ++j;
        }
    }
    print(n - ans);
    return 0;
}
