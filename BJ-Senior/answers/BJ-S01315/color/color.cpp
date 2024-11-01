#include <bits/stdc++.h>
using namespace std;
const int MAXN=105;
int t,n,a[MAXN],dp[MAXN][MAXN][MAXN];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int x=1;x<i;x++){
                for(int y=1;y<i;y++){
                    if(x==y) continue;
                    dp[i][x][y]=dp[i-1][x][y];
                    dp[i][x][i]=max(dp[i][x][i],dp[i-1][x][y]+(a[y]==a[i])*a[y]);
                    dp[i][i][y]=max(dp[i][y][i],dp[i-1][x][y]+(a[x]==a[i])*a[x]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans=max(ans,dp[n][i][j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
