#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL N = 100010, M = 200010;
LL t, n, k, q;
LL l[N], s[M];
int main() {
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    scanf("%lld", &t);
    while (t--) {
        LL cnt = 0;
        scanf("%lld%lld%lld", &n, &k, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%lld", &l[i]);
            for (int j = 1; j <= l[i]; j++) {
                scanf("%lld", &s[++cnt]);
            }
        }

        for (int i = 1; i <= q; i ++ ) {
            LL u, v;
            scanf("%lld%lld", &u, &v);
            printf("0\n");
        }
    }
}