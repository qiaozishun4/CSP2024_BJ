#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int T,n,m;
ll L,V,d[maxn],v[maxn],a[maxn],sum[maxn],mx[maxn],p[maxn],f[maxn];
ll mn[maxn<<2],ans,num;
inline void pushup(int id)
{
    mn[id]=min(mn[id<<1],mn[id<<1|1]);
}
void update(int id,int l,int r,int x,ll w)
{
    if(l==r)
    {
        mn[id]=w;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) update(id<<1,l,mid,x,w);
    else update(id<<1|1,mid+1,r,x,w);
    pushup(id);
}
ll query(int id,int l,int r,int x,int y)
{
    if(l>=x && r<=y) return mn[id];
    int mid=(l+r)>>1;
    ll ret=1e18;
    if(x<=mid) ret=min(ret,query(id<<1,l,mid,x,y));
    if(y>mid) ret=min(ret,query(id<<1|1,mid+1,r,x,y));
    return ret;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--)
    {
        num=ans=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=0;i<=L;i++) sum[i]=0,mx[i]=-1;
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
            sum[p[i]]++;
        }
        for(int i=1;i<=L;i++) sum[i]+=sum[i-1];
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]>V && sum[L]-sum[d[i]-1]!=0) mx[L]=max(mx[L],d[i]),num++;
            }
            if(a[i]>0)
            {
                if(v[i]>V)
                {
                    if(sum[L]-sum[d[i]-1]!=0) mx[L]=max(mx[L],d[i]),num++;
                }
                else
                {
                    if(d[i]+(V*V-v[i]*v[i])/(2*a[i])+1<=L && sum[L]-sum[d[i]+(V*V-v[i]*v[i])/(2*a[i])]!=0)
                        mx[L]=max(mx[L],d[i]+(V*V-v[i]*v[i])/(2*a[i])+1),num++;
                }
            }
            if(a[i]<0)
            {
                if(v[i]>V && sum[min(L,d[i]+(v[i]*v[i]-V*V-2*a[i]-1)/(-2*a[i])-1)]-sum[d[i]-1]!=0)
                {
                    mx[min(L,d[i]+(v[i]*v[i]-V*V-2*a[i]-1)/(-2*a[i])-1)]=max(mx[min(L,d[i]+(v[i]*v[i]-V*V-2*a[i]-1)/(-2*a[i])-1)],d[i]);
                    num++;
                }
            }
        }
        for(int i=1;i<=L;i++) mx[i]=max(mx[i],mx[i-1]);
        p[0]=-1,f[0]=0;
        update(1,0,m,0,0);
        for(int i=1;i<=m;i++)
        {
            f[i]=query(1,0,m,lower_bound(p,p+m,mx[p[i]-1])-p,i-1)+1;
            update(1,0,m,i,f[i]);
            if(p[i]>=mx[L]) ans=max(ans,m-f[i]);
        }
        if(num==0) ans=m;
        cout<<num<<' '<<ans<<'\n';
    }
    return 0;
}
