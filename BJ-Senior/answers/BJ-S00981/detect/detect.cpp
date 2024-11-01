#include <bits/stdc++.h>

using namespace std;

long long t,n,m,l,v,loc[100005],ans1,ans2,ove[100005];
struct car
{
    long long d,v0,a;
}b[100005];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&t);
    for(int i=1;i<=t;i++)
    {
        ans1=ans2=0;
        memset(loc,0,sizeof(loc));
        memset(b,0,sizeof(b));
        scanf("%lld%lld%lld%lld",&n,&m,&l,&v);
        for(int j=1;j<=n;j++)scanf("%lld%lld%lld",&b[j].d,&b[j].v0,&b[j].a);
        for(int j=1;j<=m;j++)scanf("%lld",&loc[j]);
        sort(loc+1,loc+1+m);
        for(int j=1;j<=n;j++)
        {
            if(b[j].d<=loc[m])
            {
                long long ds=loc[m]-b[j].d;
                long long v2=b[j].v0*b[j].v0+2*b[j].a*ds;
                if(v2>v*v)ans1++;
            }
        }
        if(ans1)printf("%lld %d\n",ans1,m-1);
        else printf("%lld %d\n",ans1,m);
    }
    return 0;
}
