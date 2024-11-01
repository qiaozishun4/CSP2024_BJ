#include <bits/stdc++.h>

using i64 = long long;
auto& IG = std::ignore;

i64 n;

void solve(void) {
    IG = scanf("%lld", &n);
    if (n == 1) {
        puts("-1");
        return;
    }
    if (n == 2) {
        puts("1");
        return;
    }
    if (n == 3) {
        puts("7");
        return;
    }
    if (n == 4) {
        puts("4");
        return;
    }
    if (n == 5) {
        puts("2");
        return;
    }
    if (n == 6) {
        puts("6");
        return;
    }
    if (n % 7 == 0) {
        for (i64 i = 1; i <= n / 7; ++i) {
            printf("8");
        }
        puts("");
    }
    else if (n % 7 == 1) {
        printf("10");
        for (i64 i = 1; i < n / 7; ++i) {
            printf("8");
        }
        puts("");
    }
    else if (n % 7 == 2) {
        printf("1");
        for (i64 i = 1; i <= n / 7; ++i) {
            printf("8");
        }
        puts("");
    }
    else if (n % 7 == 3) {
        if (n == 10) {
            printf("22");
        }
        else {
            printf("200");
            for (i64 i = 1; i < n / 7 - 1; ++i) {
                printf("8");
            }
        }
        puts("");
    }
    else if (n % 7 == 4) {
        printf("20");
        for (i64 i = 1; i < n / 7; ++i) {
            printf("8");
        }
        puts("");
    }
    else if (n % 7 == 5) {
        printf("2");
        for (i64 i = 1; i <= n / 7; ++i) {
            printf("8");
        }
        puts("");
    }
    else if (n % 7 == 6) {
        printf("6");
        for (i64 i = 1; i <= n / 7; ++i) {
            printf("8");
        }
        puts("");
    }
}

int main() {
    IG = freopen("sticks.in", "r", stdin);
    IG = freopen("sticks.out", "w", stdout);

    i64 t = 0;
    IG = scanf("%lld", &t);
    while (t--) solve();

    return 0;
}
