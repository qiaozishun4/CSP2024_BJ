#include <bits/stdc++.h>
using namespace std;
int T,n;
long long f[514];
int main () {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    f[0] = 0;
    f[1] = 1e18;
    for (int i = 2;i <= 100;i++) {
        f[i] = 1e18;
        if (i >= 2 && f[i - 2] < 1e18) {
            f[i] = min(f[i],f[i - 2] * 10 + 1);
        }
        if (i >= 3 && f[i - 3] < 1e18) {
            f[i] = min(f[i],f[i - 3] * 10 + 7);
        }
        if (i >= 4 && f[i - 4] < 1e18) {
            f[i] = min(f[i],f[i - 4] * 10 + 4);
        }
        if (i >= 5 && f[i - 5] < 1e18) {
            f[i] = min(f[i],f[i - 5] * 10 + 2);
        }
        if (i >= 6 && f[i - 6] < 1e18) {
            f[i] = min(f[i],f[i - 6] * 10 + 0);
        }
        if (i >= 7 && f[i - 7] < 1e18) {
            f[i] = min(f[i],f[i - 7] * 10 + 8);
        }
        if (i == 6) {
            f[i] = 6;
        }
    }
    cin >> T;
    while (T--) {
        scanf("%d",&n);
        if (n == 1) {
            printf("-1\n");
            continue;
        }
        int cnt = n / 700 * 100;
        n = n % 700;
        while (n > 100) {
            n -= 7;
            cnt++;
        }
        printf("%lld",f[n]);
        for (int i = 1;i <= cnt;i++) {
            putchar('8');
        }
        putchar('\n');
    }
    return 0;
}