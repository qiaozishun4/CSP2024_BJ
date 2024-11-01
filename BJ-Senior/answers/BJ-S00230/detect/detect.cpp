#include<bits/stdc++.h>
using namespace std;
long long n,m,L,V,p[100010],len,mmax,flg1,flg2;//flg1:a=0,flg2:a>0
struct node
{
    long long d,v,a;
}c[100010];
struct node2
{
    int l,r;
}bian[100010];
bool cmp(node2 x,node2 y)
{
    if(x.l!=y.l) return x.l<y.l;
    else return x.r>y.r;
}
bool check(int mid,int x)
{
    if(p[mid]<c[x].d) return 0;
    long long s1=(p[mid]-c[x].d)*2*c[x].a,s2=V*V-c[x].v*c[x].v;
    if(s2<s1) return 1;
    else return 0;
}
bool Find(int x)
{
    if(c[x].a>0)
    {
        if(p[m]<c[x].d) return 0;
        long long s1=(p[m]-c[x].d)*2*c[x].a,s2=V*V-c[x].v*c[x].v;
        if(s2>=s1) return 0;
        else
        {
            mmax=1;
            return 1;
        }
    }
    else if(c[x].a==0)
    {
        if(p[m]>=c[x].d&&c[x].v>V) return 1;
        else return 0;
    }
    else
    {
        if(c[x].v<=V) return 0;
        int l=upper_bound(p+1,p+m+1,c[x].d)-p,r=m,t=-1;
        if(p[l]<c[x].d) return 0;
        if(c[x].d==p[l]) return 1;
        int ll=l;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid,x)==1&&mid<=m)
            {
                t=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        if(t==-1||check(t,x)==0)
        {
            return 0;
        }
        else
        {
            if(t!=m)
            {
                len++;
                bian[len].l=ll;
                bian[len].r=t;
            }
            else
            {
                mmax=1;
            }
            return 1;
        }
    }
}
bool pd(int LL,int RR,int lll,int rrr)
{
    if(LL<=lll&&rrr<=RR) return 1;
    else return 0;
}
void solve()
{
    int ans=0;
    memset(p,0,sizeof(p));
    mmax=0;len=0;flg1=1;flg2=1;
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;++i)
    {
        cin>>c[i].d>>c[i].v>>c[i].a;
        if(c[i].a!=0) flg1=0;
        if(c[i].a<0) flg2=0;
    }
    for(int i=1;i<=m;++i)
    {
        cin>>p[i];
    }
    sort(p+1,p+m+1);
    for(int i=1;i<=n;++i)
    {
        if(Find(i))
        {
            ans++;
        }
    }
    if(ans==0)
    {
        cout<<ans<<' '<<m<<endl;
        return ;
    }
    if(flg1)
    {
        cout<<ans<<' '<<m-1<<endl;
        return ;
    }
    if(flg2)
    {
        cout<<ans<<' '<<m-1<<endl;
        return ;
    }
    if(len==0)
    {
        cout<<ans<<' '<<m-mmax<<endl;
    }
    else
    {
        sort(bian+1,bian+len+1,cmp);
        int s=bian[1].l,t=bian[1].r;
        mmax++;
        for(int i=2;i<=len;++i)
        {
            if(pd(s,t,bian[i].l,bian[i].r))
            {
                s=max(s,bian[i].l);
                t=min(t,bian[i].r);
            }
            else
            {
                mmax++;
                s=bian[i].l;
                t=bian[i].r;
            }
        }
        cout<<ans<<' '<<m-mmax<<endl;
    }
    return ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
