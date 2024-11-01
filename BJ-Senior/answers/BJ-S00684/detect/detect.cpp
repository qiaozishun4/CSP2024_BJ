#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int T;
int n,m,len,limv;
struct nd
{
    int d,v,a;
    bool check(int p) const
    {
        long long v2=(long long)v*v+2ll*(p-d)*a;
        if(v2<0) return false;
        return v2>(long long)limv*limv;
    }
}a[N];
int p[N];
struct nd2
{
    int l,r;
    bool operator <(const nd2 &b) const
    {
        return l<b.l;
    }
}hav[N];
int cnt,ans;
void work(int id)
{
    int l=lower_bound(p+1,p+m+1,a[id].d)-p,r=m;
    if(l>r) return;
    if(a[id].a<=0)
    {
        if(!a[id].check(p[l])) return;
        int now=l;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(a[id].check(p[mid])) l=mid;
            else r=mid-1;
        }
        hav[++cnt]=(nd2){now,l};
        // printf("%d:%d %d\n",id,now,l);
    }
    else
    {
        if(!a[id].check(p[r])) return;
        int now=r;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(a[id].check(p[mid])) r=mid;
            else l=mid+1;
        }
        hav[++cnt]=(nd2){l,now};
        // printf("%d:%d %d\n",id,l,now);
    }
}
void init()
{
    cnt=0;
    ans=0;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&m,&len,&limv);
        init();
        for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].d,&a[i].v,&a[i].a);
        for(int i=1;i<=m;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) work(i);
        sort(hav+1,hav+cnt+1);
        int nowr=len;
        for(int i=1;i<=cnt;i++)
        {
            if(hav[i].l>nowr) ans++,nowr=len;
            nowr=min(nowr,hav[i].r);
        }
        if(cnt) ans++;
        printf("%d %d\n",cnt,m-ans);
    }
}