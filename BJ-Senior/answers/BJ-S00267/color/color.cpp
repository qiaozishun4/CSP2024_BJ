#include<bits/stdc++.h>
using namespace std;
long long n, a[100005], dis[100005], ans;
void dfs(long long step){
    if(step == n + 1){
        long long tot = 0;
        for(long long  i = 2; i <= n; i++){
            for(long long j = i - 1; j >= 1; j--){
                if(dis[i] == dis[j]){
                    if(a[i] == a[j]){
                        tot += a[i];
                    }
                }
            }
        }
        ans = max(ans, tot);
        return;
    }
    dis[step] = 1;
    dfs(step + 1);
    dis[step] = 2;
    dfs(step + 1);
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    long long t;
    scanf("%lld", &t);
    while(t--){
        n = 0;
        ans = 0;
        memset(a, 0, sizeof(a));
        memset(dis, 0, sizeof(dis));
        scanf("%lld", &n);
        for(long long i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
        }
        dfs(1ll * 1);
        printf("%lld\n", ans);
    }
    return 0;
}
