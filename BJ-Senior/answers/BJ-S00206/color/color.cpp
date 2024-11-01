#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, a[200005], color[200005];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f *= -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

signed main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int t = read();
    while (t--) {
        n = read();
        for (int i = 1; i <= n; i++) a[i] = read();
        int maxscore = 0;
        for (int i = 0; i < (1 << n); i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (i & (1 << j)) {
                    color[i] = 1;
                }
            }
            int score = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i - 1; j >= 1; j--) {
                    if (color[j] == color[i] && a[j] == a[i]) {
                        score += a[i];
                        break;
                    }
                }
            }
            maxscore = max(score, maxscore);
        }
        printf("%lld\n", maxscore);
    }
}