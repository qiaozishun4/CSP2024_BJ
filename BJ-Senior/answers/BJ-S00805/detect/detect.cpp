#include <bits/stdc++.h>
using namespace std;
long long T;
long long n,m,l,v;
long long p[100005],q[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int d[100005];
    int v[100005];
    int a[100005];
    cin>>T;
    for (int i=1;i<=T;i++)
    {
        int num=0,ans=0;
        cin>>n>>m;
        for (int j=1;j<=n;j++)
        {
            cin>>d[j]>>v[j]>>a[j];//d->place, v->the begin velocity,a->acelaration
        }
        for (int j=1;j<=m;j++)
        {
            cin>>p[j];
        }
        for (int j=1;j<=n;j++)
        {
            for (int k=1;k<=m;k++)
            {
                if(p[k]==d[j])
                {
                    if (v[j]>m)
                    {
                        num++;
                        q[num]=k;
                        break;
                    }
                }
                else if(p[k]>d[j])
                {
                    if (v[j]*v[j] + 16*a[j] > 9)
                    {
                        num++;
                        q[num]=k;
                        break;
                    }
                }
            }
        }
        cout<<num<<" ";
        for (int j=1;j<=m;j++)
        {
            bool f=1;
            for (int k=1;k<=num;k++)
            {
                if (j==k)
                {
                    f=0;
                    break;
                }
            }
            if (f)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
