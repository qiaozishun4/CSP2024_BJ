#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL N = 100010;
LL t, n;
LL a[30] = {0, -1, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108, 188, 200, 208, 288, 688, 888};
int main() {
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        if (n <= 21) printf("%lld", a[n]);
        else {
            LL v1, v2;
            if (n % 7) {
                v1 = n % 7 + 14;
                v2 = n / 7 - 2;
            } else {
                v1 = 21;
                v2 = n / 7 - 3;
            }

            printf("%lld", a[v1]);
            for (int i = 1; i <= v2; i ++ ) printf("8");
        }

        printf("\n");
    }
}