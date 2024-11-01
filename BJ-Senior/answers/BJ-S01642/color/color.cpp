#include<bits/stdc++.h>
using namespace std;
#define int long long
using PII=pair<int,int>;
#define Set(x,y) memset(x,y,sizeof(x))
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define irep(i,x,y) for(int i=y;i>=x;--i)
#define File(str) \
    freopen(str".in","r",stdin);\
    freopen(str".out","w",stdout)
#define Dbg(fmt,...) \
    fprintf(stderr,"[%s:%d %s]" fmt "\n",__FILE__,__LINE__,__FUNCTION__,##__VA_ARGS__)
#define fi first
#define se second
#define pb push_back
#define TLC (double)clock()/CLOCKS_PER_SEC<0.91
const int N=2010,P=1e9+7;
int n,a[N],dp[N][N],dp1[N][N],s[N];
int Sum(int l,int r){
    return s[r]-s[l-1];
}
void Solve(){
    cin>>n;
    //if(n>2001) exit(0);
    rep(i,1,n)cin>>a[i],s[i]=s[i-1]+(a[i]==a[i-1])*a[i];
    Set(dp,0),Set(dp1,0);
    rep(i,1,n)
        rep(j,1,i-1){
            dp[i][j]=dp[j][i]=dp[i-1][j]+(a[i-1]==a[i])*a[i];
            if(j+2<=i-1)dp[i][j]=dp[j][i]=
                max(dp[i][j],dp[j+1][j]+Sum(j+2,i-1)+(a[j]==a[i])*a[i]);
        }
    int ans=0;
    rep(i,1,n)
        ans=max(ans,dp[n][i]);
    cout<<ans<<'\n';
}
main(){
    File("color");
    cin.tie(0)->sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
        Solve();
}
