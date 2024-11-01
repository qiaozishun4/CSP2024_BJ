#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int N = 2 * 1e5 + 3;
const int M = 1e6+3;
const int inf = 0x3f3f3f3f;
int T;
int a[N], p[N], dp[N], last[M], de[N];

int main() {

    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    scanf("%d", &T);
    while (T--) {

        memset(a, 0, sizeof a);
        memset(p, -1, sizeof p);
        memset(dp, 0, sizeof dp);
        memset(last, -1, sizeof last);
        memset(de, 0, sizeof de);

        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (last[a[i]] == -1) {
                last[a[i]] = i;
                dp[i] = dp[i - 1];
                continue;
            }
            if (last[a[i]] == i - 1) {
                last[a[i]] = i;
                ans += a[i];
                p[i] = p[last[a[i]]];
                continue;
            }
            if (p[last[a[i]]] == -1) {
                dp[i] = max(dp[i - 1], dp[last[a[i]] + 1] + a[i]);
            } else if (p[last[a[i]]] == 0) {
                int k = a[i] + (p[last[a[i]] + 1] > 0? dp[last[a[i]] + 1]: dp[last[a[i]]]);
                if (k > dp[i - 1]) {
                    dp[i] = k;
                    p[i] = 0;
                }
            } else {
                int k = a[i] + (p[last[a[i]] + 1] == 0? dp[last[a[i]] + 1]: dp[last[a[i]]]);
                if (k > dp[i - 1]) {
                    dp[i] = k;
                    p[i] = inf;
                }
            }
            last[a[i]] = i;
        }
        printf("%d", dp[n - 1] + ans);

    }

    return 0;
}
