#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define per(i,a,b) for (int i=(a);i>=(b);i--)
#define pll pair<ll,ll>
#define mkp make_pair
using namespace std;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
        {
            f=-1;
        }
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*f;
}
ll a[200005],n;
bool vis[200005],tvis[200005];
ll ans=0;
inline void dfs(ll x)
{
    if(x>n)
    {
        ll lst0=-1,lst1=-1;
        ll tot=0;
        rep(i,1,n)
        {
            if(vis[i])
            {
                if(a[i]==lst1)
                {
                    tot+=a[i];
                }
                lst1=a[i];
            }
            else
            {
                if(a[i]==lst0)
                {
                    tot+=a[i];
                }
                lst0=a[i];
            }
        }
        if(tot>ans)
        {
            ans=tot;
        }
        return ;
    }
    vis[x]=0;
    dfs(x+1);
    vis[x]=1;
    dfs(x+1);
}
ll f[200005];
vector<ll> g[1000005];
ll pre[200005],prk[200005];
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ll _=read();
    while(_--)
    {
        n=read();
        memset(f,0,sizeof(f));
        memset(pre,0,sizeof(pre));
        memset(vis,0,sizeof(vis));
        rep(i,1,1000000)
        {
            g[i].clear();
        }
        rep(i,1,n)
        {
            a[i]=read();
            g[a[i]].push_back(i);
        }
        ans=0;
        if(n<=15)
        {
            dfs(1);
            printf("%lld\n",ans);
            continue;
        }
        rep(i,1,n)
        {
            pre[i]=pre[i-1];
            if(a[i]==a[i-1])
            {
                pre[i]+=a[i];
            }
            f[i]=pre[i-1];
            prk[i]=0;
        }
        rep(i,2,n)
        {
            rep(j,1,i-1)
            {
                if(f[j]+pre[i-1]-pre[j]+(a[i]==a[j]?a[i]:0)>f[i])
                {
                    prk[i]=j;
                    f[i]=f[j]+pre[i-1]-pre[j]+(a[i]==a[j]?a[i]:0);
                }
            }
        }
        ll ans=pre[n];
        rep(i,1,n)
        {
            memset(vis,0,sizeof(vis));
            ll nn=i;
            while(nn)
            {
                vis[nn]=1;
                nn=prk[nn];
            }
            ll lst=0;
            ll jiafen=0;
            rep(j,1,n)
            {
                if(!vis[j])
                {
                    if(a[j]==lst)
                    {
                        jiafen+=a[j];
                    }
                    lst=a[j];
                }
            }
            ans=max(ans,f[i]+jiafen);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
