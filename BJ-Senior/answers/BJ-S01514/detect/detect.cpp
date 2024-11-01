#include <iostream>
using namespace std;
long long t,n,m,L,V,d[1000005],v[1000005],a[1000005];
long long p[1000005],c[1000005],sum=0;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin >>t;
    for(long long k=1;k<=t;k++)
    {
        cin >>n>>m>>L>>V;
        for (long long  i=1;i<=m;i++)
        {
           cin >>p[i];
        }
        for (long long i=1;i<=n;i++)
        {
            cin>>d[i]>>v[i]>>a[i];
            if (v[i]>V)
            {
                sum++;
            }
        }
    }
    cout <<sum<<' '<<m-1;
    return 0;
}
