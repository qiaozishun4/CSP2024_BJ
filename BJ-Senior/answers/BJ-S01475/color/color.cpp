#include<bits/stdc++.h>
using namespace std;
long long t,n,a[200005],maxx=0,dp[105][105][105];
void gx(long long &x,long long y){
    if(x<y)x=y;
    maxx=max(maxx,x);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(long long i=1;i<=n;i++){
            cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
        dp[0][0][0]=0;
        for(long long i=1;i<=n;i++){
            for(long long j=0;j<=100;j++){
                for(long long k=0;k<=100;k++){
                    if(dp[i-1][j][k]!=-1){
                        if(a[i]==j)gx(dp[i][j][k],dp[i-1][j][k]+j),gx(dp[i][k][j],dp[i-1][j][k]+j);
                        if(a[i]==k)gx(dp[i][j][k],dp[i-1][j][k]+k),gx(dp[i][k][j],dp[i-1][j][k]+k);
                        gx(dp[i][a[i]][k],dp[i-1][j][k]);
                        gx(dp[i][k][a[i]],dp[i-1][j][k]);
                        gx(dp[i][a[i]][j],dp[i-1][j][k]);
                        gx(dp[i][j][a[i]],dp[i-1][j][k]);
                    }
                }
            }
        }
        cout<<maxx<<"\n";
        maxx=0;
    }
    return 0;
}
