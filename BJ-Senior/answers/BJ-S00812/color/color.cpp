#include<bits/stdc++.h>
using namespace std;
const int maxN=2020;
int a[maxN],dp[maxN][maxN][2];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0]=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j][0]=dp[i][j][1]=-1;
            }
        }
        dp[1][1][0]=dp[1][1][1]=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                int tmp0=0,tmp1=0,tmp2=0,tmp3=0;
                if(a[i+1]==a[i]) tmp0=tmp2=a[i+1];
                if(a[i+1]==a[i-j]) tmp1=tmp3=a[i+1];
                if(dp[i][j][0]!=-1){
                    dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][0]+tmp0);
                    dp[i+1][1][1]=max(dp[i+1][1][1],dp[i][j][0]+tmp1);
                }
                if(dp[i][j][1]!=-1){
                    dp[i+1][j+1][1]=max(dp[i+1][j+1][1],dp[i][j][1]+tmp2);
                    dp[i+1][1][0]=max(dp[i+1][1][0],dp[i][j][1]+tmp3);
                }
            }
        }
        for(int j=1;j<=n;j++){
            ans=max(ans,dp[n][j][0]);
            ans=max(ans,dp[n][j][1]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
