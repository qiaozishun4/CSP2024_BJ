#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[200010],maxn[200010],dp[5][2010][2010];
signed main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            maxn[i]=0;
        }for(int i=1;i<=n;i++){
            cin>>a[i];
            maxn[i]=max(maxn[i-1],a[i]);
        }for(int i=0;i<=2;i++){
            for(int p=0;p<=2000;p++){
                for(int q=0;q<=2000;q++){
                    dp[i][p][q]=-1e12;
                }
            }
        }dp[0][0][0]=0;
        for(int i=1;i<=n;i++){
            for(int p=0;p<=maxn[i];p++){
                for(int q=0;q<=maxn[i];q++){
                    dp[i&1][a[i]][q]=max(dp[i&1][a[i]][q],dp[(i-1)&1][p][q]+(a[i]==p)*a[i]);
                    dp[i&1][p][a[i]]=max(dp[i&1][p][a[i]],dp[(i-1)&1][p][q]+(a[i]==q)*a[i]);
                }
            }for(int p=0;p<=2000;p++){
                for(int q=0;q<=2000;q++){
                    dp[(i-1)&1][p][q]=-1e12;
                }
            }
        }int ans=0;
        for(int i=0;i<=2000;i++){
            for(int j=0;j<=2000;j++){
                ans=max(ans,dp[n&1][i][j]);
            }
        }cout<<ans<<'\n';
    }
}