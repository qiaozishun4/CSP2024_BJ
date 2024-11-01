#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],b[100005],c[100005],d[100005],f[100005],e[100005],h[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ll t,n,m,l,v,j,s,ans,sum,k,g,i;
    cin>>t;
    while(t--)
    {
        ans=0;
        sum=0;
        k=0;
        memset(f,0,sizeof(f));
        memset(e,0,sizeof(e));
        cin>>n>>m>>l>>v;
        for(i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        for(i=1;i<=m;i++)
        {
            cin>>d[i];
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(a[j]>d[i]) continue;
                s=sqrt(b[j]*b[j]+2*c[j]*(d[i]-a[j]));
                a[j]=d[i];
                if(s>v)
                {
                    f[j]=1;
                    h[j]=i;
                }
            }
        }
        for(j=1;j<=n;j++)
        {
            if(f[j]==1) ans++;
        }
        cout<<ans<<" ";
        for(i=1;i<=m;i++)
        {
            g=sum;
            for(j=1;j<=n;j++)
            {
                if(f[j]==1&&e[j]==0&&h[j]==i)
                {
                    e[j]=1;
                    sum++;
                }
            }
            if(g==sum) k++;
        }
        cout<<k<<"\n";
    }
    return 0;
}
