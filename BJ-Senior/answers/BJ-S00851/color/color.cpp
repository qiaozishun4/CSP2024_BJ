#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 200005;
int n, a[N], col[N];
ll ans;

void dfs(int now){
    if (now > n){
        int l1 = 0, l2 = 0;
        ll res = 0;
        for (int i=1; i<=n; i++){
            if (col[i] == 1){
                if (!l1){l1 = i; continue;}
                if (a[i] == a[l1]) res += a[i];
                l1 = i;
            }
            if (col[i] == 2){
                if (!l2){l2 = i; continue;}
                if (a[i] == a[l2]) res += a[i];
                l2 = i;
            }
        }
        ans = max(ans, res);
        return;
    }
    col[now] = 1;
    dfs(now + 1);
    col[now] = 2;
    dfs(now + 1);
    col[now] = 0;
}

inline void solve1(){
    ans = 0;
    dfs(1);
    printf("%lld\n", ans);
}

inline void solve(){
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d", &a[i]);
    if (n <= 15){solve1(); return;}
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}
