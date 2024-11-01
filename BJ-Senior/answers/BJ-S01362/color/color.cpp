#include <bits/stdc++.h>
#define MAXN 1000010
#define int long long
using namespace std;
int T,n,mx,a[MAXN],f[MAXN],buk[MAXN],c[MAXN],ta[MAXN],b[MAXN],dp[MAXN];
void add(int x,int v)
{
    if(!x) return;
    for(;x<=n;x+=x&-x) c[x]+=v;
}
int ask(int x)
{
    if(!x) return 0;
    int ans=0;
    for(;x;x-=x&-x) ans+=c[x];
    return ans;
}
signed main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin.sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        mx=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(buk,0,sizeof(buk));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            f[i]=buk[a[i]],buk[a[i]]=i;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[i-1]) b[i]=a[i];
            else b[i]=0;
        }
        for(int i=1;i<=n;i++) add(f[i],b[i]);
        for(int i=n;i>=1;i--) ta[i]=ask(n)-ask(f[i]),add(f[i],-b[i]);
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            if(f[i]) dp[i]=max(dp[i],ta[i]+a[i]+dp[f[i]+1]);
        }
        cout<<dp[n]<<'\n';
    }
    return 0;
}
