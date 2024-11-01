#include<bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
int n,m,L,V,d[N],v[N],a[N],p[N];
struct nd
{
    int x,y;
};
struct seg
{
    int l,r;
}s[N],t[N],q;
nd mn(nd n1,nd n2)
{
    if(n1.x*n2.y>n1.y*n2.x)return n2;
    return n1;
}
bool cmp(seg n1,seg n2)
{
    if(n1.r!=n2.r)return n1.r<n2.r;
    return n1.l<n2.l;
}
void solve()
{
    scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
    q=(seg){-1,-1};
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
        if(a[i]==0)
        {
            if(v[i]>V)s[i]=(seg){d[i],L};
            else s[i]=q;
            continue;
        }
        if(a[i]>0)
        {
            if(v[i]>V)
            {
                s[i]=(seg){d[i],L};
                continue;
            }
            nd lc=(nd){V*V-v[i]*v[i]+2*a[i]*d[i],2*a[i]};
            if(lc.x>=L*lc.y)
            {
                s[i]=q;
                continue;
            }
            int k=lc.x/lc.y;
            if(lc.x%lc.y==0)k++;
            s[i]=(seg){k,L};
            continue;
        }
        if(v[i]<=V)
        {
            s[i]=q;
            continue;
        }
        nd lc=(nd){v[i]*v[i]-V*V-2*a[i]*d[i],-2*a[i]};
        lc=mn((nd){L+1,1},lc);
        int k=lc.x/lc.y;
        if(lc.x%lc.y==0)k--;
        s[i]=(seg){d[i],k};
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&p[i]);
    }
    sort(p+1,p+1+m);
    int res=0,cw=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i].l==-1)continue;
        int ll=1,rr=m,best=-1;
        while(ll<=rr)
        {
            int mid=(ll+rr)/2;
            if(p[mid]>=s[i].l)
            {
                best=mid;
                rr=mid-1;
            }
            else
            {
                ll=mid+1;
            }
        }
        if(best==-1)continue;
        int lll=1,rrr=m,bbest=-1;
        while(lll<=rrr)
        {
            int mid=(lll+rrr)/2;
            if(p[mid]<=s[i].r)
            {
                bbest=mid;
                lll=mid+1;
            }
            else
            {
                rrr=mid-1;
            }
        }
        if(best>bbest)continue;
        res++;
        t[++cw]=(seg){best,bbest};
    }
    printf("%lld ",res);
    sort(t+1,t+1+cw,cmp);
    int ans=0;
    for(int i=1;i<=cw;i++)
    {
        ans++;
        int j=i;
        while(j<cw&&t[j+1].l<=t[i].r)
        {
            j++;
        }
        i=j;
    }
    printf("%lld\n",m-ans);
}
signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    scanf("%lld",&T);
    while(T--)
    {
        solve();
    }
    return 0;
}