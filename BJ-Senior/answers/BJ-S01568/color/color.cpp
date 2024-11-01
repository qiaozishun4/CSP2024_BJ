#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n;
ll a[200005];
ll pre[1000005],prec[1000005];
ll dp[200005];
void solve()
{
    ll n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
        pre[i]=prec[a[i]];
        prec[a[i]]=i;
    }
    ll maxdp=0;
    ll res=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        dp[i-1]=maxdp;
        if(pre[i])dp[i-1]=max(dp[i-1],dp[pre[i]]+a[i]);
        if(a[i]==a[i-1])dp[i-1]-=a[i],res+=a[i];
        maxdp=max(maxdp,dp[i-1]);
    }
    for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
    cout<<ans+res<<'\n';
    for(int i=1;i<=n;i++)prec[a[i]]=0,a[i]=dp[i]=pre[i]=0;
    return;
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll t=read();
    while(t--)solve();
    return 0;
}