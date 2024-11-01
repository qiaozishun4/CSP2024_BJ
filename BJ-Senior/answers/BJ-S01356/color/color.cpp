#ifndef COLOR_CPP_INCLUDED
#define COLOR_CPP_INCLUDED

#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int T, n;
int a[maxn];
int dp[maxn][2][2][2];
int pre[maxn][2][2];
int ans1 = 0, ans2 = 0;
void dfs(int i, int col, int j, int k){
    if(i == n){
        if(col == 0) ans1 = max(ans1, dp[n][0][j][k]);
        else ans2 = max(ans2, dp[n][1][j][k]);
        return;
    }
    dp[i+1][0][i][k] = max(dp[i+1][0][i][k], dp[i][0][j][k]+(a[i+1] == a[i])*a[i+1]);
    dfs(i+1, 0, i, k);
    dp[i+1][1][i][k] = max(dp[i+1][1][i][k], dp[i][0][j][k]+(a[i+1] == a[k])*a[i+1]);
    dfs(i+1, 1, i, k);
    dp[i+1][0][j][i] = max(dp[i+1][0][j][i], dp[i][1][j][k]+(a[j] == a[i+1])*a[i+1]);
    dfs(i+1, 0, j, i);
    dp[i+1][1][j][i] = max(dp[i+1][1][j][i], dp[i][1][j][k]+(a[i] == a[i+1])*a[i+1]);
    dfs(i+1, 1, j, i);
}
int main(){
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        ans1 = ans2 = 0;
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d", &a[i]);
        memset(dp, -0x3f3f3f3f, sizeof(dp));
        dp[1][0][0][0] = 0;
        dp[1][1][0][0] = 0;
        dfs(1, 0, 0, 0);
        memset(dp, -0x3f3f3f3f, sizeof(dp));
        dp[1][0][0][0] = 0;
        dp[1][1][0][0] = 0;
        dfs(1, 1, 0, 0);
        cout<<max(ans1, ans2)<<endl;
    }
    return 0;
}

#endif // COLOR_CPP_INCLUDED
