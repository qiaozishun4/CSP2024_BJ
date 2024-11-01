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
int a[200005];

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    T = read();

    while (T--) {
        n = read();

        for (int i = 1; i <= n; i++)
            a[i] = read();

        int state = (1 << n);
        int ans = 0;

        for (int i = 0; i < state; i++) {
            int ans2 = 0;

            for (int j = 1; j <= n; j++) {
                bool color = i & (1 << (n - j)), flag = 0;
                int tmp = 0;

                for (int k = 1; k < j; k++) {
                    if (color == ((i & (1 << (n - k))) >> (n - k))) {
                        flag = 1;
                        tmp = k;
                    }
                }

                if (flag && a[tmp] == a[j]) {
                    ans2 += a[j];
                }
            }

            ans = max(ans, ans2);
        }

        write(ans);
        puts("");
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
