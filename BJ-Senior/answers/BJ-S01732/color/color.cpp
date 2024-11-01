#include <bits/stdc++.h>
using namespace std;

const int NR = 1e5 + 10;
int a[NR];

inline int read() {
    char c; int op, x;
    c = getchar();

    if (c == '-') op = -1, x = 0;
    else op = 1, x = c - '0';

    c = getchar();
    while (c != '\n' && c != ' ') {
        x = x * 10 + c - '0';
        c = getchar();
    }

    return op * x;
}

inline void print(int x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    int t = read();

    while (t--) {
        int n = read();
        for (int i = 1; i <= n; i++)
            a[i] = read();

        int ans = 0;
        for (unsigned i = 1; i <= 1 << n; i++) {
            int lstr = -1, lstb = -1, sum = 0;
            for (int j = 1; j <= n; j++)
                if ((1 << j) & i) {
                    if (lstr == a[j]) sum += a[j];
                    lstr = a[j];
                }
                else {
                    if (lstb == a[j]) sum += a[j];
                    lstb = a[j];
                }
            ans = max(ans, sum);
        }
        print(ans);
        printf("\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
