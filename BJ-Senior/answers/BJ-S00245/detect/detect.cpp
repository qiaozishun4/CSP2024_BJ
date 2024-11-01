#include<bits/stdc++.h>
using namespace std;
int n,m,l,vall;
int d[10005],v[10005],a[10005],p[10005];
int f[10005];
int g[10005],s[10005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int t;
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n>>m>>l>>vall;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>p[i];
        }
        for(int i=1;i<=n;i++)
        {
            f[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            g[i]=0;
        }
        int cnt=0,ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(d[j]>p[i]||v[j]<0)
                {
                    continue;
                }
                else
                {
                    double db=sqrt(v[j]*v[j]+2*a[j]*(p[i]-d[j]));
                    if(db>vall)
                    {
                        g[i]=1;
                        v[j]=0;
                        a[j]=0;
                        f[j]=1;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(f[i]==1)
            {
                cnt++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(g[i]==0)
            {
                ans++;
            }
        }
        cout<<cnt<<' '<<ans<<endl;
    }
    return 0;
}
