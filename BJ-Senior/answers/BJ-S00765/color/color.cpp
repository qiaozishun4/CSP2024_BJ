#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int long long
#define rep(i,n) for(int i=1;i<=n;++i)
#define reb(i,n) for(int i=0;i<n;++i)
#define pii pair<int,int>
#define X first
#define Y second
#define ld long double
using namespace std;
const int N=2e5+7,M=1e6+7;
int a[N],buc[M],dp[N][2][2],sum[N],n;
void cmax(int&a,int b){
    if(a<b)a=b;
}
int solve(){
    cin>>n;
    rep(i,n)dp[i][0][0]=dp[i][1][1]=dp[i][1][0]=dp[i][0][1]=0;
    reb(i,M)buc[i]=0;
    rep(i,n)cin>>a[i];
    buc[a[1]]=1;
    for(int i=2;i<=n;++i){
        if(a[i]==a[i-1])sum[i]=sum[i-1]+a[i];
        else sum[i]=sum[i-1];
        reb(col,2)
        reb(las,2)
        reb(hh,2)
        cmax(dp[i][col][las],dp[i-1][las][hh]);
        if(buc[a[i]]){
            // cout<<"jw "<<i<<'\n';
            if(a[i-1]==a[i]){
                reb(col,2)
                reb(ll,2){
                    cmax(dp[i][col][col],dp[i-1][col][ll]+a[i]);
                }
            buc[a[i]]=i;
                continue;
            }
            // cout<<"ihsduif "<<i<<"#"<<buc[a[i]]+1<<'\n';
            reb(col,2){
                int las=1-col;
                // cout<<col<<":"<<las<<'\n';
                // cout<<"!"<<dp[buc[a[i]]+1][las][col]<<'\n';
                cmax(dp[i][col][las],dp[buc[a[i]]+1][las][col]+a[i]+sum[i-1]-sum[buc[a[i]]]);
            }
        }
        buc[a[i]]=i;
    }
    int ans=0;
    reb(col,2)
    reb(p,2)ans=max(ans,dp[n][col][p]);
    // cout<<dp[5][1][0]<<'\n';
    cout<<ans<<'\n';
    return 0;
}
main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;while(T--)solve();
    return 0;
}