#include<iostream>
using namespace std;
int main(int argc, char**argv)
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    int n,m,l,s;
    int d[100005],v[100005],a[100005],c[100005][100005]={0},b[100005];
    bool f=0;
    bool de=0;
    double x=0;
    int ans=0,keep=0;
    cin>>T;
    while(T>0)
    {
        T--;
        f=0;
        cin>>n>>m>>l>>s;
        for(int i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>b[i];
        }
        for(int i=1;i<=n;i++)
        {
            f=0;
            if(a[i]==0)
            {
                if(v[i]>s)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(b[j]>=d[i])
                        {
                            c[i][j]=1;
                        }
                    }
                    ans++;
                }
                else
                {
                    continue;
                }
            }
            if(a[i]>0)
            {
                if(v[i]>s)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(b[j]>=d[i])
                        {
                            c[i][j]=1;
                        }
                    }
                    ans++;
                }
                else
                {
                    x=(s*s-v[i]*v[i])/(2*a[i]);
                    for(int j=1;j<=m;j++)
                    {
                        if(b[j]>d[i]+x)
                        {
                            c[i][j]=1;
                            f=1;
                        }
                    }
                    if(f==1)
                    {
                        ans++;
                    }
                }
            }
            if(a[i]<0)
            {
                if(v[i]<=s)
                {
                    continue;
                }
                else
                {
                    x=(s*s-v[i]*v[i])/(2*a[i]);
                    for(int j=1;j<=m;j++)
                    {
                        if(b[j]>=d[i]&&b[j]<d[i]+x)
                        {
                            c[i][j]=1;
                            f=1;
                        }
                    }
                    if(f==1)
                    {
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
