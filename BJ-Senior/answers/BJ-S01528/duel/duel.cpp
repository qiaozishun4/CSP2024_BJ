#include<bits/stdc++.h>
using namespace std;
long long n;
long long f[100005],g[100005];
long long maxn;
queue<long long> last;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++)
    {
        long long a;
        scanf("%lld",&a);
        f[a]++;
        g[a]++;
        maxn=max(maxn,a);
    }
    for(long long i=1;i<=maxn+4;i++)
    {
        if(f[i]&&!last.empty())
        {
            long long las=last.front();
            int xx=0;
            while(f[las]<=g[i]&&!last.empty())
            {
                g[i]-=f[las];
                f[las]=0;
                g[las]=0;
                last.pop();
                las=last.front();
                xx=1;
            }
            if(xx)last.push(i);
            if(g[las]>g[i])
            {
                f[las]-=f[i];
                g[i]=0;
                last.push(i);
            }

        }
        else if(f[i])
            last.push(i);
    }
    long long ans=0;
    while(!last.empty())
    {
        long long i=last.front();
        last.pop();
        ans+=f[i];
    }
    printf("%lld",ans);
    return 0;
}
