#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m,L,V,d[100005],v[100005],a[100005],p[100005];
struct hi{ll l,r;}s[100005];
bool cmp(hi u,hi v)
{
    if(u.l==v.l) return u.r>v.r;
    return u.l<v.l;
}
ll lb(ll x)
{
    ll l=1,r=m,ret=-1;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(p[mid]>=x) ret=mid,r=mid-1;
        else l=mid+1;
    }
    return ret;
}
ll ub(ll x)
{
    ll l=1,r=m,ret=-1;
    while(l<=r)
    {
        ll mid=(l+r)>>1;
        if(p[mid]<=x) ret=mid,l=mid+1;
        else r=mid-1;
    }
    return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
    {
        cin>>n>>m>>L>>V;
        ll id=0,ans=0;
        for(ll i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
        for(ll i=1;i<=m;i++) cin>>p[i];
        sort(p+1,p+m+1);
        for(ll i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]<=V||d[i]>p[m]) continue;
                s[++id].l=lb(d[i]);
                s[id].r=m;
            }
            else if(a[i]<0)
            {
                if(v[i]<=V||d[i]>p[m]) continue;
                ll e=d[i]+1.0*(V*V-v[i]*v[i])/(2*a[i])-0.000000001;
                s[++id].r=ub(e);
                if(s[id].r==-1)
                {
                    id--;
                    continue;
                }
                if(p[s[id].r]<d[i])
                {
                    id--;
                    continue;
                }
                s[id].l=lb(d[i]);
            }
            else
            {
                if(d[i]>p[m]) continue;
                if(v[i]>V)
                {
                    s[++id].l=lb(d[i]);
                    s[id].r=m;
                    continue;
                }
                double e=d[i]+1.0*(V*V-v[i]*v[i])/(2*a[i])+0.000000001;
                ll x=e;
                if(x<e) x++;
                if(x>p[m]||x<d[i]) continue;
                s[++id].l=lb(x);
                s[id].r=m;
            }
        }
        sort(s+1,s+id+1,cmp);
        for(ll i=1;i<=id;i++)
        {
            ll r=s[i].r,mn=s[i].r;ans++;
            while(r>=s[i+1].l&&i<id&&s[i+1].l<=mn)
            {
                i++;
                mn=min(mn,s[i].r);
            }
        }
        cout<<id<<" "<<m-ans<<endl;
    }
	return 0;
}
