#include<iostream>
using namespace std;
long long a[200005],t[1000005],dp[200005],f[200005];
void solve(){
    long long n,num;
    scanf("%lld",&n);
    num=0;
    for(long long i=1;i<=1000005;i++) t[i]=0;
    for(long long i=1;i<=n;i++) dp[i]=0,f[i]=0;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        f[i]=t[a[i]];
        t[a[i]]=i;
    }
    for(long long i=2;i<=n;i++){
        dp[i-1]=dp[i-2];
        if(a[i]==a[i-1]) num+=a[i];
        else if(f[i]!=0){
            dp[i-1]=max(dp[i-1],dp[f[i]]+a[i]);
        }
    }
    long long ans=0;
    for(long long i=1;i<=n;i++) ans=max(ans,dp[i]);
    ans+=num;
    cout<<ans<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
