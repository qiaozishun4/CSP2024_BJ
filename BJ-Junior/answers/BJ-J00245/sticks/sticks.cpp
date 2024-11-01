#include <bits/stdc++.h>
using namespace std;
int solution[] = {-1, -1, 1, 7, 4, 2, 6};

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

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int t, n;
    t = read();
    while (t--) {
        n = read();
        if (n < 7) {
            printf("%d\n", solution[n]);
            continue;
        }
        if (n == 10) {
            printf("%d\n", 22);
            continue;
        }
        int k = n / 7, r = n % 7;
        if (r == 0) {
            for (int i = 0; i < k; i++) putchar('8');
        } else if (r == 1) {
            putchar('1'); putchar('0');
            for (int i = 0; i < k - 1; i++) putchar('8');
        } else if (r == 2) {
            putchar('1');
            for (int i = 0; i < k; i++) putchar('8');
        } else if (r == 3) {
            putchar('2'); putchar('0'); putchar('0');
            for (int i = 0; i < k - 2; i++) putchar('8');
        } else if (r == 4) {
            putchar('2'); putchar('0');
            for (int i = 0; i < k - 1; i++) putchar('8');
        } else if (r == 5) {
            putchar('2');
            for (int i = 0; i < k; i++) putchar('8');
        } else if (r == 6) {
            putchar('6');
            for (int i = 0; i < k; i++) putchar('8');
        }
        putchar('\n');
    }
    return 0;
}