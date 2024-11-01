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
ll n,m,L,V;
ll d[100005],v[100005],a[100005];
ll p[100005];
ll calcl(ll x)
{
    ll l=0,r=m+1;
    ll res=0;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(p[mid]>=x)r=mid-1,res=mid;
        else l=mid+1;
    }
    return res;
}
ll calcr(ll x)
{
    ll l=0,r=m+1;
    ll res=0;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(p[mid]<=x)l=mid+1,res=mid;
        else r=mid-1;
    }
    return res;
}
ll pl[100005];
void solve()
{
    n=read(),m=read(),L=read(),V=read();
    for(int i=1;i<=n;i++)d[i]=read(),v[i]=read(),a[i]=read();
    for(int i=1;i<=m;i++)p[i]=read();p[m+1]=L+1;
    ll cnt=0;
    for(int i=1;i<=n;i++)
    {
        ll l=-1,r=-1;
        if(v[i]>V&&a[i]>0)l=d[i],r=L;
        else if(a[i]>0)
        {
            ll p=(V*V-v[i]*v[i])/a[i]/2+1;
            if(p+d[i]<=L)l=p+d[i],r=L;
        }
        if(v[i]<=V&&a[i]<0)l=-1,r=-1;
        else if(a[i]<0)
        {
            ll p=(v[i]*v[i]-V*V-1)/(0-a[i])/2;
            l=d[i],r=min(L,d[i]+p);
        }
        if(a[i]==0)
        {
            if(v[i]>V)l=d[i],r=L;
            else l=-1,r=-1;
        }
        if(l==-1&&r==-1)continue;
        l=calcl(l),r=calcr(r);
        if(l>r||l>m||r<1)continue;
        pl[r]=max(pl[r],l);
        cnt++;
//        cout<<l<<' '<<r<<'\n';
    }
    ll res=0,lstp=0;
    for(int i=1;i<=m;i++)
    {
        if(pl[i]<=lstp)continue;
        res++;
        lstp=i;
    }
    cout<<cnt<<' '<<m-res<<'\n';
    for(int i=1;i<=m;i++)pl[i]=0;
    return;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll t=read();
    while(t--)solve();
    return 0;
}