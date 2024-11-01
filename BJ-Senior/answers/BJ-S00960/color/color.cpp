#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL N = 20;
LL t, n;
LL a[N];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%lld", &t);
    while (t -- ) {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i ++ ) {
            scanf("%lld", &a[i]);
        }

        LL res = 0;
        for (int i = 0; i < (1 << n); i ++ ) {
            LL val = 0, v1 = 0, v2 = 0;
            for (int k = 1; k <= n; k ++ ) {
                if (i & (1 << (k - 1))) {
                    if (v1 == a[k]) {
                        val += a[k];
                    }

                    v1 = a[k];
                } else {
                    if (v2 == a[k]) {
                        val += a[k];
                    }

                    v2 = a[k];
                }
            }

            res = max(res, val);
        }

        printf("%lld\n", res);
    }

    return 0;
}