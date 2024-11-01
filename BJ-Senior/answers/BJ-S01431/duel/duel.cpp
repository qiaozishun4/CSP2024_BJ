#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], tot, cur;

int main() {
    freopen("duel.in", "r", stdin);
    freopen("duel.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i-1]) { 
            tot = max(0, tot - cur);
            tot += cur;
            cur = 0;
        }
        cur++;
    }
    tot = max(0, tot - cur);
    tot += cur;
    printf("%d\n", tot);
    return 0;
}