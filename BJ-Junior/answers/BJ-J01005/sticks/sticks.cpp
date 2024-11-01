#include <cstdio>
using namespace std;
int t, n;
int nums[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int sticks_num(long long x) {
    int num = 0;
    while (x) {
        num += nums[x % 10];
        x /= 10;
    }
    return num;
}
int main () {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i < t; ++ i) {
        scanf("%d", &n);
        if (n % 7 == 0) {
            for (int j = 0; j < n / 7; ++ j) printf("8");
            printf("\n");
            continue;
        }
        if (n <= 1) {
            printf("-1\n");
            continue;
        }
        for (long long j = 0; j <= 888888888888888888;++ j) {
            if (sticks_num(j) == n) {
                printf("%d\n", j);
                break;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
