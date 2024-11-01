#include<bits/stdc++.h>
#define int long long
using namespace std;

int t,n,m,l,u;
int d[100005],v[100005],a[100005],p[100005],vis[100005];

int bs1(int x)
{
    int l=0,r=m,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(p[mid]<x)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}

int bs2(int x)
{
    int l=0,r=m,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(p[mid]<=x)
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
}

int bs3(int x)
{
    int l=0,r=m,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(p[mid]>=x)
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    return ans;
}

signed main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        int ans1=0,ans2=0;
        cin>>n>>m>>l>>u;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        p[0]=p[m];
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]<=u||d[i]>p[m])
                {
                    continue;
                }
                else
                {
                    ans1++;
                    if(!vis[m])
                    {
                        ans2++;
                        vis[m]=1;
                    }
                }
            }
            else if(a[i]<0)
            {
                if(v[i]<=u||d[i]>p[m])
                {
                    continue;
                }
                else
                {
                    int x=ceil(((u*u*1.0)-(v[i]*v[i]*1.0))/(2.0*a[i]));
                    if(x==0)
                    {
                        int y=bs2(d[i]);
                        if(p[y]==d[i])
                        {
                            ans1++;
                            if(!vis[y])
                            {
                                ans2++;
                                vis[y]=1;
                            }
                        }
                    }
                    else
                    {
                        x+=d[i];
                        if(x>p[m])
                        {
                            ans1++;
                            if(!vis[m])
                            {
                                ans2++;
                                vis[m]=1;
                            }
                        }
                        else
                        {
                            int y=bs1(x);
                            bool fa=true;
                            for(int j=bs3(d[i]);j<=y;j++)
                            {
                                if(vis[j])fa=false;
                            }
                            if(y!=0&&p[y]>=d[i])
                            {
                                ans1++;
                                if(fa)
                                {
                                    ans2++;
                                    vis[y]=1;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                int x=floor(((u*u*1.0)-(v[i]*v[i]*1.0))/(2.0*a[i]));
                x+=d[i];
                if(x>=p[m]||d[i]>p[m])
                {
                    continue;
                }
                else
                {
                    ans1++;
                    if(!vis[m])
                    {
                        ans2++;
                        vis[m]=1;
                    }
                }
            }
        }
        ans2=m-ans2;
        cout<<ans1<<" "<<ans2<<endl;
    }
}
