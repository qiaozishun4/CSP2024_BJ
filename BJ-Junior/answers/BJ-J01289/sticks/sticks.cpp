#include<bits/stdc++.h>
using namespace std;
int t, n;
int a[60] = {-1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888, 1088, 1888, 2008, 2088, 2888, 6888, 8888, 10888, 18888, 20088, 20888, 28888, 68888, 88888, 108888, 188888, 200888, 208888, 288888, 688888, 888888, 1088888, 1888888, 2008888, 2088888, 2888888, 6888888, 8888888, 10888888, 18888888, 20088888, 20888888, 28888888, 68888888, 88888888};
int main() {
    freopen("sticks.out", "w", stdout);
    freopen("sticks.out", "r", stdin);
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if (n % 7 == 0) {
            for (int i = 0; i < n / 7; i++) printf("8");
            printf("\n");
        } else if (n % 7 == 1) {
            printf("10");
            n -= 8;
            for (int i = 0; i < n / 7; i++) printf("8");
            printf("\n");
        } else if (n <= 56) {
            printf("%d\n", a[n]);
        }
    }
    return 0;
}