#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int T,n,m,A[maxn],a[maxn];
int K,vv[4],c[maxn],d[22][maxn];
ll ans[maxn],prt;
int f[maxn][22],ht[maxn],kd[maxn],g[maxn][22];
void build(int id,int l,int r,int h,int w)
{
    ht[id]=h,kd[id]=d[h][w];
    if(l==r)
    {
        for(int i=0;i<=K;i++) f[id][i]=g[id][i]=l-1;
        if(a[l]<=K) g[id][a[l]]=1e9;
        for(int i=a[l];i<=K;i++) f[id][i]=1e9;
        return;
    }
    int mid=(l+r)>>1,s0=id<<1|(!kd[id]),s1=id<<1|kd[id];
    build(id<<1,l,mid,h-1,w*2-1);
    build(id<<1|1,mid+1,r,h-1,w*2);
    for(int i=h;i<=K;i++) g[id][i]=max(g[s1][i],min(g[s0][i],f[s1][h-1]));
    for(int i=0;i<h;i++) g[id][i]=min(g[s0][i],f[s1][h-1]);
    f[id][0]=g[id][0];
    for(int i=1;i<=K;i++) f[id][i]=max(f[id][i-1],g[id][i]);
}
inline int get_pos(int id,int pos)
{
    int ret=1<<K,fa;
    while(id!=1)
    {
        fa=id>>1;
        if((id&1)==kd[fa])
        {
            if(a[pos]<ht[fa]) ret=min(ret,pos-1);
        }
        else
        {
            ret=min(ret,f[fa<<1|kd[fa]][ht[fa]-1]);
        }
        id=fa;
    }
    return ret;
}
int main()
{
    char ch;
    int pos;
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>A[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    K=0;
    while((1<<K)<n) K++;
    for(int i=1;i<=K;i++)
        for(int j=1;j<=(1<<(K-i));j++)
        {
            cin>>ch;
            d[i][j]=ch-'0';
        }
    cin>>T;
    while(T--)
    {
        cin>>vv[0]>>vv[1]>>vv[2]>>vv[3];
        for(int i=1;i<=n;i++) a[i]=A[i]^vv[i%4];
        for(int i=0;i<=(1<<K);i++) ans[i]=0;
        ans[1]=1,prt=0;
        for(int p=1;p<=K;p++)
        {
            build(1,1,1<<p,p,1);
            for(int i=1;i<=(1<<p);i++)
            {
                pos=min(1<<p,get_pos((1<<p)-1+i,i));
                if(pos>(1<<(p-1))) ans[pos]+=i;
            }
            for(int i=(1<<p)-1;i>(1<<(p-1));i--) ans[i]+=ans[i+1];
        }
        for(int i=1;i<=m;i++) prt^=(i*ans[c[i]]);
        cout<<prt<<'\n';
    }
    return 0;
}
