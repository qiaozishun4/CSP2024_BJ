#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int T,n,a[N];
int lst[N],nxt[N];
long long sum[N];
long long f[N];//f[i]:first i things,col[i] and col[i-1] is different,max value
long long g[N];//g[i]:first i things,the color beside col[i] is unimportant
void init()
{
    memset(lst,0x3f,sizeof(lst));
    for(int i=n;i>=1;i--)
    {
        nxt[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    nxt[0]=n+1;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(a[i]==a[i-1])*a[i];
    memset(f,-0x3f,sizeof(f));
    memset(g,-0x3f,sizeof(g));
}
int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        init();
        g[1]=0;
        for(int i=2;i<=n;i++) f[i]=sum[i-1];
        for(int i=1;i<=n;i++)
        {
            g[i]=max(g[i],f[i]);
            g[i+1]=max(g[i+1],g[i]+sum[i+1]-sum[i]);
            f[i+1]=max(f[i+1],g[i]);
            if(nxt[i-1]<=n) f[nxt[i-1]]=max(f[nxt[i-1]],f[i]+a[i-1]+sum[nxt[i-1]-1]-sum[i]);
        }
        printf("%lld\n",g[n]);
    }
}