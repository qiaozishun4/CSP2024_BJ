#include <bits/stdc++.h>
using namespace std;

int n, r[100005];

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

int main()
{
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    n = read();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int r = read();
        if (r == 2) cnt++;
    }
    printf("%d\n", max(n - cnt, cnt));
    return 0;
}