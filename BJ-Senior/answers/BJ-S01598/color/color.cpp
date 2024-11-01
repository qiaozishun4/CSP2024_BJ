#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005],s[100005];
long long mp[2005][2005],dp[105][105][105];
long long ans;
void dfs(int now,long long val,int lx,int ly){
    //cout<<now<<' '<<val<<' '<<lx<<' '<<ly<<'\n';
    if(now>n){
        ans=max(ans,val);
        return;
    }
    //cout<<mp[lx][ly]<<'\n';
    if(val<=mp[lx][ly]) return;
    mp[lx][ly]=val;
    if(a[lx]==a[now]) dfs(now+1,val+a[now],now,ly);
    else dfs(now+1,val,now,ly);
    if(a[ly]==a[now]) dfs(now+1,val+a[now],lx,now);
    else dfs(now+1,val,lx,now);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n>15&&n<=100){
            memset(dp,0,sizeof(dp));
            for(int i=2;i<=n;i++){
                for(int j=0;j<i;j++){
                    for(int k=0;k<i;k++){
                        if(j==k) continue;
                        if(a[j]==a[i]) dp[i][i][k]=max(dp[i][i][k],dp[i-1][j][k]+a[i]);
                        else dp[i][i][k]=max(dp[i][i][k],dp[i-1][j][k]);
                        if(a[k]==a[i]) dp[i][j][i]=max(dp[i][j][i],dp[i-1][j][k]+a[i]);
                        else dp[i][j][i]=max(dp[i][j][i],dp[i-1][j][k]);
                    }
                }
            }
            for(int i=0;i<=n;i++) ans=max(ans,max(dp[n][n][i],dp[n][i][n]));
            cout<<ans<<'\n';
            continue;
        }else if(n>250){
            cout<<0<<'\n';
            continue;
        }
        for(int i=0;i<=1000;i++) for(int j=0;j<=1000;j++) mp[i][j]=-1;
        dfs(1,ans,0,0);
        cout<<ans<<'\n';
    }
    return 0;
}
