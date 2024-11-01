#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n;
int a[MAXN];
int sum[MAXN];
int dp[105][105][105];
int you[MAXN];
bool col[20];
int ans = 0;
void dfs(int now){
    if(now == n+1){
        vector<int> re,bl;
        for(int i = 1; i <= n; i++){
            if(col[i] == 1) re.emplace_back(i);
            else bl.emplace_back(i);
        }
        int sum = 0;
        for(int j = 1; j < re.size(); j++){
            if(a[re[j]] == a[re[j-1]]) sum += a[re[j]];
        }
        for(int j = 1; j < bl.size(); j++){
            if(a[bl[j]] == a[bl[j-1]]) sum += a[bl[j]];
        }
        ans = max(ans,sum);
        return ;
    }
    col[now] = 0;
    dfs(now+1);
    col[now] = 1;
    dfs(now+1);
}
void solve()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
    if(n <= 15){
        ans = 0;
        dfs(1);
        printf("%d\n",ans);
        return ;
    }
    for(int i = 1; i <= n; i++) sum[i] = 0;
    for(int i = 2; i <= n; i++){
        sum[i] = sum[i-1] + (a[i] == a[i-1] ? a[i] : 0);
    }
    memset(dp,0,sizeof(dp));
    dp[1][0][0] = 0;
    dp[2][1][0] = dp[2][0][1] = (a[1] == a[2] ? a[1] : 0);
    for(int i = 3; i <= n; i++){
        //dp[i][i-1][j] = (i,i-1) + dp[i-1][k][j]
        for(int j = 0; j < i-1; j++){
            int tmp = (a[i] == a[i-1] ? a[i] : 0);
            int maxn = 0;
            for(int k = 0; k < max(i-1,0); k++){
                if(j == k) continue;
                if(j == i-2 || k == i-2) maxn = max(maxn,dp[i-1][k][j]);
            }
            dp[i][i-1][j] = max(dp[i][i-1][j],tmp + maxn);
            tmp = (a[i] == a[j] ? a[i] : 0);
            maxn = 0;
            for(int k = 0; k < max(j-1,0); k++){
                if(j && (!(j-1) || k != j-1)) dp[i][i-1][j] = max(dp[i][i-1][j],tmp + sum[i-1] - sum[j+1] + dp[j][j-1][k] + (a[j+1] == a[j-1] ? a[j+1] : 0));
                if(j && (!(j-1) || k != j-1)) dp[i][i-1][j] = max(dp[i][i-1][j],tmp + sum[i-1] - sum[j+1] + dp[j][k][j-1] + (a[j+1] == a[k] ? a[j+1] : 0));
            }
        }

        for(int j = 0; j < i-1; j++){
            int tmp = (a[i] == a[i-1] ? a[i] : 0);
            int maxn = 0;
            for(int k = 0; k < max(i-1,0); k++){
                if(j == k) continue;
                if(j == i-2 || k == i-2) maxn = max(maxn,dp[i-1][j][k]);
            }
            dp[i][j][i-1] = max(dp[i][j][i-1],tmp + maxn);
            tmp = (a[i] == a[j] ? a[i] : 0);
            maxn = 0;
            for(int k = 0; k < max(j-1,0); k++){
                if(j && (!(j-1) || k != j-1)) dp[i][j][i-1] = max(dp[i][j][i-1],tmp + sum[i-1] - sum[j+1] + dp[j][k][j-1] + (a[j+1] == a[j-1] ? a[j+1] : 0));
                if(j && (!(j-1) || k != j-1)) dp[i][j][i-1] = max(dp[i][j][i-1],tmp + sum[i-1] - sum[j+1] + dp[j][j-1][k] + (a[j+1] == a[k] ? a[j+1] : 0));
            }
        }
    }
    ans = 0;
    for(int i = 0; i < n-1; i++) ans = max(ans,max(dp[n][n-1][i],dp[n][i][n-1]));
    printf("%d\n",ans);
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t; scanf("%d",&t);
    while(t--) solve();

    return 0;
}

