#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005];
int dp[105][105][105];
int f[2005][2005];
int g[2005][2005];
int c[100005];
void solve(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    if(n<=15){
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    c[j+1]=1;
                }else{
                    c[j+1]=0;
                }
            }
            int lstr=0,lstb=0,res=0;
            for(int i=1;i<=n;i++){
                if(c[i]&&lstb==a[i]) res+=a[i];
                if(!c[i]&&lstr==a[i]) res+=a[i];
                if(c[i]) lstb=a[i];
                else lstr=a[i];
            }
            ans=max(ans,res);
        }
        printf("%lld\n",ans);
    }else if(n<=100){
         for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) for(int k=0;k<=n;k++){
            dp[i][j][k]=-0x3f3f3f3f;
        }
        dp[0][0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                for(int k=0;k<i;k++){
                    int cost=0;
                    if(a[i]==a[k]){
                        cost=a[k];
                    }
                    dp[i][j][i]=max(dp[i][j][i],dp[i-1][j][k]+cost);
                    cost=0;
                    if(a[i]==a[j]){
                        cost=a[j];
                    }
                    dp[i][i][k]=max(dp[i][i][k],dp[i-1][j][k]+cost);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                ans=max(ans,dp[n][i][j]);
            }
        }
        printf("%lld\n",ans);
    }else if(n<=2000){
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=g[i][j]=-0x3f3f3f3f;
        f[1][0]=0;
        for(int i=2;i<=n+1;i++){
            for(int j=0;j<max(1ll,i-1);j++){// i-1 is red j is blue
                int cost=0;
                if(a[i]==a[i-1]){
                    cost=a[i];
                }
                f[i][j]=max(f[i][j],f[i-1][j]);//i is red
                cost=0;
                if(a[i]==a[j]){
                    cost=a[i];
                }
                g[i][i-1]=max(g[i][i-1],f[i-1][j]+cost);//i is blue
            }
            for(int j=0;j<max(1ll,i-1);j++){// i-1 is blue ans j is red
                int cost=0;
                if(a[i]==a[i-1]){
                    cost=a[i];
                }
                g[i][j]=max(g[i][j],g[i-1][j]);//i is blue
                cost=0;
                if(a[i]==a[j]){
                    cost=a[i];
                }
                f[i][i-1]=max(f[i][i-1],g[i-1][j]+cost);//i is red
            }
        }
        int ans=0;
        for(int i=0;i<=n;i++){
            ans=max(ans,max(f[n+1][i],g[n+1][i]));
        }
        printf("%lld\n",ans);
    }
}
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%lld",&T);
    while(T--){
        solve();
    }
    return 0;
}