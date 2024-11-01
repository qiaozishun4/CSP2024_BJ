#include <bits/stdc++.h>

using namespace std;

inline int read() {
    int x = 0, w = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 3) + (x << 1) + ch - '0'; ch = getchar(); }
    return x * w;
}

inline void write(int x) {
    if (x > 9)
        write(x / 10);

    putchar(x % 10 + '0');
}

int T;
int n;
int m;
int L;
int V;
int d[100005];
int v[100005];
int a[100005];
int p[100005];
int ans;

int f(int x) {
    int res = 0;

    while (x) {
        x &= x - 1;
        res++;
    }

    return res;
}

int main() {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    T = read();

    while (T--) {
        n = read(), m = read(), L = read(), V = read();

        for (int i = 1; i <= n; i++) {
            d[i] = read(), v[i] = read(), a[i] = read();
        }

        for (int i = 1; i <= m; i++) {
            p[i] = read();
        }
        if (n <= 20 && m <= 20) {
            int cnt = 0;

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (p[j] >= d[i]) {
                        if (v[i] * v[i] + 2 * a[i] * (p[j] - d[i]) >= 0) {
                            if (sqrt(v[i] * v[i] + 2 * a[i] * (p[j] - d[i])) > V) {
                                cnt++;
                                break;
                            }
                        }
                    }
                }
            }

            write(cnt);
            putchar(' ');

            int state = (1 << n);
            int t = 2147483647;

            for (int i = 0; i < state; i++) {
                int tmp = 0;

                for (int j = 1; j <= n; j++) {
                    for (int k = 1; k <= m; k++) {
                        if (i & (1 << (m - k))) {
                            if (p[k] >= d[j]) {
                                if (v[j] * v[j] + 2 * a[j] * (p[k] - d[j]) >= 0) {
                                    if (sqrt(v[j] * v[j] + 2 * a[j] * (p[k] - d[j])) > V) {
                                        tmp++;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }

                if (tmp == cnt) {
                    t = min(t, f(i));
                }
            }

            write(n - t);
            puts("");
        } else {
            ans = 0;

            for (int i = 1; i <= n; i++) {
                if (d[i] <= p[m]) {
                    if (sqrt(v[i] * v[i] + 2 * a[i] * (p[m] - d[i])) > V) {
                        ans++;
                    }
                }
            }

            write(ans);
            putchar(' ');
            write(m - (ans > 0));
            puts("");
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
