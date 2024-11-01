#include <bits/stdc++.h>
using namespace std;

int a[200005], dp[2][200005], pre[1000005];
long long ans;

void dfs(int i, int prer, int preb, int n, long long res){
    if(i == n+1){
        ans = max(ans, res);
        return;
    }
    dfs(i+1, i, preb, n, res+(a[i] == a[prer])*a[i]);
    dfs(i+1, prer, i, n, res+(a[i] == a[preb])*a[i]);
    return;
}

int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
            /*if(pre[a[i]] == 0){
                pre[a[i]] = i;
            }
            dp[0][i] = 0;
            dp[1][i] = 0;*/
        }
        ans = 0;
        dfs(1, 0, 0, n, 0LL);
        /*for(int i=1;i<=n;i++){
            if(pre[a[i]] == i){
                dp[1][i] = dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
            }else{
                dp[0][i] = max(dp[0][pre[a[i]]]+a[i], dp[1][pre[a[i]]]);
                dp[1][i] = max(dp[1][pre[a[i]]]+a[i], dp[0][pre[a[i]]]);
            }
            pre[a[i]] = i;
        }*/
        cout << ans << '\n';
    }
    return 0;
}