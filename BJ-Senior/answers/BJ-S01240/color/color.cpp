#include <bits/stdc++.h>
using namespace std;
int T, n, a[200004];
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "r", stdout);
    scanf("%d", &T);
    while(T--) {
        int sum = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 0; i < (1 << n); i++) {
            int tmp = n + 1, tpp = n + 1, ans = 0;
            for(int j = 1; j <= n; j++) {
                if((i >> j - 1) & 1) {
                    if(a[j] == a[tmp]) ans += a[j];
                    tmp = j;
                } else {
                    if(a[j] == a[tpp]) ans += a[j];
                    tpp = j;
                }
            }
            sum = max(sum, ans);
        }
        printf("%d\n", sum);
    }
    return 0;
}
