// 勤奋 求实 创造 奉献
// Luogu Coder12823
// 塞尔达是天

#include <bits/stdc++.h>
using namespace std;

int small_n_res[] = {-1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88};

int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        if (n < 15) {
            printf("%d\n", small_n_res[n - 1]);
            continue;
        }

        int op = n % 7, x = n / 7;;
        if (op == 1) {
            printf("10");
            for (int i = 2; i <= x; i++) {
                printf("8");
            }
            printf("\n");
        } else if (op == 2) {
            printf("1");
            for (int i = 1; i <= x; i++) {
                printf("8");
            }
            printf("\n");
        } else if (op == 3) {
            printf("200");
            for (int i = 3; i <= x; i++) {
                printf("8");
            }
            printf("\n");
        } else if (op == 4) {
            printf("20");
            for (int i = 2; i <= x; i++) {
                printf("8");
            }
            printf("\n");
        } else if (op == 5) {
            printf("2");
            for (int i = 1; i <= x; i++) {
                printf("8");
            }
            printf("\n");
        } else if (op == 6) {
            printf("6");
            for (int i = 1; i <= x; i++) {
                printf("8");
            }
            printf("\n");
        } else {
            printf("8");
            for (int i = 1; i <= x; i++) {
                printf("8");
            }
            printf("\n");
        }
    }

    return 0;
}

// C C F 快让我得 1=