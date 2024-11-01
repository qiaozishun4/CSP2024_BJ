#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef int ll;
const ll inf=10000000;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline char getc()
{
    char ch=getchar();
    while(ch!='0'&&ch!='1'){ch=getchar();}
    return ch;
}
ll n,m,k;
ll tmp[200005],c[200005],a[200005];
ll X[4];
int ls[8000005],rs[8000005],id[8000005];
int px[8000005],py[8000005];
bool d[200005][20];
ll cntn;
void pushup(ll rt,ll dep)
{
    ll l=ls[rt],r=rs[rt];
    if(px[l]==-1&&px[r]==-1){px[rt]=-1,py[rt]=0;return;}
    if(!id[rt])
    {
        if(px[l]>=dep)
        {
            px[rt]=px[l];
            if(py[l]==inf)py[rt]=py[l];
            else py[rt]=(py[l]>=dep?py[l]:min(py[r],dep));
        }
        else
        {
            px[rt]=px[r];
            if(py[l]==inf)py[rt]=py[r];
            else py[rt]=(py[l]>=dep?min(py[l],py[r]):min(py[r],dep));
        }
    }
    else
    {
        if(px[r]>=dep)
        {
            px[rt]=px[r];
            if(py[r]==inf)py[rt]=py[r];
            else py[rt]=(py[r]>=dep?py[r]:min(py[l],dep));
        }
        else
        {
            px[rt]=px[l];
            if(py[r]==inf)py[rt]=py[l];
            else py[rt]=(py[r]>=dep?min(py[l],py[r]):min(py[l],dep));
        }
    }
}
void build(ll rt,ll l,ll r,ll dep,ll pid)
{
    px[rt]=-1,py[rt]=0,id[rt]=d[dep][pid];
    if(l==r){return;}
    ll mid=(l+r)>>1;
    ls[rt]=(++cntn),rs[rt]=(++cntn);
    build(ls[rt],l,mid,dep-1,pid<<1);
    build(rs[rt],mid+1,r,dep-1,pid<<1|1);
    pushup(rt,dep);
}
void update(ll rt0,ll rt,ll l,ll r,ll qx,ll val,ll dep)
{
    id[rt]=id[rt0];
    if(l==r)
    {
        px[rt]=val,py[rt]=inf;
        return;
    }
    ll mid=(l+r)>>1;
    if(qx<=mid)
    {
        ++cntn;
        ls[rt]=cntn,rs[rt]=rs[rt0];
        update(ls[rt0],ls[rt],l,mid,qx,val,dep-1);
    }
    if(mid+1<=qx)
    {
        ++cntn;
        ls[rt]=ls[rt0],rs[rt]=cntn;
        update(rs[rt0],rs[rt],mid+1,r,qx,val,dep-1);
    }
    pushup(rt,dep);
//    cout<<rt<<' '<<l<<' '<<r<<' '<<px[rt]<<' '<<py[rt]<<' '<<id[rt]<<'\n';
}
ll rtx[200005],ot;
bool get(ll rt,ll l,ll r,ll qx,ll val,ll dep)
{
    if(l==r)
    {
        return 1;
    }
    ll mid=(l+r)>>1;
    if(qx<=mid)
    {
        bool p=get(ls[rt],l,mid,qx,val,dep-1);
        if(p==0)return 0;
        if(!id[rt])return val>=dep;
        else
        {
            if(px[rs[rt]]!=-1&&px[rs[rt]]<dep)return 1;
            if(py[rs[rt]]!=inf&&py[rs[rt]]<dep)return 1;
            return 0;
        }
    }
    else
    {
        bool p=get(rs[rt],mid+1,r,qx,val,dep-1);
        if(p==0)return 0;
        if(id[rt])return val>=dep;
        else
        {
            if(px[ls[rt]]!=-1&&px[ls[rt]]<dep)return 1;
            if(py[ls[rt]]!=inf&&py[ls[rt]]<dep)return 1;
            return 0;
        }
    }
}
bool calc(ll t,ll x)
{
    ot=t;
    if(x<=t)
    {
        return get(rtx[t],1,n,x,a[x],k);
    }
    else
    {
        return get(rtx[t],1,n,x,inf-1,k);
    }
}
ll ans[200005],qa[200005];
void solve()
{
//    cout<<"qwq\n";
    for(int i=0;i<4;i++)X[i]=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=tmp[i]^X[i%4];
    }
//    for(int i=1;i<=n;i++)cout<<a[i]<<' ';cout<<'\n';
    cntn=0;
    rtx[0]=(++cntn);
    build(1,1,n,k,0);
    for(int i=1;i<=n;i++)
    {
        rtx[i]=(++cntn);
//        cout<<"qwq "<<i<<'\n';
        update(rtx[i-1],rtx[i],1,n,i,a[i],k);
    }
    ll rn=1;
    for(int i=1;i<=n;i++)
    {
        if(rn<i)rn<<=1;
        ll l=1,r=n,res=0;
        while(l<=r)
        {
            ll mid=(l+r)>>1;
            if(calc(mid,i))l=mid+1,res=mid;
            else r=mid-1;
        }
//        cout<<res<<' ';
        ll prn=rn/2+1;
        if(prn>res)continue;
        ans[prn]+=i,ans[res+1]-=i;
    }
    for(int i=1;i<=n;i++)qa[i]=qa[i-1]+ans[i];
    ll rres=0;
    for(int i=1;i<=m;i++)
    {
        rres^=(1ll*i*qa[c[i]]);
    }
    cout<<rres<<'\n';
    for(int i=1;i<=n;i++)ans[i]=0,qa[i]=0;
    return;
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)tmp[i]=read();
    for(int i=1;i<=m;i++)c[i]=read();
    ll rn=1;
    while(rn<n)rn<<=1,k++;
    n=rn;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j*(1ll<<i)<=n;j++)d[i][j-1]=getc()-'0';
    }
    ll t=read();
    while(t--)solve();
    return 0;
}