#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128

const int N = 2e5 + 5;
int T, n, a[N], b[N];
ll ans;

void dfs(int u) {
    if(u == n+1) {
        int bl = 0, red = 0; ll res = 0;
        for(int i = 1; i <= n; i++) {
            if(b[i] == 0 && bl) res += (a[i] == a[bl] ? a[i] : 0);
            if(b[i] == 1 && red) res += (a[i] == a[red] ? a[i] : 0);
            if(b[i] == 0) bl = i;
            else red = i;
        }
        ans = max(ans, res); return;
    }
    b[u] = 0; dfs(u+1);
    b[u] = 1; dfs(u+1);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);

    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n); ans = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        if(n <= 27) {
            dfs(1);
            printf("%lld\n", ans);
        }
        else {
            for(int i = 2; i <= n; i++) ans += a[i];
            printf("%lld\n", ans);
        }
    }
    return 0;
}
