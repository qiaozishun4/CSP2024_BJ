#include<bits/stdc++.h>
using namespace std;
long long d[200000],v[200000],a[200000],p[200000],k[4000][4000],n,m,kk[4000],y[4000];
double L,R;
void f(double x,double y,int j)
{
    for (int i=1;i<=m;i++)
    {
        if (p[i]<x)continue;
        if (p[i]>y)break;
        if (p[i-1]<x)L=i;
        if (p[i+1]>y)R=i;
        if (i==m)R=m;
        k[j][i]=1;
    }
    //cout << x << " " << y  << " " << L << " "  << R <<endl;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    long long t;
    cin >> t;
    for (int ii=1;ii<=t;ii++)
    {
        long long l,V,ans=0,ans2=0;
        cin >> n >> m >> l >>V;
        memset(k,0,sizeof(k));
        memset(y,0,sizeof(y));
        for (int i=1;i<=n;i++)cin >>d[i] >>v[i] >>a[i];
        for (int i=1;i<=m;i++)cin >> p[i];
        for (int j=1;j<=n;j++)
        {
            L=0;
            R=0;
            if (v[j]<=V && a[j]<=0)continue;
            if (v[j]>V && a[j]>0)
            {
                f(d[j],l,j);
            }
            if (v[j]<=V && a[j]>0)
            {
                double s=(V*V-v[j]*v[j])/2.0/a[j];
                f(d[j]+s+0.0001,l,j);
            }
            if (v[j]>V && a[j]==0)
            {
                f(d[j],l,j);
            }
            if (v[j]>V && a[j]<0)
            {
                double s=(V*V-v[j]*v[j])/2.0/a[j];
                f(d[j],d[j]+s-0.0001,j);
            }
            ans+=(R!=0);
            //cout  <<ans <<" ";
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                if (k[i][j])y[i]=1;
            }
        }
        for (int i=1;i<=m;i++)
        {
            memset(kk,0,sizeof(kk));
            int flag=1;
            for (int j=1;j<=m;j++)
            {
                if (i!=j)
                {
                    for (int i2=1;i2<=n;i2++)
                    {
                        if (k[i2][j])kk[i2]=1;
                    }
                }
            }
            for (int i=1;i<=n;i++)
            {
                if (kk[i]!=y[i])flag=0;
                //cout <<kk[i] << " ";
            }
            if (flag)
            {
                for (int j=1;j<=n;j++)
                {
                    k[j][i]=0;
                }
                ans2++;
            }
        }
        cout <<ans << " " << ans2 << endl;
    }
    return 0;
}
