#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long T,n,m,l,V,s,ans1,ans2;
long long d[100005],v[100005],a[100005],p[100005],x[100005],y[100005],c[100005];
bool flag=true,vis[100005];
double tmp;
bool dfs(long long cnt,long long x)
{
    if(cnt==0)
    {
        if(x==s)
            return true;
        return false;
    }
    for(int i=1;i<=m;++i)
        if(!vis[i])
        {
            vis[i]=true;
            dfs(cnt-1,x|c[i]);
            vis[i]=false;
        }
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&l,&V);
        ans1=s=0;
        ans2=n;
        flag=true;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld%lld%lld",&d[i],&v[i],&a[i]);
            v[i]=x[i]=y[i]=0;
            if(a[i]>0)
                flag=false;
        }
        for(int i=1;i<=m;++i)
        {
            scanf("%lld",&p[i]);
            vis[i]=false;
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                tmp=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i])+0.0);
                if(tmp>V)
                {
                    if(x[i]==0)
                        x[i]=j;
                    y[i]=j;
                    c[j] |= (1<<(i-1));
                    if(c[j]==(1<<n)-1)
                        ans2=n-1;
                }
            }
            if(x[i]>0)
            {
                ans1++;
                s |= (1<<(i-1));
            }
        }
        printf("%lld ",ans1);
        if(flag)
        {
            printf("%lld\n",n-1);
            continue;
        }
        for(ans2=1;ans2<=n;++ans2)
        {
            if(dfs(ans2,0))
                break;
        }
        printf("%lld\n",n-ans2);
    }
    return 0;
}