#include<bits/stdc++.h>
#define For(i,l,r) for(register int i=(l);i<=(r);++i)
#define For_down(i,r,l) for(register int i=(r);i>=(l);--i)
using namespace std;
const int n_MAX=200000+5;
int n,m,L,V,d[n_MAX],v[n_MAX],a[n_MAX],p[n_MAX];
bool ban[n_MAX];
inline long long mul(const int x,const int y)
{
    return ((long long)x*y);
}
inline bool check(const int i,const int j)
{
    if(p[j]<d[i]) return 0;
    const long long sum=(mul(v[i],v[i])+mul(a[i]*2,p[j]-d[i]));
    return (sum>mul(V,V));
}
int q;
struct range
{
    int l,r;
    inline bool operator < (const range &other) const
    {
        return (r<other.r);
    }
};
range c[n_MAX];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int T; cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V,q=0;
        For(i,1,n) cin>>d[i]>>v[i]>>a[i];
        For(i,1,m) cin>>p[i];
        int cnt=0,ans=m;
        For(i,1,n)
        {
            ban[i]=0;
            const int j=(lower_bound(p+1,p+m+1,d[i])-p);
            if(a[i]>=0) ban[i]=check(i,m);
            else if(a[i]<0) ban[i]=check(i,j);
            if(ban[i]) ++cnt;
        }
        For(i,1,n)
        {
            if(!ban[i]) continue;
            const int j=(lower_bound(p+1,p+m+1,d[i])-p);
            if(a[i]>=0)
            {
                int l=j,r=m;
                while(l<r)
                {
                    const int mid=((l+r)>>1);
                    if(check(i,mid)) r=mid;
                    else l=(mid+1);
                }
                c[++q]=(range){l,m};
            }
            else
            {
                int l=j,r=m;
                while(l<r)
                {
                    const int mid=((l+r+1)>>1);
                    if(check(i,mid)) l=mid;
                    else r=(mid-1);
                }
                c[++q]=(range){j,l};
            }
        }
        sort(c+1,c+q+1);
        int pre=0;
        For(i,1,q)
        {
            const int l=c[i].l;
            const int r=c[i].r;
            if(l<=pre) continue;
            pre=r,--ans;
        }
        cout<<cnt<<' '<<ans<<'\n';
    }
    return 0;
}