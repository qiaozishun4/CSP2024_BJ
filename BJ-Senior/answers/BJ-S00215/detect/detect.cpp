#include<bits/stdc++.h>
using namespace std;
long long d[100010],v[100010],a[100010],p[100010];
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {       // 车数，测，长，限
        long long n,m,l,v1;
        cin>>n>>m>>l>>v1;
        for(long long i=1;i<=n;i++)
        {          //距，速，加
            cin>>d[i]>>v[i]>>a[i];
        }
        for(long long i=1;i<=m;i++) cin>>p[i];
        for(long long i=1;i<=n;i++)
        {
            double x=(v1*v1-v[i]*v[i])/(2*a)+d[i];
            if(a[i]>0)
            {
                
            }
        }
    }
    return 0;
}
