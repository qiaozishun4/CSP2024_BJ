#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL N = 100010;
LL n;
LL a[N];
int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%lld", &n);
    for (int i = 1; i <= n; i ++ ) {
        scanf("%lld", &a[i]);
    } 

    sort(a + 1, a + n + 1);
    LL res = 0, cnt = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (i == 1 || a[i - 1] != a[i]) {
            cnt = 0;
        }

        cnt ++ ;
        res = max(res, cnt);
    }

    printf("%lld\n", res);
    return 0;
}