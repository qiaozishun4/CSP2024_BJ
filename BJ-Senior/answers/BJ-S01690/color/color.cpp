#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int a[20005],sum,ans;
int dp[2][20005][2];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--){
        ans=0;
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i%2][j][1]=dp[(i-1)%2][j][1];
                if(a[i]==a[i-1]){
                    dp[i%2][j][1]+=a[i];
                }
                if(a[i]==a[j]){
                    dp[i%2][i][1]=max(dp[(i-1)%2][j+1][0]+a[i],dp[i%2][i][1]);
                }else{
                    dp[i%2][i][1]=max(dp[(i-1)%2][j+1][0],dp[i%2][i][1]);
                }
                ans=max({ans,dp[i%2][j][1],dp[i%2][i][1]});
                //dp[(i-1)%2][j][1]=dp[i%2][j][1];
                //dp[(i-1)%2][i][1]=dp[i%2][i][1];
            }
            for(int j=1;j<i;j++){
                dp[i%2][j][0]=dp[(i-1)%2][j][0];
                if(a[i]==a[i-1]){
                    dp[i%2][j][0]+=a[i];
                }
                if(a[i]==a[j]){
                    dp[i%2][i][0]=max(dp[(i-1)%2][j+1][1]+a[i],dp[i%2][i][0]);
                }else{
                    dp[i%2][i][0]=max(dp[(i-1)%2][j+1][1],dp[i%2][i][0]);
                }
                ans=max({ans,dp[i%2][j][1],dp[i%2][i][1]});
                //dp[(i-1)%2][j][0]=dp[i%2][j][0];
                //dp[(i-1)%2][i][0]=dp[i%2][i][0];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
