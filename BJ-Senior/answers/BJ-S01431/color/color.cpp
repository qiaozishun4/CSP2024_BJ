#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 20 + 5;
int t, n;
int col[N], a[N], ans;

void dfs(int now) {
    if (now > n) {
        int las1 = 0, las0 = 0, cur = 0;
        for (int i = 1; i <= n; i++) {
            if (col[i]) {
                if (las1 == a[i]) 
                    cur += las1;
                las1 = a[i];
            } else {
                if (las0 == a[i]) 
                    cur += las0;
                las0 = a[i];
            }
        }
        ans = max(ans, cur);
        return;
    }
    col[now] = 1;
    dfs(now + 1);
    col[now] = 0;
    dfs(now + 1);
}

int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        ans = 0;
        scanf("%d", &n);
        if (n > 20) return 0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        dfs(1);
        printf("%d\n", ans);
    }
    return 0;
}