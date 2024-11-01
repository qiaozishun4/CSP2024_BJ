#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,s;
int d[100005],v[100005],p[100005],a[100005];
bool vis[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>s;
        int maxn=-1;
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        memset(p,0,sizeof(p));
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        sort(p+1,p+1+n);
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]>s&&d[i]<=p[m])
                {
                    ans1++;
                    vis[m]=1;
                }
            }
            else
            {
                for(int j=m;j>=1;j--)
                {
                    if(p[j]<d[i])break;
                    int lon=p[j]-d[i];
                    long long num=v[i]*v[i]+2*a[i]*lon;
                    if(num<0)continue;
                    double xyz=sqrt(num);
                    if(num>s)
                    {
                        ans1++;
                        vis[j]=1;
                        break;
                    }
                }
            }
        }
        cout<<ans1<<" ";
        for(int i=1;i<=m;i++)
        {
            if(vis[i]==0)ans2++;
        }
        cout<<ans2<<endl;
    }
    return 0;
}
