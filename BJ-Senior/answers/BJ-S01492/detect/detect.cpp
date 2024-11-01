#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long T,n,m,L,V,d[maxn],v[maxn],a[maxn],p[maxn],ans1,ans2;
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&T);
    for(int o=0;o<T;++o)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&L,&V);
        ans1=0;
        ans2=m-1;
        for(int i=1;i<=n;++i)
            scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
        for(int i=1;i<=m;++i)
            scanf("%lld",&p[i]);
        for(int i=1;i<=n;++i)
        {
            if(d[i]>p[m])
                continue;
            long long speed=v[i]*v[i];
            speed+=a[i]*(p[m]-d[i])*2;
            if(speed>V*V)
            {
                ++ans1;
            }
        }
        if(ans1==0)
            ans2=m;
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}
