#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
int w[10]={6,2,5,5,4,5,6,3,7,6};
int f[N];
long long g[N];

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);

    scanf("%d",&T);
    while (T--)
    {
        memset(f,0,sizeof f);
        memset(g,0x7f,sizeof g);
        scanf("%d",&n);
        if (n%7==0)
        {
            while (n-=7)
            {
                printf("8");
            }
            printf("8\n");
            continue;
        }
        for (int i=1;i<10;i++)
        {
            f[w[i]]=1;
            g[w[i]]=min(g[w[i]],1LL*i);
        }
        for (int i=2;i<=n;i++)//num of sticks
        {
            for (int j=0;j<10;j++)//the number
            {
                if (i>=w[j])
                {
                    f[i]|=f[i-w[j]];
                    if (f[i-w[j]])
                    {
                        if (g[i-w[j]]==0) continue;
                        g[i]=min(g[i],g[i-w[j]]*10+1LL*j);
                    }
                }
            }
        }
        if (g[n]==0x7f7f7f7f7f7f7f7f) printf("-1\n");
        else printf("%lld\n",g[n]);
    }
    return 0;
}
