#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int n, a[N]; bool c[N]; ll ans, f[2005][2005];
void dfs(int x) {
    if(x == n + 1) {
        int pos[2] = {0, 0}; ll sum = 0;
        for(int i = 1; i <= n; i++) {
            if(pos[c[i]] && a[pos[c[i]]] == a[i]) sum += a[i];
            pos[c[i]] = i;
        }
        ans = max(ans, sum);
        return ;
    }
    c[x] = true; dfs(x + 1);
    c[x] = false; dfs(x + 1);
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        if(n > 15) {
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= n; j++)
                    f[i][j] = 0;
            for(int i = 2; i <= n; i++) {
                for(int j = 2; j <= i; j++) {
                    if(a[i] == a[i-1]) f[i][j] = f[i-1][j-1] + a[i];
                    else f[i][j] = f[i-1][j-1];
                }
                for(int k = 1; k < i - 1; k++) {
                    ll w = f[i-1][k];
                    if(a[i] == a[i-k-1]) w += a[i];
                    f[i][1] = max(f[i][1], w);
                }
            }
            ans = 0;
            for(int i = 1; i <= n; i++) ans = max(ans, f[n][i]);
            printf("%lld\n", ans);
            continue ;
        }
        ans = 0; dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}