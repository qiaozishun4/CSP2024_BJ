#include<bits/stdc++.h>
using namespace std;
//#define int long long
//#define endl '\n'
#define ll long long
const int INF =1e7+5;
int T,n;
const int MAXN =2e5+5;
int a[MAXN];
int dp[105][105][105];
int dp2[MAXN][11][11];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    //freopen("data.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];

        if(n<=100){

            for(int i=1;i<=n;i++)for(int j=0;j<=100;j++)for(int k=0;k<=100;k++)dp[i][j][k]=-INF;
            dp[1][a[1]][0]=0;
            dp[1][0][a[1]]=0;
            for(int i=2;i<=n;i++){
                for(int j=0;j<=100;j++){
                    for(int k=0;k<=100;k++){
                        if(dp[i-1][j][k]==-INF)continue;
                        dp[i][j][a[i]]=max(dp[i-1][j][k],dp[i][j][a[i]]);
                        dp[i][a[i]][k]=max(dp[i-1][j][k],dp[i][a[i]][k]);
                        if(j==a[i]){dp[i][a[i]][k]=max(dp[i-1][j][k]+a[i],dp[i][a[i]][k]);}
                        if(k==a[i]){dp[i][j][a[i]]=max(dp[i-1][j][k]+a[i],dp[i][j][a[i]]);}
                    }
                }
            }
            int ans =-INF;
            for(int i=0;i<=100;i++)for(int j=0;j<=100;j++)ans=max(ans,dp[n][i][j]);
            //for(int i=1;i<=n;i++)for(int j=0;j<=3;j++)for(int k=0;k<=3;k++)cout<<i<<' '<<j<<' '<<k<<' '<<dp2[i][j][k]<<endl;
            cout<<max(ans,0)<<endl;
        }
        else {

            for(int i=1;i<=n;i++)for(int j=0;j<=10;j++)for(int k=0;k<=10;k++)dp2[i][j][k]=-INF;
            dp2[1][a[1]][0]=0;
            dp2[1][0][a[1]]=0;
            for(int i=2;i<=n;i++){
                for(int j=0;j<=10;j++){
                    for(int k=0;k<=10;k++){
                        if(dp2[i-1][j][k]==-INF)continue;
                        dp2[i][j][a[i]]=max(dp2[i-1][j][k],dp2[i][j][a[i]]);
                        dp2[i][a[i]][k]=max(dp2[i-1][j][k],dp2[i][a[i]][k]);
                        if(j==a[i]){dp2[i][a[i]][k]=max(dp2[i-1][j][k]+a[i],dp2[i][a[i]][k]);}
                        if(k==a[i]){dp2[i][j][a[i]]=max(dp2[i-1][j][k]+a[i],dp2[i][j][a[i]]);}
                    }
                }
            }
            int ans =-INF;
            for(int i=0;i<=10;i++)for(int j=0;j<=10;j++)ans=max(ans,dp2[n][i][j]);
            //for(int i=1;i<=n;i++)for(int j=0;j<=3;j++)for(int k=0;k<=3;k++)cout<<i<<' '<<j<<' '<<k<<' '<<dp2[i][j][k]<<endl;
            cout<<max(ans,0)<<endl;
        }
    }
    return 0;
}
