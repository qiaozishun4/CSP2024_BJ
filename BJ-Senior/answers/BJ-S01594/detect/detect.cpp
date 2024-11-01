#include <bits/stdc++.h>
using namespace std;
int d[100005],v[100005],a[100005],p[100005];
int key[100005],X,n,m,L,V,l[100005],r[100005],vis[100005];
bool dfs(int x)
{
    if(x==X+1)
    {
        for(int i=1;i<=n;i++)
        {
            if(l[i]==0) continue;
            bool flag=0;
            for(int j=l[i];j<=r[i];j++)
            {
                if(!vis[j])
                {
                    flag=1;
                    break;
                }
            }
            if(!flag) return 0;
        }
        return 1;
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans|=dfs(x+1);
            vis[i]=0;
        }
    }
    return ans;
}
bool check(int x)
{
    X=x;
    return dfs(1);
}
void solve()
{
    cin>>n>>m>>L>>V;
    for(int i=1;i<=n;i++) key[i]=l[i]=r[i]=0;
    for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
    for(int i=1;i<=m;i++) cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        int l=1,r=m;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(p[mid]>=d[i])
            {
                key[i]=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
    }
    int ans1=0;
    for(int i=1;i<=n;i++)
    {
        if(!key[i]) continue;
        double speed;
        if(a[i]<0)
        {
            int s=p[key[i]]-d[i];
            speed=sqrt(v[i]*v[i]+2*a[i]*s);
        }
        else if(a[i]>0)
        {
            int s=p[m]-d[i];
            speed=sqrt(v[i]*v[i]+2*a[i]*s);
        }
        else speed=v[i];
        if(speed>V) ans1++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!key[i]) continue;
        for(int j=key[i];j<=m;j++)
        {
            double speed;
            if(a[i]!=0)
            {
                int s=p[j]-d[i];
                if(s<0) continue;
                speed=sqrt(v[i]*v[i]+2*a[i]*s);
            }
            else speed=v[i];
            if(speed>V)
            {
                l[i]=j;
                break;
            }
        }
        for(int j=m;j>=key[i];j--)
        {
            double speed;
            if(a[i]!=0)
            {
                int s=p[j]-d[i];
                if(s<0) continue;
                speed=sqrt(v[i]*v[i]+2*a[i]*s);
            }
            else speed=v[i];
            if(speed>V)
            {
                r[i]=j;
                break;
            }
        }
    }
    int L=0,R=m,ans2=0;
    while(L<=R)
    {
        int mid=(L+R)/2;
        if(check(mid))
        {
            ans2=mid;
            L=mid+1;
        }
        else R=mid-1;
    }
    cout<<ans1<<" "<<ans2<<endl;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}
