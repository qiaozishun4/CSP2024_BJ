#include<bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
int n,m,t,k,ax[N],a[N],c[N],T,x[10],w[20][N];
char r[2*N];
int dy(int p,int q)
{
    int res=q;
    for(int i=1;i<p;i++)
    {
        res+=(1<<(k-i));
    }
    return res;
}
signed main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&ax[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&c[i]);
    }
    int cw=1;
    while(cw<n)
    {
        cw*=2;
        k++;
    }
    scanf("\n");
    int crz=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=(1<<(k-i));j++)
        {
            scanf("%c",&r[++crz]);
        }
        scanf("\n");
    }
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&x[0],&x[1],&x[2],&x[3]);
        for(int i=1;i<=n;i++)
        {
            a[i]=ax[i]^x[(i%4)];
        }
        for(int j=1;j<=n;j++)
        {
            w[0][j]=j;
        }
        for(int j=1;j<=k;j++)
        {
            for(int z=1;z+(1<<j)-1<=n;z+=(1<<j))
            {
                int js=(z+(1<<j)-1)/((1<<j));
                if(r[dy(j,js)]=='0')
                {
                    if(a[w[j-1][z]]>=j)w[j][z]=w[j-1][z];
                    else w[j][z]=w[j-1][z+(1<<(j-1))];
                }
                else
                {
                    if(a[w[j-1][z+(1<<(j-1))]]>=j)w[j][z]=w[j-1][z+(1<<(j-1))];
                    else w[j][z]=w[j-1][z];
                }
            }
        }
        int res=0;
        for(int i=1;i<=m;i++)
        {
            t=0,cw=1;
            while(cw<c[i])
            {
                cw*=2;
                t++;
            }
            res^=(i*w[t][1]);
        }
        printf("%lld\n",res);
    }
    return 0;
}
