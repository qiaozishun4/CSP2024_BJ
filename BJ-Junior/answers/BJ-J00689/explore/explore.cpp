#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#define r register
using namespace std;

typedef long long l;
l ax[] = {0, 1, 0, -1}, ay[] = {1, 0, -1, 0};

inline l read() {
    r l x(0);
    r char ch;
    for (; !isdigit(ch); ch = getchar()) ;
    for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
    return x;
}

inline void print(r l x) {
    if (!x) putchar(48);
    r char out[19];
    r l len(0);
    while (x != 0) {
        out[++len] = x % 10 + 48;
        x /= 10;
    }
    while (len) putchar(out[len--]);
}

int main() {
    freopen("explore.in", "r", stdin);
    freopen("explore.out", "w", stdout);
    r l t(read());
    while (--t > -1) {
        r l n(read()), m(read()), k(read()), x(read()), y(read()), d(read()), ans(0);
        r char a[1005][1005];
        r bool b[1005][1005];
        memset(b, 0, sizeof(b));
        b[x][y] = 1;
        for (r l i(1); i <= n; ++i) {
            for (r l j(1); j <= m; ++j) {
                cin >> a[i][j];
            }
        }
        while (--k > -1) {
            r l x2(x + ax[d]), y2(y + ay[d]);
            if (a[x2][y2] == 'x' || x2 < 1 || x2 > n || y2 < 1 || y2 > m) {
                d = (d + 1) % 4;
            } else {
                x = x2; y = y2;
                b[x][y] = 1;
            }
        }
        for (r l i(1); i <= n; ++i) {
            for (r l j(1); j <= m; ++j) {
                ans += b[i][j];
            }
        }
        print(ans);
        putchar(10);
    }
}
