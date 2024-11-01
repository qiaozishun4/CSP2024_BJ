#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=300000+5;
int n,q,mem[n_MAX],a[n_MAX],c[n_MAX];
long long ans[n_MAX];
int inc[n_MAX];
char z[n_MAX];
string str[n_MAX];
int lv[n_MAX],H[4];
vector<int> vec[n_MAX];
long long tag[n_MAX];
int f[n_MAX],g[n_MAX];
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int init; cin>>init>>q;
    while((1<<n)<init) ++n;
    const int N=(1<<n);
    For(i,1,init) cin>>mem[i];
    For(i,1,q)
    {
        cin>>c[i];
        int k=0;
        while((1<<k)<c[i]) ++k;
        vec[k].push_back(i);
    }
    For(i,1,n) cin>>str[i];
    For_down(i,N-1,1)
    {
        lv[i]=(lv[i<<1]+1);
    }
    For(i,1,N-1)
    {
        z[i]=str[lv[i]][i-(1<<(n-lv[i]))];
    }
    int TT; cin>>TT;
    while(TT--)
    {
        For(i,0,3) cin>>H[i];
        For(i,0,N-1)
        {
            a[i+N]=min(20,mem[i]^H[(i+1)&3]);
            if(i>=init) a[i+N]=20;
        }
        For_down(i,N-1,1)
        {
            const int l=(i<<1),r=(i<<1|1);
            if(z[i]=='0')
            {
                a[i]=((a[l]>=lv[i])?a[l]:a[r]);
            }
            else
            {
                a[i]=((a[r]>=lv[i])?a[r]:a[l]);
            }
        }
        For(i,2,(N*2)-1)
        {
            const int Fa=(i>>1);
            if(i!=((Fa<<1)|(z[Fa]-'0')))
            {
                continue;
            }
            const int x=lv[Fa];
            int u=i,S=((1<<x)-1),L=0,R=0;
            bool flag=0;
            while(u<=(N-1))
            {
                const int l=(u<<1),r=(u<<1|1);
                const int y=lv[u];
                For(t,0,20)
                {
                    if(!(S&(1<<t))) continue;
                    if(z[u]=='0')
                    {
                        if(t>=y)
                        {
                            if(a[l]>=(t+1)) L|=((1<<t)|((1<<y)-1));
                            else if(a[l]==t) R|=((1<<21)-1);
                            else if(a[l]>=y) L|=((1<<t)|((1<<y)-1));
                            else R|=(1<<t);
                        }
                        else
                        {
                            if(a[l]>=y) L|=((1<<y)-1);
                            else R|=(1<<t);
                        }
                    }
                    else
                    {
                        if(t>=y)
                        {
                            if(a[l]==t) R|=(((1<<y)-1)|(1<<t));
                            else R|=(1<<t);
                        }
                        else
                        {
                            if(a[l]==t) R|=((1<<y)-1);
                            else L|=(1<<t);
                        }
                    }
                }
                if(R) u=r,S=R;
                else u=l,S=L,flag=1;
            }
            //if(u==512) printf("a[u] = %d\n",a[u]);
            if(!(S&(1<<a[u]))) --u,flag=1;
            if(flag) inc[i]=(u-N+1);
            else inc[i]=INT_MAX;
            //printf("inc[%d] = %d\n",i,inc[i]);
        }
        For(k,0,n)
        {
            int rt=(1<<(n-k));
            f[rt]=0,g[rt]=(1<<k);
            For_down(e,k,0)
            {
                const int ll=(1<<(n-e));
                const int rr=(ll+(1<<(k-e)));
                if(!e)
                {
                    For(i,0,1<<k) tag[i]=0;
                    For(u,ll,rr-1)
                    {
                        //printf("k = %2d , u = %2d : f = %2d , g = %2d\n",k,u,f[u],g[u]);
                        const int self=(((u-N+1)<=init)?a[u]:20);
                        if(self>=f[u])
                        {
                            tag[g[u]]+=(u-N+1);
                        }
                        else
                        {
                            tag[min(g[u],u-N)]+=(u-N+1);
                        }
                    }
                    For_down(i,1<<k,1) tag[i-1]+=tag[i];
                    for(const int i:vec[k])
                    {
                        ans[i]=tag[c[i]];
                    }
                    continue;
                }
                For(u,ll,rr-1)
                {
                    const int l=(u<<1),r=(u<<1|1);
                    if(z[u]=='0')
                    {
                        f[l]=max(f[u],lv[u]);
                        f[r]=f[u];
                        g[l]=g[u];
                        g[r]=min(g[u],inc[l]);
                    }
                    else
                    {
                        f[l]=f[u];
                        f[r]=max(f[u],lv[u]);
                        g[l]=min(g[u],inc[r]);
                        g[r]=g[u];
                    }
                }
            }
        }
        long long hash=0;
        For(i,1,q) hash^=(i*ans[i]);
        //For(i,1,q) printf("ans[%d] = %lld\n",i,ans[i]);
        cout<<hash<<'\n';
    }
    return 0;
}