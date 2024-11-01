#include<bits/stdc++.h>
using namespace std;
long long t,n,no[1000005],a[1000005],dp[1000005],maxn[1000005],ans;
bool c[1000005];
inline void dfs(long long x){
    if(x==n+1){
        long long last[2]={0,0},sum=0;
        for(int b=1;b<=n;b++){
            if(last[c[b]]==no[b])sum=sum+no[b];
            else last[c[b]]=no[b];
        }
        ans=max(ans,sum);
        return;
    }
    c[x]=0;
    dfs(x+1);
    c[x]=1;
    dfs(x+1);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int b=1;b<=1000000;b++)maxn[b]=-b;
        long long sum=0;
        for(int b=1;b<=n;b++)scanf("%lld",&no[b]);
        if(n<=20){
            dfs(1);
            cout<<ans<<"\n";
            ans=0;
            continue;
        }
        for(int b=1;b<=n;b++){
            if(no[b]==no[b-1]){
                sum=sum+no[b];
                no[b-1]=0;
            }
        }
        long long m=0;
        for(int b=1;b<=n;b++)if(no[b])a[++m]=no[b];
        n=m;
        for(int b=1;b<=n;b++){
            dp[b]=maxn[a[b]]+a[b];
            if(a[b-1]==a[b+1])dp[b]=dp[b]+a[b-1];
            maxn[a[b]]=max(maxn[a[b]],dp[b]);
            ans=max(ans,dp[b]);
        }
        cout<<ans+sum<<"\n";
        ans=0;
    }
    return 0;
}
