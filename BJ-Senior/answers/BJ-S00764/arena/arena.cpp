#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int t,n,m,a1[100010],c[100010],a[100010],dui[4];
vector<int>d[100010];

int div(int now,int l,int r)
{
    if(l == r)
    {
        return l;
    }
    int mid = (l+r)/2;
    int zuo = div(now-1,l,mid);
    int you = div(now-1,mid+1,r);
    if(d[now][l/(1<<now)]==0 && a[zuo] >= now) return zuo;
    else if(d[now][l/(1<<now)] && a[you] < now) return zuo;
    else return you;
}

int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i<=n;i++)
        scanf("%d",&a1[i]);
    for (int i = 1;i<=m;i++)
        scanf("%d",&c[i]);
    int k = log2(n*2-1);
    for (int i = 1;i<=k;i++)
        for (int j = 1;j<=1<<(k-i);j++)
        {
            int x;
            scanf("%1d",&x);
            d[i].push_back(x);
        }
    scanf("%d",&t);
    for (int i = 1;i<=t;i++)
    {
        long long ans = 0;
        int fir,sec,thi,fou;
        scanf("%d%d%d%d",&dui[0],&dui[1],&dui[2],&dui[3]);
        for (int j = 1;j<=n;j++)
            a[j] = a1[j]^dui[i%4];
        for (int j = 1;j<=m;j++)
            ans = ans^(j*div(k,1,c[i]));
        printf("%lld\n",ans);
    }
    return 0;
}
